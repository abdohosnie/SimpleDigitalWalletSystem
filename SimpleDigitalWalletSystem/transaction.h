#pragma once
#include <string>

class Transaction {
private:
    std::string senderUsername;
    std::string recipientUsername;
    double amount;
    std::string transactionType;

public:
    Transaction(const std::string& sender, const std::string& recipient, double amount, const std::string& type);

    std::string getSenderUsername() const;
    std::string getRecipientUsername() const;
    double getAmount() const;
    std::string getTransactionType() const;
};