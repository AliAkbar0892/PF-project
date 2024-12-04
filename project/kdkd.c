#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVELS 5
int currentLevel = 1;
int Tscores = 0;
int Highscores = 0;
char play;   // to store the charcter.

// Mazes for each level
int width[] = {10, 12, 14, 16, 18}; 
int height[] = {10, 12, 14, 16, 18}; 

// Fixes Mazes
int maze10[10][10] = {            
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 8, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},   //Level 1
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1},    
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze12[12][12] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1},      // Level 2
    {1, 8, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze14[14][14] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},         //Level 3
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 8, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}
};

int maze16[16][16]={
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 8, 0, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},   // Level 4
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int maze18[18][18] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},     //Level 5
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Player's starting position 
int playerX = 1, playerY = 1; 
int endpointX = 0, endpointY = 0; // Ending position

// Array to store current maze. 
int maze[18][18];  

int scores(int n, int totalscores){
    char line[100];
    if(Tscores > Highscores){
        Highscores = Tscores;
        printf("You broke the High Scores");
    }
    if(n == 1 ){
        FILE * ptr = fopens("scores.txt", "r");
        if (ptr == NULL) {
            printf("Error opening file!\n");
            return 1; 
        }
        while (fgets(line, sizeof(line), ptr)) {
            if (strstr(line, "High Score")) { // Check if the line contains "High Score"
                sscanf(line, "High Score: %d", &Highscores); // Extracting high score 
                printf("High Scores: %d",Highscores);
                break; 
            }
        }        
    }
    if(n == 2){
        FILE * file = fopen("scores.txt", "a");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }        
        fprintf(file, "High Scores: %d\nYour Total Score: %d",Highscores,Tscores);
    }
}

// Function to load the maze of current level in array maze. 
void setMaze() {
    int w = width[currentLevel - 1]; // width for current level
    int h = height[currentLevel - 1]; //  height for current level

    
    if (currentLevel == 1) {    // Copying maze
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                maze[i][j] = maze10[i][j];
            }
        }
    } else if (currentLevel == 2) {   
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                maze[i][j] = maze12[i][j];
            }
        }
    } else if (currentLevel == 3) {
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 14; j++) {
                maze[i][j] = maze14[i][j];
            }
        }
    }
    else if (currentLevel == 4) {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                maze[i][j] = maze16[i][j];
            }
        }
    } else if (currentLevel == 5) {
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 18; j++) {
                maze[i][j] = maze18[i][j];
            }
        }
    }

    // Seting endpoint of the maze
    endpointX = w - 2;
    endpointY = h - 2;
}

// Function to display the maze
void displayMaze() {
    int w = width[currentLevel - 1]; //  getting width 
    int h = height[currentLevel - 1]; // getting height

    // Display the maze
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == playerX && j == playerY) {
                printf("%c ",play); // Player position
            } else if (i == endpointX && j == endpointY) {
                printf("E "); // Endpoint position
            } else if (maze[i][j] == 1) {
                printf("# "); // Wall
            } else if (maze[i][j] == 8) {
                printf("* "); // collectible
            } else printf(". "); // empty space    
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
        if (maze[playerX - 1][playerY] == 0 || maze[playerX - 1][playerY] == 8) { 
            playerX--;
            if (maze[playerX][playerY] == 8) maze[playerX][playerY] == 0; // colectible's place
            }
    } else if (input == 's' || input == 'S') { // Move down
        if (maze[playerX + 1][playerY] == 0 || maze[playerX + 1][playerY] == 8) {
            playerX++;
            if(maze[playerX][playerY] == 8) maze[playerX][playerY] == 0;
            }
    } else if (input == 'a' || input == 'A') { // Move left
        if (maze[playerX][playerY - 1] == 0 || maze[playerX][playerY - 1] == 8) {
            playerY--;
            if(maze[playerX][playerY] == 8) maze[playerX][playerY] == 0;
            }
    } else if (input == 'd' || input == 'D') { // Move right
        if (maze[playerX][playerY + 1] == 0 || maze[playerX][playerY + 1] == 8) {
            playerY++;
            if(maze[playerX][playerY] == 8) maze[playerX][playerY] == 0;
            }
    }
    setMaze();
}

