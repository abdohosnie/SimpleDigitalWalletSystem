#include "User.h"
#include <iostream>
using namespace std;

bool AdminFunctionalities::adminLogin(const string& username, const string& password) {
   
    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;
    
    if (username == "admin" && password == "password") {
      return true;
    }
   else {
       cout << "Incorrect username or password.\n";
      return false;
   }


}

void AdminFunctionalities::viewAllUsers(const vector<User>& users) {
    
    cout << "Registered Users:\n";
    for (const auto& user : users) {
        cout << "Username: " << user.username << ", Balance: " << user.initialBalance << ", Suspended: " << (user.suspended ? "Yes" : "No") << endl;
    }
}

bool AdminFunctionalities::addUser(const string& username, const string& password, double initialBalance, vector<User>& users) {
   
    for (const auto& user : users) {
        if (user.username == username) {
            cout << "Username already exists. Please choose another username.\n";
            return false;
        }
    }

    User newUser;
    newUser.username = username;
    newUser.password = password;
    newUser.balance = initialBalance;
    users.push_back(newUser);

    cout << "User account created successfully.\n";
    return true;
}

bool AdminFunctionalities::editUser(const string& username, double newBalance, vector<User>& users) {
    
    for (auto& user : users) {
        if (user.username == username) {
            user.initialBalance = newBalance;
            cout << "User account details updated successfully.\n";
            return true;
        }
    }
    cout << "User not found.\n";
    return false;
}

bool AdminFunctionalities::deleteUser(const string& username, vector<User>& users) {
    
    for (auto it = users.begin(); it != users.end(); ++it) {
        
        if (it -> username == username) {
            users.erase(it);
            cout << "User account deleted successfully.\n";
            return true;
        }
    }
    cout << "User not found.\n";
    return false;
}

bool AdminFunctionalities::suspendUser(const string& username, vector<User>& users) {
    
    for (auto& user : users) {
        if (user.username == username) {
            user.suspended = true;
            cout << "User account suspended successfully.\n";
            return true;
        }   
    }
    cout << "User not found.\n";
    return false;
}

void AdminFunctionalities::viewAllTransactions(const vector<User>& users) {
    
    cout << "All Transactions:\n";
    for (const auto& user : users) {
        cout << "User: " << user.username << endl;
        user.wallet.viewTransactions();
        cout << endl;
    }
}


