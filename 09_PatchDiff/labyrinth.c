#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int main(int argc, char **argv) {
    const char wallChar = '#', spaceChar = '.';
    const int size = 6;

    srand(time(NULL));

    bool **points = malloc((2*size+1) * sizeof(bool *));

    for (int y = 0; y <= 2*size; y++) {
        points[y] = malloc((2*size+1) * sizeof(bool));
        for (int x = 0; x <= 2*size; x++) {
            points[y][x] = false;
        }
    }

    int x = rand() % size;
    int y = rand() % size;
    points[2*y+1][2*x+1] = true;  // false = wall, true = space

    for (int countSeen = 1; countSeen < size * size;) {
        int sides[4] = {0,0,0,0};
        int countWalls = 0;

        if (x > 0 && !points[2*y+1][2*x-1]) {
            sides[countWalls] = LEFT;
            countWalls++;
        }

        if (x < size-1 && !points[2*y+1][2*x+3]) {
            sides[countWalls] = RIGHT;
            countWalls++;
        }

        if (y > 0 && !points[2*y-1][2*x+1]) {
            sides[countWalls] = UP;
            countWalls++;
        }

        if (y < size-1 && !points[2*y+3][2*x+1]) {
            sides[countWalls] = DOWN;
            countWalls++;
        }
        
        if (countWalls == 0) {
            do {
                x = rand() % size;
                y = rand() % size;
            } while (!points[2*y+1][2*x+1]);
            continue;
        }

        switch (sides[rand()%countWalls]) {
            case LEFT:
                points[2*y+1][2*x] = true;
                points[2*y+1][2*x-1] = true;
                x--;
                break;
            case RIGHT:
                points[2*y+1][2*x+2] = true;
                points[2*y+1][2*x+3] = true;
                x++;
                break;
            case UP:
                points[2*y][2*x+1] = true;
                points[2*y-1][2*x+1] = true;
                y--;
                break;
            case DOWN:
                points[2*y+2][2*x+1] = true;
                points[2*y+3][2*x+1] = true;
                y++;
                break;
        }
                
        countSeen++;
    }

    for (y = 0; y <= 2*size; y++) {
        for (x = 0; x <= 2*size; x++) {
            if (points[y][x]) {
                printf("%c", spaceChar);
            } else {
                printf("%c", wallChar);
            }
        }
        printf("\n");
        free(points[y]);
    }

    free(points);

    return 0;
}
