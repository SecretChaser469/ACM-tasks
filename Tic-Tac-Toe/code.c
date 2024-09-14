#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_board(char board[]);
int check_win(char board[]);
int is_board_full(char board[]);
void player_move(char board[]);
void computer_move(char board[]);
void welcome_message();
void print_divider();
void thank_you_message();

int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int result = 0;
    char play_again;

    welcome_message();  // Display the welcome message

    do {
        // Reset the board for a new game
        for (int i = 0; i < 9; i++) board[i] = '1' + i;

        display_board(board);

        // Main game loop
        while (1) {
            player_move(board);          // Player's turn
            display_board(board);

            result = check_win(board);   // Check if player wins
            if (result != 0) break;

            if (is_board_full(board)) {  // Check for draw
                printf("It's a draw! No one wins.\n");
                break;
            }

            computer_move(board);        // Computer's turn
            display_board(board);

            result = check_win(board);   // Check if computer wins
            if (result != 0) break;

            if (is_board_full(board)) {  // Check for draw
                printf("It's a draw! No one wins.\n");
                break;
            }
        }

        // Display the final result
        if (result == 1) {
            printf("\n🎉 Congratulations! You win! 🎉\n");
        } else if (result == -1) {
            printf("\n😔 Computer wins! Better luck next time! 😔\n");
        }

        // Ask if the user wants to play again
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);

        print_divider();  // Add a nice divider for separation

    } while (play_again == 'y' || play_again == 'Y');

    thank_you_message();  // Display a thank-you message

    return 0;
}

// Function to display the current Tic-Tac-Toe board
void display_board(char board[]) {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n\n");
}

// Function to check the win conditions
int check_win(char board[]) {
    int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
        {0, 4, 8}, {2, 4, 6}              // diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[win_conditions[i][0]] == board[win_conditions[i][1]] &&
            board[win_conditions[i][1]] == board[win_conditions[i][2]]) {
            if (board[win_conditions[i][0]] == 'X') return 1;  // Player wins
            if (board[win_conditions[i][0]] == 'O') return -1; // Computer wins
        }
    }

    return 0; // No winner yet
}

// Function to check if the board is full (i.e., a draw)
int is_board_full(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return 0;
    }
    return 1;
}

// Function to handle the player's move
void player_move(char board[]) {
    int move;
    while (1) {
        printf("Your turn! Enter your move (1-9): ");
        scanf("%d", &move);
        move--; // Convert 1-9 to 0-8 for array indexing

        // Check for invalid input
        if (move < 0 || move > 8 || board[move] == 'X' || board[move] == 'O') {
            printf("⚠️ Invalid move. Please try again!\n");
        } else {
            board[move] = 'X';
            break;
        }
    }
}

// Function to handle the computer's move (random)
void computer_move(char board[]) {
    int move;
    srand(time(0)); // Seed for random number generation

    while (1) {
        move = rand() % 9; // Random number between 0-8

        // Check if the move is valid
        if (board[move] != 'X' && board[move] != 'O') {
            board[move] = 'O';
            printf("\nComputer chose position %d\n", move + 1);
            break;
        }
    }
}

// Function to display the welcome message
void welcome_message() {
    printf("============================================\n");
    printf("  🎮 Welcome to the Ultimate Tic-Tac-Toe! 🎮  \n");
    printf("============================================\n");
    printf("You are 'X' and the computer is 'O'.\n");
    printf("Get ready to challenge the computer!\n\n");
}

// Function to print a decorative divider
void print_divider() {
    printf("============================================\n");
}

// Function to display a thank you message at the end
void thank_you_message() {
    printf("\n============================================\n");
    printf("  🙏 Thank you for playing Tic-Tac-Toe! 🙏  \n");
    printf("============================================\n");
    printf("Have a great day!\n");
}
