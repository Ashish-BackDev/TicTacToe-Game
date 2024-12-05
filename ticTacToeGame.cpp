#include <iostream>
#include <limits> // For std::numeric_limits
using namespace std;

// Array representing the Tic Tac Toe board (positions 1-9)
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

// Function prototypes
int checkwin();     // Function to check the game status
void board();       // Function to draw the current game board
void resetBoard();  // Function to reset the board for a new round

int main()
{
    int player = 1, i, choice;   // player holds 1 or 2 for Player 1 and Player 2
    char mark, playAgain;         // mark is 'X' or 'O' based on the player, playAgain is used for restarting the game

     // Prompt user to press Ente0sd;ljvbkfzksldf{"vbm'r to start the game
     cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout << "\t \t \t \t Welcome to Tic Tac Toe!" << endl;
    cout<<  "\tKey Concepts:"<<endl;
    cout<<  "1) Game Loop: Players take turns entering a number between 1 and 9.The program updates the board after\n   each move and checks for a win  or draw."<<endl;
    cout<<  "2) Board Display: The board() function updates the board after every move to show the current state of the game."<<endl;
    cout<<  "3) Input Validation: The program ensures only valid numbers are entered, and rejects any invalid input."<<endl;
    cout<<  "4) Game Outcome: The checkwin() function checks the status of the game to determine if there’s a winner or a draw."<<endl;
    cout<<  "5) Replay Option: After a game ends, the program asks if players want to play again.\n "<<endl;
    cout << "Press Enter when you are ready to start the game...";
    cin.ignore(); // Wait for the user to press Enter

    do
    {
        resetBoard(); // Reset the board before starting each round

        // Game loop where the players take turns
        do
        {
            board(); // Display the current board
            player = (player % 2) ? 1 : 2; // Alternate between Player 1 and Player 2
            cout << "Player " << player << ", enter a number:  ";

            // Input validation: ensure the user enters a number between 1 and 9
            while (!(cin >> choice) || choice < 1 || choice > 9)
            {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a number between 1 and 9: ";
            }

            mark = (player == 1) ? 'X' : 'O'; // Assign 'X' to Player 1, 'O' to Player 2

            // Check if the selected cell is unoccupied, and place the player's mark if valid
            if (choice == 1 && square[1] == '1') 
                square[1] = mark;
            else if (choice == 2 && square[2] == '2') 
                square[2] = mark;
            else if (choice == 3 && square[3] == '3') 
                square[3] = mark;
            else if (choice == 4 && square[4] == '4') 
                square[4] = mark;
            else if (choice == 5 && square[5] == '5') 
                square[5] = mark;
            else if (choice == 6 && square[6] == '6') 
                square[6] = mark;
            else if (choice == 7 && square[7] == '7') 
                square[7] = mark;
            else if (choice == 8 && square[8] == '8') 
                square[8] = mark;
            else if (choice == 9 && square[9] == '9') 
                square[9] = mark;
            else
            {
                // If the cell is already occupied or the input is invalid, prompt the user again
                cout << "Invalid move ";
                player--; // Decrement the player counter to give the player another turn
                cin.ignore(); // Ignore the extra input
                cin.get();    // Wait for user to press enter
            }

            i = checkwin(); // Check if the game is over (win or draw)
            player++; // Switch to the other player

        } while (i == -1); // Continue the loop if the game is still in progress

        board(); // Display the final board after the game ends

        // Display the result of the game (win or draw)
        if (i == 1)
            cout << "==>\aPlayer " << --player << " wins!" << endl;
        else
            cout << "==>\aGame draw" << endl;

        // Ask players if they want to play again
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain == 'Y' || playAgain == 'y') {
            player = 1; // Reset player to 1 for the next round
        }

    } while (playAgain == 'Y' || playAgain == 'y'); // Repeat the game if the players choose to play again

    return 0; // Exit the program
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    0 GAME IS OVER AND NO RESULT
*********************************************/ 

int checkwin()
{
    // Check rows for a win
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    // Check columns for a win
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    // Check diagonals for a win
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    // Check for a draw (no free spots left on the board)
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0; // Draw

    // If no winner yet, the game is still in progress
    else
        return -1;
}

/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void board()
{
    system("cls"); // Clear the console screen
    cout << "\n\n\tTic Tac Toe\n\n"; // Display game title
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl; // Show player roles
    cout << endl;
    
    // Print the current state of the Tic Tac Toe board
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}

/*******************************************************************
     FUNCTION TO RESET THE BOARD FOR NEXT ROUND
********************************************************************/

void resetBoard()
{
    // Reset the board to the initial state (numbers 1-9 for each cell)
    for (int i = 1; i <= 9; i++) {
        square[i] = '0' + i; // Set each cell to its corresponding number (1 to 9)
    }
}
