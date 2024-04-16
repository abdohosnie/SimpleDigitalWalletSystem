// transaction.cpp
#include "transaction.h"

Transaction::Transaction(const std::string& sender, const std::string& recipient, double amount, const std::string& type)
    : senderUsername(sender), recipientUsername(recipient), amount(amount), transactionType(type) {}
