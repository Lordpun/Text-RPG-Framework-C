#include "rooms.h"
#include "actions.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Important variables / Global variables
char currentRoom[50] = "TestRoom1";
int run = 1;
// Used to define what state the game is in, example; 0 is for exploring rooms, 1 is combat, 2 is npc interactions, and 3 is shops
int gamestate = 0;

int main(void) {
  setupRooms();

  printf(BLUE "C TEXT RPG FRAMEWORK" RESET "\n\nPress enter to begin.\n");
  getchar();

  displayRoom();
    
  // Main gameloop
  while (run == 1) {
    // Main state, room exploration
    if (gamestate == 0) {
      printf("\n" PURPLE "Enter a command:\n" RESET);
      int action;
      char test;
      if(scanf("%d%c", &action, &test) != 2 || test != '\n') {
        printf(RED "Please enter a number corresponding to the commands listed.\n" RESET);
        // Remove this line ↓ and enter a non int, and watch the program freak out.
        // It's quite funny
        while ((test = getchar()) != '\n' && test != EOF);
      } else {
        char* result = testAction(action);
        if (strcmp(result, "no error") != 0) {
          printf(RED "%s", result);
        }
      }
    } else {
      printf(RED "Invalid gamestate" RESET);
    }
  }
  
  return 0;
}