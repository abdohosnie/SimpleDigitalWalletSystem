#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "AuthenticationManager.h"
#include "BalanceManager.h"
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

    vector<User> users;
    bool loggedIn = false;

    if (fileHandler.loadUserData(filename, userTable)) {
        std::cout << "Data loaded successfully " << endl;
    }
    else {
        std::cerr << "Error: Failed to load user data." << std::endl;
    }

    std::string currentUser = "";
    
    while (true) {
        
        cout << "Welcome to User Management System" << endl;
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
            std::string newUsername;
            std::string newPassword;
            double initialBalance;

            std::cout << "Enter username: ";
            std::cin >> newUsername;
            std::cout << "Enter password: ";
            std::cin >> newPassword;
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;

            // Register the new user
            if (userManager.registerUser(newUsername, newPassword, initialBalance, userTable, filename)) {
                std::cout << "User registered successfully." << std::endl;
            }
            else {
                std::cerr << "Failed to register user." << std::endl;
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
            cout << "2. Edit Profile" << endl;
            cout << "3. Change Password" << endl;
            cout << "4. Send Money" << endl;
            cout << "5. Request Money" << endl;
            cout << "6. View Transactions" << endl;
            cout << "7. Logout" << endl;
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
                    std::cout << "Username: " << user.getUsername() << std::endl;
                    std::cout << "Balance: " << user.getBalance() << std::endl;
                    std::cout << "Account Status: " << (user.getIsSuspended() ? "Suspended" : "Active") << std::endl;
                }
                else {
                    std::cerr << "Error: Current user not found." << std::endl;
                }
            }
                break;
            case 2:
                // Edit Profile
                
                break;
            case 3:
                // Change Password
                
                break;
            case 4:
                // Send Money
                
                break;
            case 5:
                // Request Money
                
                break;
            case 6:
                // View Transactions
                
                break;
            case 7:
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