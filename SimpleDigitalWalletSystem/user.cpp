#include "user.h"

using namespace std;

User::User(const string& username, const string& password, double initialBalance)
    : username(username), password(password), balance(initialBalance) {}

string User::getUsername() const {
    return username;
}

double User::getBalance() const {
    return balance;
}

vector<Transaction> User::getTransactionHistory() const {
    return transactionHistory;
}

bool User::authenticate(const string& passwordInput) const {
    // Compare input password with stored password (hashed)
    // Implement your authentication logic here
}

bool User::sendMoney(const string& recipient, double amount) {
    // Implement logic to send money to another user
}

bool User::requestMoney(const string& sender, double amount) {
    // Implement logic to request money from another user
}

void User::updateBalance(double amount, const string& transactionType) {
    // Update user's balance based on transaction type (e.g., "sent", "received")
}

void User::addToTransactionHistory(const Transaction& transaction) {
    // Add a transaction to the user's transaction history
}
