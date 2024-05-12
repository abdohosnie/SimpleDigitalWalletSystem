#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <string>
#include <queue>
#include "Transaction.h"

class TransactionManager {
public:
    static bool makeTransaction(const std::string& sender, const std::string& recipient, double amount, const std::string& type, std::queue<Transaction>& transactions);
    static void viewAllTransactions(std::queue<Transaction>& transactions);
};

#endif // TRANSACTION_MANAGER_H
