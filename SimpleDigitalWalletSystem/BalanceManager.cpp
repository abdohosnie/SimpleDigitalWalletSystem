#include "BalanceManager.h"
#include <iostream>

void BalanceManager::updateBalance(User& user, double amount, const std::string& transactionType) {
    double currentBalance = user.getBalance();

    if (transactionType == "Deposit") {
        user.updateBalance(currentBalance + amount, transactionType);
    }
    else if (transactionType == "Withdraw")
    {
        if (currentBalance >= amount)
        {
            user.updateBalance(currentBalance - amount, transactionType);
        }
        else
        {
            std::cout << "Your balance is low.\n";
        }
    }
    else
    {
        std::cout << "Invalid transaction type.\n";
    }
}

bool BalanceManager::adminUpdateBalance(const std::string& username, double newBalance, std::vector<User>& users) {
    for (auto& user : users) {
        if (user.getUsername() == username) {
            user.updateBalance(newBalance, "Admin Update");
            return true;
        }
    }
    return false;
}
