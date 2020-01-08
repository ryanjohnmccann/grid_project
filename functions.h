#ifndef functions_h
#define functions_h

#include <stdio.h>

#define NRows 21    // Dimensions for grid
#define NCols 51

// Reset grid to original settings
void resetGrid(char grid[][NCols]);

// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height);

// Print current grid contents
void printGrid(char grid[][NCols]);

#endif
