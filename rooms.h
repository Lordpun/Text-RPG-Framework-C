#ifndef ROOMS_H
#define ROOMS_H

struct ExitPair {
  char direction[50];
  char roomExit[50];
};

struct CommandPair {
  int num;
  char commandText[50];
};

struct Room {
  char roomNameId[50];
  char roomDesc[200];
  struct ExitPair exits[10];
  struct CommandPair commands[20];
};

extern struct Room roomList[100];

extern int roomCount;

extern char currentRoom[50];

void setupRooms();

struct Room findRoom(char roomName[50]);

#endif