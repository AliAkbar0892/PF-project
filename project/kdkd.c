#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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

    // Set the endpoint (E) at the bottom-right corner
    endpointX = w - 2;
    endpointY = h - 2;
}

// Function to display the maze
void displayMaze() {
    int w = width[currentLevel - 1]; // Get width for current level
    int h = height[currentLevel - 1]; // Get height for current level

    // Display the maze
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == playerX && j == playerY) {
                printf("P "); // Player position
            } else if (i == endpointX && j == endpointY) {
                printf("E "); // Endpoint position
            } else if (maze[i][j] == 1) {
                printf("# "); // Wall
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }
}

// Function to clear the console
void clearScreen() {
    system("cls"); 
}

// Function to move the player based on input
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
    setMaze(); // Set the maze for current level

    printf("Level %d Maze:\n", currentLevel);

    // Game loop
    char input;
    while (1) {
        clearScreen(); // Clear the screen
        displayMaze(); // Show the current maze

        // Check for game-over condition (exit is at (width-2, height-2))
        int w = width[currentLevel - 1];
        int h = height[currentLevel - 1];
        if (playerX == endpointX && playerY == endpointY) {
            printf("Congratulations! You've completed level %d!\n", currentLevel);
            break;
        }

        printf("Use W, A, S, D to move. Press 'q' to quit.\n");

        // Read the player's input immediately
        input = _getch(); 

        if (input == 'q' || input == 'Q') {
            printf("You quit the game.\n");
            break;
        }

        movePlayer(input); // Move player based on input
    }

    return 0;
}
