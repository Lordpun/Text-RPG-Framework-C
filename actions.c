#include "actions.h"
#include "rooms.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *testAction(int action) {
  struct Room room = findRoom(currentRoom);

  int actionInList = 0;
  char command[50];
  for (int i = 0; i < sizeof(room.commands) / sizeof(room.commands[0]); i++) {
    if (room.commands[i].num == action) {
      actionInList = 1;
      strcpy(command, room.commands[i].commandText);
      break;
    }
  }
  if (actionInList == 0) {
    return "The action entered is not in the list of valid commands";
  }

  struct Words words = splitCommand(command);

  if (strcmp(words.string[0], "Move") == 0) {
    moveCommandCase(words, room);
  } else {
    return "There isn't a case for this command, something went wrong on the dev's part.";
  }
  
  return "no error";
};

struct Words splitCommand(char command[50]) {
  struct Words words;
  char* word = strtok(command, " ");
  strcpy(words.string[0], word);

  if (word != NULL) {
    word = strtok(NULL, " ");
    strcpy(words.string[1], word);
  }
  
  return words;
}

// Below are functions for the different commands
void moveCommandCase(struct Words words, struct Room room) {
  char direction[50]; 
  strcpy(direction, words.string[1]);

  for (int i = 0; i < sizeof(room.exits) / sizeof(room.exits[0]); i++) {
    if (strcmp(room.exits[i].direction, direction) == 0) {
      strcpy(currentRoom, room.exits[i].roomExit);

      displayRoom();
    }
  }
}