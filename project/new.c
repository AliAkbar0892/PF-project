#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

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

void printMaze() {
    int w = width[currentLevel - 1];
    int h = height[currentLevel - 1];
    system("cls");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == playerX && j == playerY)
                printf("P "); 
            else if (i == endpointX && j == endpointY)
                printf("E "); 
            else if (maze[i][j] == 1)
                printf("# "); 
            else
                printf(". "); 
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    int w = width[currentLevel - 1];
    int h = height[currentLevel - 1];

    if (direction == 'w' && playerX > 0 && maze[playerX - 1][playerY] != 1) {
        playerX--; 
    } else if (direction == 's' && playerX < h - 1 && maze[playerX + 1][playerY] != 1) {
        playerX++; 
    } else if (direction == 'a' && playerY > 0 && maze[playerX][playerY - 1] != 1) {
        playerY--; 
    } else if (direction == 'd' && playerY < w - 1 && maze[playerX][playerY + 1] != 1) {
        playerY++; 
    }

    
    if (playerX == endpointX && playerY == endpointY) {
        printf("\nCongratulations! You've completed level %d.\n", currentLevel);
        currentLevel++;
        if (currentLevel > MAX_LEVELS) {
            printf("You have completed all levels!\n");
            exit(0); 
        }
        playerX = 1;
        playerY = 1;
        setMaze();
    }
}

int main() {
    
    setMaze();
    char direction;

    printf("Welcome to the maze game!\n");

    while (1) {
        printMaze();
        if (kbhit()) {
            direction = getch();
            movePlayer(direction);
        }
    }

    return 0;
}
