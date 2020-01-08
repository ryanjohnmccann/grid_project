#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

// Reset grid to original settings
void resetGrid(char grid[][NCols]) {
    // i and j defined to execute our for loops accordingly.
    int i, j;
    // Loop that handles updating our grid array values with plus and minuses properly.
    for (i = 20; i >= 0;  i -= 5) {
        for (j = 0; j <= 50; j++) {
            if (j % 5 == 0)
                grid[i][j] = '+';
            else
                grid [i][j] = '-';
        }
    }
    // Loop that handles updating our grid array values with bars and spaces properly.
    for (i = 19; i >= 1; i--) {
        if (i % 5 > 0) {
            for (j = 0; j <= 50; j++) {
                if (j % 5 == 0)
                    grid[i][j] = '|';
                else
                    grid[i][j] = ' ';
            }
        }
    }
}
// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height) {
    // p and r defined to execute our for loops accordingly.
    int p, r;
    /* Loop to update all mygrid array values to a star with respect to how
     large the user would like the box to be. */
    for (p = 20 - y ; p > ( 20 - y ) - height; p--) {
        for (r = x; r < ( x + width ); r++) {
             // Only updates array if it is within our specified grid.
            if (r >= 0 && r <= 50 && p >= 0 && p <= 20)
                grid[p][r] = '*';
        }
    }
}

// Print current grid contents
void printGrid(char grid[][NCols]) {
    /* k and m defined to execute our for loops accordingly, n defined to properly print the
    users box from bottom to top, since our array prints from top to bottom we don't want the box to print
    opposite to where it should be. */
    int k, m, n;
    n = 20;
    // for loop and nested for loop to go through every array and to print it.
    for (k = 0; k < 21; k++) {
        for (m = 0; m < 51; m++) {
            printf("%c", grid[k][m]);
        }
        // to print all of our y axis grid labels.
        if (n % 5 == 0) {
            if (n == 0 || n == 5)
                printf(" %d", n);
            else
                printf("%d", n);
        }
        n-= 1;
        printf("\n");
    }
    k = 0;
    // Loop to print all of our x axis grid labels.
    do {
        printf("%d", k);
        if (k < 10)
            printf("    ");
        else
            printf("   ");
        k += 5;
    } while (k <= 50);
    printf("\n");
    
}
