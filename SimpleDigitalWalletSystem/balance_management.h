#include <string>
#include <vector>
#include "user.h"

class BalanceManagement {
public:
    // Function to view user balance
    static double viewBalance(const std::string& username, const std::vector<User>& users);

    // Function to send money from one user to another
    static bool sendMoney(const std::string& sender, const std::string& recipient, double amount, std::vector<User>& users);

    // Function to request money from another user
    static bool requestMoney(const std::string& sender, const std::string& recipient, double amount, std::vector<User>& users);
};