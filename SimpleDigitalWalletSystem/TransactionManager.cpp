#include "TransactionManager.h"
#include <iostream>

bool TransactionManager::makeTransaction(const std::string& sender, const std::string& recipient, double amount, const std::string& type, std::queue<Transaction>& transactions) {
    Transaction newTransaction(sender, recipient, amount, type);
    transactions.push(newTransaction);
    std::cout << "Transaction successful.\n";
    return true;
}

void TransactionManager::viewAllTransactions(std::queue<Transaction>& transactions) {
    std::cout << "All Transactions:\n";
    while (!transactions.empty()) {
        Transaction transaction = transactions.front();
        std::cout << "Sender: " << transaction.getSenderUsername() << ", Recipient: " << transaction.getRecipientUsername()
            << ", Amount: " << transaction.getAmount() << ", Type: " << transaction.getTransactionType() << std::endl;
        transactions.pop();
    }
}
