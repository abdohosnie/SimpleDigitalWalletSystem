#include "UserManager.h"
#include "FileHandler.h"
#include <iostream>

bool UserManager::registerUser(const std::string& username, const std::string& password, double initialBalance, std::unordered_map<std::string, User>& userTable, const std::string& filename) {
    if (userTable.find(username) != userTable.end()) {
        std::cout << "Username already exists." << std::endl;
        return false;
    }

    User newUser(username, password, initialBalance);
    userTable[username] = newUser;

    FileHandler fileHandler;
    if (!fileHandler.saveUserData(filename, userTable)) {
        std::cerr << "Error saving user data after registration." << std::endl;
        return false;
    }

    return true;
}

bool UserManager::editUserProfile(const std::string& username, const std::string& currentPassword, const std::string& newPassword, std::unordered_map<std::string, User>& userTable) {
    auto it = userTable.find(username);
    if (it != userTable.end()) {
        if (it->second.getPassword() == currentPassword) {
            it->second.setPassword(newPassword);
            std::cout << "Password updated successfully." << std::endl;
            return true;
        }
        else {
            std::cout << "Failed, Wrong Password." << std::endl;
            return false;
        }
    }

    std::cout << "User not found." << std::endl;
    return false;
}

bool UserManager::resetPassword(const std::string& username, const std::string& newPassword, std::unordered_map<std::string, User>& userTable) {
    auto it = userTable.find(username);
    if (it != userTable.end()) {
        it->second.setPassword(newPassword);
        std::cout << "Password reset successfully." << std::endl;
        return true;
    }

    std::cout << "User not found." << std::endl;
    return false;
}