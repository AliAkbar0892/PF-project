#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVELS 5
int currentLevel = 1;

int width[] = {10, 12, 14, 16, 18}; 
int height[] = {10, 12, 14, 16, 18}; 

int maze10x10[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze12x12[12][12] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze14x14[14][14] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}
};

int playerX = 1, playerY = 1; 
int endpointX = 0, endpointY = 0; 

int maze[18][18];  

void setMaze() {
    int w = width[currentLevel - 1];
    int h = height[currentLevel - 1];

    if (currentLevel == 1) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                maze[i][j] = maze10x10[i][j];
            }
        }
    } else if (currentLevel == 2) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                maze[i][j] = maze12x12[i][j];
            }
        }
    } else if (currentLevel == 3) {
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 14; j++) {
                maze[i][j] = maze14x14[i][j];
            }
        }
    }

    endpointX = w - 2;
    endpointY = h - 2;
}

void displayMaze() {
    int w = width[currentLevel - 1]; 
    int h = height[currentLevel - 1]; 


    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            } else if (i == endpointX && j == endpointY) {
                printf("E ");
            } else if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf(". "); 
            }
        }
        printf("\n");
    }
}

void clearScreen() {
    system("cls"); 
}

void movePlayer(char input) {
    if (input == 'w' || input == 'W') { // Move up
        if (maze[playerX - 1][playerY] == 0) playerX--;
    } else if (input == 's' || input == 'S') { // Move down
        if (maze[playerX + 1][playerY] == 0) playerX++;
    } else if (input == 'a' || input == 'A') { // Move left
        if (maze[playerX][playerY - 1] == 0) playerY--;
    } else if (input == 'd' || input == 'D') { // Move right
        if (maze[playerX][playerY + 1] == 0) playerY++;
    }
}

int main() {
    setMaze();

    printf("Level %d Maze:\n", currentLevel);

    char input;
    while (1) {
        clearScreen(); 
        displayMaze();

        int w = width[currentLevel - 1];
        int h = height[currentLevel - 1];
        if (playerX == endpointX && playerY == endpointY) {
            printf("Congratulations! You've completed level %d!\n", currentLevel);
            break;
        }

        printf("Use W, A, S, D to move. Press 'q' to quit.\n");

        input = _getch(); 

        if (input == 'q' || input == 'Q') {
            printf("You quit the game.\n");
            break;
        }

        movePlayer(input); 
    }

    return 0;
}
