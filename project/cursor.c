#include <stdio.h>
#include <conio.h>   
#include <windows.h> 

#define WIDTH 10
#define HEIGHT 8


int maze1[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze2[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


int playerX = 1, playerY = 1;
int currentLevel = 1; 

void displayMaze(int maze[HEIGHT][WIDTH]) {
    system("cls");  // Clear screen

  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            } else if (maze[i][j] == 1) {
                printf("# "); 
            } else {
                printf(". "); 
            }
        }
        printf("\n");
    }

}

void movePlayer(char direction, int maze[HEIGHT][WIDTH]) {
    int newX = playerX, newY = playerY;

    if (direction == 'w') newY--;  // Move
    if (direction == 's') newY++;  
    if (direction == 'a') newX--;  
    if (direction == 'd') newX++;  

    if (maze[newY][newX] == 0) {
        playerX = newX;
        playerY = newY;
    }
}

void switchLevel() {
    if (currentLevel == 1) {
        playerX = 1; playerY = 1;
        currentLevel = 2;
    } else if (currentLevel == 2) {
        printf("Congratulations! You've completed all levels!\n");
        exit(0);
    }
}

int main() {
    char input;

    while (1) {
       
        if (currentLevel == 1) {
            displayMaze(maze1);
        } else if (currentLevel == 2) {
            displayMaze(maze2);
        }

        if ((currentLevel == 1 && playerX == WIDTH - 2 && playerY == HEIGHT - 2) ||
            (currentLevel == 2 && playerX == WIDTH - 2 && playerY == HEIGHT - 2)) {
            switchLevel(); 
        }

        input = _getch();  
        if (currentLevel == 1) {
            movePlayer(input, maze1);  
        } else if (currentLevel == 2) {
            movePlayer(input, maze2); 
        }

        Sleep(100);
    }

    return 0;
}
