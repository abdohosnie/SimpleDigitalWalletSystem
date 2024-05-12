#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
#include "TransactionManager.h"

class User {
private:
    std::string username;
    std::string password;
    double balance;
    bool isAdmin = false;
    bool isSuspended = false;
    std::queue<Transaction> transactionHistory;

public:
    User() : username(""), password(""), balance(0.0), isAdmin(false), isSuspended(false) {}
    User(const std::string& username, const std::string& password, double initialBalance, bool isAdmin = false, bool isSuspended = false);

    bool getIsAdmin() const;
    bool getIsSuspended() const;
    std::string getUsername() const;
    std::string getPassword() const;
    double getBalance() const;
    std::queue<Transaction> getTransactionHistory() const;
    void setBalance(double newBalance);
    void setPassword(const std::string& newPassword);
    void setIsSuspended(bool suspended);
    void setIsAdmin(bool admin);

    bool authenticate(const std::string& passwordInput) const;
    bool sendMoney(const std::string& recipient, double amount, std::unordered_map<std::string, User>& users);
    bool requestMoney(const std::string& sender, double amount, std::unordered_map<std::string, User>& users);
    void updateBalance(double amount, const std::string& transactionType);
    void addToTransactionHistory(const Transaction& transaction);

    // Admin Functions
    static void viewAllUsers(const std::unordered_map<std::string, User>& users);
    static bool editUser(const std::string& username, double newBalance, std::unordered_map<std::string, User>& users);
    static bool deleteUser(const std::string& username, std::unordered_map<std::string, User>& users);
    static bool suspendUser(const std::string& username, std::unordered_map<std::string, User>& users);
    static bool adminUpdateBalance(const std::string& username, double newBalance, std::unordered_map<std::string, User>& users);
};

#endif // USER_H
