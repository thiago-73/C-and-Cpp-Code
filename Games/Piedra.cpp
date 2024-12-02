/*
Rock, Paper, Scissors Game in C++

This program simulates the classic game of Rock, Paper, Scissors between the user and the computer.
Features:
1. Allows multiple rounds of gameplay.
2. Tracks and displays the score after each round.
3. Computer makes random choices using a random number generator.

Example Interaction:
Choose: 1 (Rock), 2 (Paper), 3 (Scissors): 1
Computer chose: Scissors
You win this round!
Scores - You: 1, Computer: 0
Play again? (y/n): y
Choose: 1 (Rock), 2 (Paper), 3 (Scissors): 2
Computer chose: Rock
You win this round!
Scores - You: 2, Computer: 0
Play again? (y/n): n
Final Scores - You: 2, Computer: 0
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to return the name of the choice
string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random number generator
    int userScore = 0, computerScore = 0; // Scores
    char playAgain;

    do {
        int userChoice, computerChoice;

        // Display options and get user input
        cout << "Choose: 1 (Rock), 2 (Paper), 3 (Scissors): ";
        cin >> userChoice;

        // Generate random choice for computer
        computerChoice = (rand() % 3) + 1;

        // Display choices
        cout << "Computer chose: " << getChoiceName(computerChoice) << "\n";

        // Determine winner
        if (userChoice == computerChoice) {
            cout << "It's a tie!\n";
        } else if ((userChoice == 1 && computerChoice == 3) ||
                (userChoice == 2 && computerChoice == 1) ||
                (userChoice == 3 && computerChoice == 2)) {
            cout << "You win this round!\n";
            userScore++;
        } else {
            cout << "Computer wins this round!\n";
            computerScore++;
        }

        // Display current scores
        cout << "Scores - You: " << userScore << ", Computer: " << computerScore << "\n";

        // Ask if the user wants to play again
        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // Continue if 'y' or 'Y' is entered

    // Final scores
    cout << "Final Scores - You: " << userScore << ", Computer: " << computerScore << "\n";
    cout << "Thanks for playing!\n";

    return 0;
}
