#include "rooms.h"
#include "actions.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearConsole() {
  system("clear");
}

void displayRoom() {
  clearConsole();
  struct Room room = findRoom(currentRoom);

  printf("%s\n", room.roomDesc);
  printf(GREEN "\nCOMMANDS:\n");
  for (int i = 0; i < sizeof(room.commands) / sizeof(room.commands[0]); i++) {
    if (room.commands[i].num != 0) { printf("\n%d: %s", room.commands[i].num, room.commands[i].commandText); }
  }
  printf(RESET "\n");
}