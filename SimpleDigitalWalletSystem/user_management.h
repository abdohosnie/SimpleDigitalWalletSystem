#include <string>
#include <vector>
#include "user.h"

class UserManagement {
public:
    // Function to register a new user
    static bool registerUser(const std::string& username, const std::string& password, double initialBalance, std::vector<User>& users);

    // Function to edit user profile (e.g., change password)
    static bool editUserProfile(const std::string& username, const std::string& newPassword, std::vector<User>& users);

    // Function to reset user password
    static bool resetPassword(const std::string& username, const std::string& newPassword, std::vector<User>& users);
};