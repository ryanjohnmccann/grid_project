#include <stdio.h>
#include <string.h>
#include "functions.h"

int main() {
    /* myGrid defined as how large our grid will be for the user to print boxes
     on in the x and y axis. userCommand defined as which command the user
     would like to */
    char myGrid[NRows][NCols], userCommand[50];
    /* xStartCord defined as where the user wishes to begin the box in the x direction.
    the same goes for yStartCord but for the y direction. Width being how wide the user
     would like to make the box, and height being how tall the user would like the box to be.*/
    int xStartCord, yStartCord, width, height;
    // Initialize grid to clear state
    resetGrid( myGrid );
    // Loop to run until user enters the "exit" command
    printf("If you forget or are confused about what to do please type 'Help'\n");
    do {
        printf("Enter command: ");
        scanf("%s", userCommand);
        // Executes for print command.
        if ((strncmp(userCommand, "print", 50) == 0) || (strncmp(userCommand, "Print", 50) == 0)) {
            printGrid(myGrid);
        }
        // Executes for add command.
        else if ((strncmp(userCommand, "add", 50) == 0) || (strncmp(userCommand, "Add", 50) == 0)) {
            printf("Enter x and y coordinates for origin: ");
            scanf("%d %d", &xStartCord, &yStartCord);
            printf("Enter width and height: ");
            scanf("%d %d", &width, &height);
            addBox(myGrid, xStartCord, yStartCord, width, height);
        }
        // Executes for reset command.
        else if ((strncmp(userCommand, "reset", 50) == 0) || (strncmp(userCommand, "reset", 50) == 0)) {
            resetGrid(myGrid);
        }
        // Explains how the program functions.
        else if ((strncmp(userCommand, "help", 50) == 0) || (strncmp(userCommand, "Help", 50) == 0)) {
            printf("COMMANDS\n\n");
            printf("Print: Prints the grid\n\n");
            printf("Add: Allows you to add a box to the grid\n\n");
            printf("Reset: Resets all boxes on the grid\n\n");
            printf("Exit: Exits the program\n\n");
        }
        // Handles error checking for userCommand input.
        else {
            if ((strncmp ( userCommand, "exit", 50 ) != 0) && (strncmp(userCommand, "Exit", 50) != 0)) {
                printf("Invalid command --> %s\n", userCommand);
            }
        }
    } while ((strncmp(userCommand, "exit", 50) != 0) && (strncmp(userCommand, "Exit", 50) != 0));
}


