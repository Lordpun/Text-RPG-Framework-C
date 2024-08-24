#ifndef ACTIONS_H
#define ACTIONS_H

#include "rooms.h"

// Supports at minium two words and a null char
struct Words {
  char string[3][50];
};

char* testAction(int num);

struct Words splitCommand(char command[50]);

void moveCommandCase(struct Words words, struct Room room);

#endif