#include <stdio.h>
#include <conio.h>   // For _getch() and _kbhit()
#include <windows.h> // For Sleep() and system("cls")

#define WIDTH 10
#define HEIGHT 8

// Define multiple mazes (levels)
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

// Player's position
int playerX = 1, playerY = 1;
int currentLevel = 1;  // Start at level 1

// Function to display the maze
void displayMaze(int maze[HEIGHT][WIDTH]) {
    system("cls");  // Clear the console

  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == playerX && j == playerY) {
                printf("P "); // Player position
            } else if (maze[i][j] == 1) {
                printf("# "); // Wall
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }

}

// Function to handle player movement
void movePlayer(char direction, int maze[HEIGHT][WIDTH]) {
    // Calculate the new position based on the direction
    int newX = playerX, newY = playerY;

    if (direction == 'w') newY--;  // Move up
    if (direction == 's') newY++;  // Move down
    if (direction == 'a') newX--;  // Move left
    if (direction == 'd') newX++;  // Move right

    // Check if the new position is within bounds and not a wall
    if (maze[newY][newX] == 0) {
        playerX = newX;
        playerY = newY;
    }
}

// Function to switch between levels
void switchLevel() {
    if (currentLevel == 1) {
        playerX = 1; playerY = 1;  // Reset player position for the next level
        currentLevel = 2;
    } else if (currentLevel == 2) {
        printf("Congratulations! You've completed all levels!\n");
        exit(0);  // Exit the game after the last level
    }
}

int main() {
    char input;

    while (1) {
        // Display the current level maze
        if (currentLevel == 1) {
            displayMaze(maze1);
        } else if (currentLevel == 2) {
            displayMaze(maze2);
        }

        // Check if the player has reached the goal
        if ((currentLevel == 1 && playerX == WIDTH - 2 && playerY == HEIGHT - 2) ||
            (currentLevel == 2 && playerX == WIDTH - 2 && playerY == HEIGHT - 2)) {
            switchLevel();  // Move to the next level or end game
        }

        // Wait for the player's input
        input = _getch();  // Get the key input (W, A, S, D)
        if (currentLevel == 1) {
            movePlayer(input, maze1);  // Move the player in level 1 maze
        } else if (currentLevel == 2) {
            movePlayer(input, maze2);  // Move the player in level 2 maze
        }

        Sleep(100);  // Delay for smoother movement
    }

    return 0;
}
