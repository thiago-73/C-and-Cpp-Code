/*
ATM Simulator in C++

This program simulates a basic ATM (Automated Teller Machine) system where users can:
1. Deposit money into their account.
2. Withdraw money from their account (if sufficient funds are available).
3. Check their account balance.

The program uses a simple loop for navigation between options.

Example Interaction:
Welcome to the ATM Simulator!
1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit
Choose an option: 1
Enter the amount to deposit: 500
Deposit successful! Your new balance is: 500

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit
Choose an option: 2
Enter the amount to withdraw: 200
Withdrawal successful! Your new balance is: 300

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit
Choose an option: 3
Your current balance is: 300
Choose an option: 4
Thank you for using the ATM Simulator. Goodbye!
*/

#include <iostream>
using namespace std;

// Main function
int main() {
    double balance = 0.0; // Initial balance
    int option; // User-selected menu option

    cout << "Welcome to the ATM Simulator!\n";

    do {
        // Display menu
        cout << "\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit\nChoose an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                // Deposit money
                double depositAmount;
                cout << "Enter the amount to deposit: ";
                cin >> depositAmount;

                if (depositAmount > 0) {
                    balance += depositAmount;
                    cout << "Deposit successful! Your new balance is: " << balance << "\n";
                } else {
                    cout << "Invalid amount. Please enter a positive value.\n";
                }
                break;
            }

            case 2: {
                // Withdraw money
                double withdrawAmount;
                cout << "Enter the amount to withdraw: ";
                cin >> withdrawAmount;

                if (withdrawAmount > 0) {
                    if (withdrawAmount <= balance) {
                        balance -= withdrawAmount;
                        cout << "Withdrawal successful! Your new balance is: " << balance << "\n";
                    } else {
                        cout << "Insufficient funds. Your current balance is: " << balance << "\n";
                    }
                } else {
                    cout << "Invalid amount. Please enter a positive value.\n";
                }
                break;
            }

            case 3:
                // Check balance
                cout << "Your current balance is: " << balance << "\n";
                break;

            case 4:
                // Exit
                cout << "Thank you for using the ATM Simulator. Goodbye!\n";
                break;

            default:
                // Invalid option
                cout << "Invalid option. Please select a valid menu item.\n";
        }

    } while (option != 4); // Exit when the user chooses option 4

    return 0;
}
