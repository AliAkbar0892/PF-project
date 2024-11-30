#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For kbhit() and getch()

#define MAX_LEVELS 5
int currentLevel = 1;

// Maze dimensions for each level
int width[] = {10, 12, 14, 16, 18};
int height[] = {10, 12, 14, 16, 18};

// Fixed mazes for each level (10x10, 12x12, 14x14, etc.)
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

// Player's starting position (always starts at 1, 1)
int playerX = 1, playerY = 1;
int endpointX = 0, endpointY = 0; // Position of endpoint (E)

// The active maze array
int maze[18][18];  // The max size of any maze (18x18)

// Function to assign the maze for the current level
void setMaze() {
    int w = width[currentLevel - 1]; // Get width for current level
    int h = height[currentLevel - 1]; // Get height for current level

    // Set the maze based on the current level
    if (currentLevel == 1) {
        // Copy maze10x10 to the active maze
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                maze[i][j] = maze10x10[i][j];
            }
        }
    } else if (currentLevel == 2) {
        // Copy maze12x12 to the active maze
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                maze[i][j] = maze12x12[i][j];
            }
        }
    } else if (currentLevel == 3) {
        // Copy maze14x14 to the active maze
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 14; j++) {
                maze[i][j] = maze14x14[i][j];
            }
        }
    }
    // Set endpoint at the bottom-right corner
    endpointX = w - 2;
    endpointY = h - 2;
}

void printMaze() {
    int w = width[currentLevel - 1];
    int h = height[currentLevel - 1];
    system("cls"); // Clear the console for every new frame

    // Print the maze
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == playerX && j == playerY)
                printf("P "); // P for player
            else if (i == endpointX && j == endpointY)
                printf("E "); // E for endpoint
            else if (maze[i][j] == 1)
                printf("# "); // Wall
            else
                printf(". "); // Open space
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    int w = width[currentLevel - 1];
    int h = height[currentLevel - 1];

    if (direction == 'w' && playerX > 0 && maze[playerX - 1][playerY] != 1) {
        playerX--; // Move up
    } else if (direction == 's' && playerX < h - 1 && maze[playerX + 1][playerY] != 1) {
        playerX++; // Move down
    } else if (direction == 'a' && playerY > 0 && maze[playerX][playerY - 1] != 1) {
        playerY--; // Move left
    } else if (direction == 'd' && playerY < w - 1 && maze[playerX][playerY + 1] != 1) {
        playerY++; // Move right
    }

    // Check if player reached the endpoint
    if (playerX == endpointX && playerY == endpointY) {
        printf("\nCongratulations! You've completed level %d.\n", currentLevel);
        currentLevel++;
        if (currentLevel > MAX_LEVELS) {
            printf("You have completed all levels!\n");
            exit(0); // Exit the game
        }
        playerX = 1;
        playerY = 1;
        setMaze();
    }
}

int main() {
    // Initialize the game
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