int MainMenu() {              // Displaying main menu
    printf("=====================================\n");
    printf("            MAZE ADVENTURE           \n");
    printf("=====================================\n");
    printf("Welcome to the Maze Game!\n\n");
    printf("1. Start Game\n");
    printf("2. Instructions\n");
    printf("3. High Scores\n");
    printf("4. Exit\n");
    printf("5. Credits\n\n");
    printf("Enter your choice: ");

}


int main() {
    time_t startTime, currentTime; //for time
    double timeLimit = 10.0;
    double elapsedTime = 0.0;
    while(1){
        MainMenu();
        int option;  // to store choice
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter character you want to control: \n");
                scanf("%c", &play);
                printf("\nStarting the game...\n");
                startTime = time(NULL);
                break;
            case 2:
                printf("\nInstructions\n");
                printf("=> Navigate through the maze to reach the exit.\n");
                printf("=> Use W, A, S, D keys to move up, left, down, and right respectively.\n");
                printf("=> Avoid walls and find the shortest path to win!\n\n");
                printf("\nScores\n");
                printf("You will get 10 scores for every second you saved to complete the level.\n");
                printf("If you collect ( * ) in the game you will get a bonus of 5 scores.\n");
                printf("Remember! there is a time limit of 10 seconds to complete the game\n");
                continue;
            case 3:
                scores( 1, Tscores);
                continue;
            case 4:
                printf("\nExiting the game. Goodbye!\n");
                return 0;
            case 5: 
                printf("Ali Akbar\t\t24k-0892\nArslan Rashid\t\t24k-0776\n");
                continue;    
            default:
                printf("\nInvalid choice. Please try again.\n");
                continue;
        }

        setMaze(); // Set the maze for current level

        char input;
        while (1) {
            clearScreen(); // Calling function to clear the screen
            printf("Current Level: %d \n",currentLevel);
            displayMaze(); // Show the current maze
            // Checking for game-over condition i.e. when player is at end point.
            int w = width[currentLevel - 1];
            int h = height[currentLevel - 1];
            if (playerX == endpointX && playerY == endpointY) {
                if(elapsedTime == 1) Tscores = 10;          // scores for the time saved
                else if (elapsedTime ==2) Tscores +=20;
                else if (elapsedTime ==3) Tscores +=30;
                else if (elapsedTime ==4) Tscores +=40;
                else if (elapsedTime ==5) Tscores +=50;
                else if (elapsedTime ==6) Tscores +=60;
                else if (elapsedTime ==7) Tscores +=70;
                else if (elapsedTime ==8) Tscores +=80;
                else if (elapsedTime ==9) Tscores +=90;
                printf("Congratulations! You've completed level %d! \n Total Score : %d\nPress any key to continue...\n", currentLevel,Tscores);
                scores(2, Tscores);
                currentLevel++;
                playerX=1; playerY=1;
                if(currentLevel>5){       //Game complete
                    printf("Congratulations!!!\nYOU HAVE FINISHED THE GAME. TOTAL SCORE:  %d \n press any key yo continue...",Tscores);
                    _getch();
                    break;
                }
                _getch();
            }

           if (currentLevel == 1 && playerX ==5 && playerY == 3) {        // colectables scores
                Tscores += 15; 
            } else if (currentLevel == 2 && playerX == 7 && playerY == 1) {
                Tscores += 15;
            } else if (currentLevel == 3 && playerX == 11 && playerY == 8) {
                Tscores += 15;
            }else if (currentLevel == 4 && playerX == 1 && playerY == 9) {
                Tscores += 15;
            } else if (currentLevel == 5 && playerX == 16 && playerY == 6) {
                Tscores += 15;
            } 

            printf("Use W, A, S, D to move. Press 'q' to quit ingame.\n\n");
            printf("Your score: %d\n",Tscores);
            printf("Remaining Time: %.0f seconds\n", timeLimit - elapsedTime);

            // Read the player's input
            input = _getch();

            currentTime = time(NULL);
            elapsedTime = difftime (currentTime , startTime); 

            if(elapsedTime > timeLimit){   // End game when time's out
                printf("\nTime's Up!!!\n");
                break;
            }
            if (input == 'q' || input == 'Q') {
                printf("You quit the game.\n");
                break;
            }
            movePlayer(input); // function to move player
        }

    }

    return 0;
}
