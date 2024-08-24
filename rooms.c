#include "rooms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Room roomList[100];
int roomCount;

// Put this at the top of your main function in your main file
void setupRooms() {
  // If you plan on adding in rooms, just add on the info to the end of an array
  char roomNames[][50] = {"TestRoom1", "TestRoom2"};
  char roomDescs[][200] = {"It's a empty room, a room of emptiness, quite an emtpy room I must say! EMPTIER THAN EMPTY!", "Cool room, if you found this you are a cool something."};
  // Adding on to these two arrays, when adding in a new room, the second inner array ({ { this array } }) is the room.
  // Add on a pair with a third array with the format {{{int number, char command[20]}}}
  // If you add a three word command, unless you modify some code in actions.c, it will just return the first two.
  // Warning; ONE WORD CRASHES IT!
  struct CommandPair roomCommands[][20] = {{{1, "Move forwards"}}, {{1, "Move backwards"}}};
  struct ExitPair roomExits[][10] = {{{"forwards", "TestRoom2"}}, {{"backwards", "TestRoom1"}}};
  roomCount = sizeof(roomNames) / sizeof(roomNames[0]);

  struct Room room;
  for (int i = 0; i < roomCount; i++) {
    // 100 is the set room limit, but you can increase it by modifiying the number in the defintion of roomList in this file and in rooms.h
    if (i > 100) {
      printf("Too many rooms, exceeded set array ammount.");
      return;
    }
    
    strcpy(room.roomNameId, roomNames[i]);
    strcpy(room.roomDesc, roomDescs[i]);
    for (int j = 0; j < sizeof(roomCommands[i]) / sizeof(roomCommands[i][0]); j++) {
      room.commands[j] = roomCommands[i][j];
    }
    for (int j = 0; j < sizeof(roomExits[i]) / sizeof(roomExits[i][0]); j++) {
      room.exits[j] = roomExits[i][j];
    }
    
    roomList[i] = room;
  }
}

// To be used with a room string variable, it takes in a string and outputs a room based on the first instant of the string in roomList[index].roomNameId
struct Room findRoom(char roomName[50]) {
  struct Room room;

  for (int i = 0; i < roomCount; i++) {
    if (strcmp(roomList[i].roomNameId, roomName) == 0) {
      return roomList[i];
    }
  }

  return room;
}