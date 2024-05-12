#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "AuthenticationManager.h"
#include "FileHandler.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include "User.h"
#include "UserManager.h"

using namespace std;

int main() {

    UserManager userManager;
    FileHandler fileHandler;
    unordered_map<string, User> userTable;

    string filename = "Database/userdata.txt";
    //string filename = "Database/transactionsdata.txt";

    bool loggedIn = false;

    if (fileHandler.loadUserData(filename, userTable)) {
        cout << "Data loaded successfully " << endl;
    }
    else {
        cerr << "Error: Failed to load user data." << endl;
    }

    string currentUser = "";
    
    while (true) {
        
        cout << "\nWelcome to User Management System" << endl;
        cout << "1. Register new user" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            // Register a new user
            string newUsername;
            string newPassword;
            double initialBalance;

            cout << "Enter username: ";
            cin >> newUsername;
            cout << "Enter password: ";
            cin >> newPassword;
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            // Register the new user
            if (userManager.registerUser(newUsername, newPassword, initialBalance, userTable, filename)) {
                cout << "User registered successfully." << endl;
            }
            else {
                cerr << "Failed to register user." << endl;
            }
            break;
        }
        case 2: {
            // Login
            string username;
            string password;

            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
        
            if (AuthenticationManager::loginUser(username, password,filename)) {
                loggedIn = true;
                currentUser = username;
                cout << "Login successful." << endl;
            }
            else {
                cout << "Invalid username or password." << endl;
            }
            break;
        }
        case 3: {
            // Exit
            return 0;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        while (loggedIn) {
            cout << "\nUser Menu" << endl;
            cout << "1. View Profile" << endl;
            cout << "2. Change Password" << endl;
            cout << "3. Send Money" << endl;
            cout << "4. Request Money" << endl;
            cout << "5. View Transactions" << endl;
            cout << "6. Logout" << endl;
            cout << "Enter your choice: ";

            int userChoice;
            cin >> userChoice;
            cin.ignore();

            switch (userChoice) {
            case 1:
                // View Profile
            {
                auto it = userTable.find(currentUser);
                if (it != userTable.end()) {
                    const User& user = it->second;

                    cout << "\n\tUser Profile" << endl;
                    cout << "\tUsername: " << user.getUsername() << endl;
                    cout << "\tBalance: " << user.getBalance() << endl;
                    cout << "\tAccount Status: " << (user.getIsSuspended() ? "Suspended" : "Active") << endl;
                }
                else {
                    cerr << "Error: Current user not found." << endl;
                }
            }
                break;
            case 2:
                // Change Password
            {
                // Get the current user from the userTable
                auto it = userTable.find(currentUser);
                if (it != userTable.end()) {
                    string currentPassword, newPassword;
                    cout << "Enter current password: ";
                    cin >> currentPassword;
                    cout << "Enter new password: ";
                    cin >> newPassword;

                    userManager.editUserProfile(currentUser, currentPassword, newPassword, userTable, filename);
                }
            }
                break;
            case 3:
                // Send Money
            {
                string recipient;
                double amount;
                cout << "Enter recipient username: ";
                cin >> recipient;
                cout << "Enter amount to send: ";
                cin >> amount;

                auto senderIt = userTable.find(currentUser);
                if (senderIt != userTable.end()) {
                    User& sender = senderIt->second;
                    if (sender.sendMoney(recipient, amount, userTable)) {
                        cout << "Money sent successfully.\n";
                    }
                    else {
                        cout << "Failed to send money.\n";
                    }
                }
                else {
                    cout << "Error: Sender not found.\n";
                }

            }
                break;
            case 4:
                // Request Money
                
                break;
            case 5:
            {
                auto it = userTable.find(currentUser);
                if (it != userTable.end()) {
                    const User& user = it->second;

                    cout << "\n\t(---{ Transaction History }---)\n";
                    auto transactions = user.getTransactionHistory();

                    while (!transactions.empty()) {
                        Transaction transaction = transactions.front();
                        transactions.pop();

                        cout << "\tSender: " << transaction.getSenderUsername() << endl;
                        cout << "\tRecipient: " << transaction.getRecipientUsername() << endl;
                        cout << "\tAmount: " << transaction.getAmount() << endl;
                        cout << "\tType: " << transaction.getTransactionType() << endl;
                        cout << "\t--------------------------\n";
                    }
                }
                else {
                    cerr << "Error: Current user not found." << endl;
                }
            }
            break;
            case 6:
                // Logout
                loggedIn = false;
                cout << "Logged out successfully." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}