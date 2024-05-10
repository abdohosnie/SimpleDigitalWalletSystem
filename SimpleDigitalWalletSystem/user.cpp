#include "User.h"
#include <iostream>
#include "FileHandler.h"

User::User(const std::string& username, const std::string& password, double initialBalance, bool isAdmin, bool isSuspended)
    : username(username), password(password), balance(initialBalance), isAdmin(isAdmin), isSuspended(isSuspended) {}


bool User::getIsAdmin() const {
    return isAdmin;
}

bool User::getIsSuspended() const {
    return isSuspended;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

double User::getBalance() const {
    return balance;
}

std::queue<Transaction> User::getTransactionHistory() const {
    return transactionHistory;
}

void User::setBalance(double newBalance) {
    balance = newBalance;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

void User::setIsSuspended(bool suspended) {
    isSuspended = suspended;
}

void User::setIsAdmin(bool admin)
{
    isAdmin = admin;
}

bool User::authenticate(const std::string& passwordInput) const {
    return passwordInput == password;
}

bool User::sendMoney(const std::string& recipient, double amount, std::unordered_map<std::string, User>& users) {
    if (balance >= amount) {
        balance -= amount;

        auto it = users.find(recipient);
        if (it != users.end()) {
            it->second.updateBalance(amount, "Received");
            Transaction sentTransaction(username, recipient, amount, "Sent");
            addToTransactionHistory(sentTransaction);
            Transaction receivedTransaction(username, recipient, amount, "Received");
            it->second.addToTransactionHistory(receivedTransaction);
            return true;
        }
        else {
            std::cout << "Recipient not found.\n";
            balance += amount; // Rollback the balance change
            return false;
        }
    }
    else {
        std::cout << "Not enough funds to complete the transaction." << std::endl;
        return false;
    }
}

bool User::requestMoney(const std::string& sender, double amount, std::unordered_map<std::string, User>& users) {
    auto it = users.find(sender);
    if (it != users.end()) {
        if (it->second.getBalance() >= amount) {
            it->second.updateBalance(-amount, "Requested");
            updateBalance(amount, "Received");
            Transaction sentTransaction(sender, username, amount, "Requested");
            it->second.addToTransactionHistory(sentTransaction);
            Transaction receivedTransaction(sender, username, amount, "Received");
            addToTransactionHistory(receivedTransaction);
            return true;
        }
        else {
            std::cout << "Sender does not have enough funds to fulfill the request." << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Sender not found." << std::endl;
        return false;
    }
}

void User::updateBalance(double amount, const std::string& transactionType) {
    if (transactionType == "Deposit") {
        balance += amount;
        Transaction depositTransaction(username, "Self", amount, "Deposit");
        addToTransactionHistory(depositTransaction);
    }
    else if (transactionType == "Withdrawal") {
        if (balance >= amount) {
            balance -= amount;
            Transaction withdrawalTransaction(username, "Self", amount, "Withdrawal");
            addToTransactionHistory(withdrawalTransaction);
        }
        else {
            std::cout << "Not enough funds. Withdrawal failed." << std::endl;
        }
    }
    else {
        std::cout << "Invalid transaction type." << std::endl;
    }
}

void User::addToTransactionHistory(const Transaction& transaction) {
    transactionHistory.push(transaction);
}

void User::viewAllUsers(const std::unordered_map<std::string, User>& users) {
    std::cout << "Registered Users:\n";
    for (const auto& pair : users) {
        std::cout << "Username: " << pair.first << ", Balance: " << pair.second.getBalance() << ", Suspended: " << (pair.second.getIsSuspended() ? "Yes" : "No") << std::endl;
    }
}

bool User::editUser(const std::string& username, double newBalance, std::unordered_map<std::string, User>& users) {
    auto it = users.find(username);
    if (it != users.end()) {
        it->second.setBalance(newBalance);
        std::cout << "User account details updated successfully.\n";
        return true;
    }
    else {
        std::cout << "User not found.\n";
        return false;
    }
}

bool User::deleteUser(const std::string& username, std::unordered_map<std::string, User>& users) {
    auto it = users.find(username);
    if (it != users.end()) {
        users.erase(it);
        std::cout << "User account deleted successfully.\n";
        return true;
    }
    else {
        std::cout << "User not found.\n";
        return false;
    }
}

bool User::suspendUser(const std::string& username, std::unordered_map<std::string, User>& users) {
    auto it = users.find(username);
    if (it != users.end()) {
        it->second.setIsSuspended(true);
        FileHandler::saveUserData("userdata.txt", users);
        std::cout << "User account suspended successfully.\n";
        return true;
    }
    else {
        std::cout << "User not found.\n";
        return false;
    }
}


//void User::viewAllTransactions(const std::unordered_map<std::string, User>& users) {
//    std::cout << "All Transactions:\n";
//    for (const auto& pair : users) {
//        std::cout << "User: " << pair.first << std::endl;  // pair.first is the username
//        const auto& transactions = pair.second.getTransactionHistory();
//        while (!transactions.empty()) {
//            const auto& transaction = transactions.front();
//            std::cout << "Sender: " << transaction.getSenderUsername() << ", Recipient: " << transaction.getRecipientUsername()
//                << ", Amount: " << transaction.getAmount() << ", Type: " << transaction.getTransactionType() << std::endl;
//            transactions.pop();
//        }
//    }
//}