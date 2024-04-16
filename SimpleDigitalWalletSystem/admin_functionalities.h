#include <string>
#include <vector>
#include "user.h"

class AdminFunctionalities {
public:
    // Function for admin login
    static bool adminLogin(const std::string& username, const std::string& password);

    // Function to view list of all registered users
    static void viewAllUsers(const std::vector<User>& users);

    // Function to add a new user account
    static bool addUser(const std::string& username, const std::string& password, double initialBalance, std::vector<User>& users);

    // Function to edit user account details
    static bool editUser(const std::string& username, double newBalance, std::vector<User>& users);

    // Function to delete a user account
    static bool deleteUser(const std::string& username, std::vector<User>& users);

    // Function to suspend a user account
    static bool suspendUser(const std::string& username, std::vector<User>& users);

    // Function to view all transactions
    static void viewAllTransactions(const std::vector<User>& users);
};