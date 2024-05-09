#include "Transaction.h"

Transaction::Transaction(const std::string& sender, const std::string& recipient, double amount, const std::string& type)
    : senderUsername(sender), recipientUsername(recipient), amount(amount), transactionType(type) {}

std::string Transaction::getSenderUsername() const {
    return senderUsername;
}

std::string Transaction::getRecipientUsername() const {
    return recipientUsername;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTransactionType() const {
    return transactionType;
}
