#include "User.h"
#include "TransactionManager.h"

class BalanceManager {
public:
    static void updateBalance(User& user, double amount, const std::string& transactionType);
    static bool adminUpdateBalance(const std::string& username, double newBalance, std::vector<User>& users);
};