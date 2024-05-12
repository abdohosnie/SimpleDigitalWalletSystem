#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>
#include <unordered_map>
#include "User.h"

class UserManager {
public:
    bool registerUser(const std::string& username, const std::string& password, double initialBalance, std::unordered_map<std::string, User>& userTable, const std::string& filename);
    bool editUserProfile(const std::string& username, const std::string& currentPassword, const std::string& newPassword, std::unordered_map<std::string, User>& userTable, const std::string& filename);
    bool resetPassword(const std::string& username, const std::string& newPassword, std::unordered_map<std::string, User>& userTable, const std::string& filename);
};

#endif // USER_MANAGER_H
