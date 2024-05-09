#include <fstream>
#include <sstream>
#include <iostream>
#include "User.h"
#include "AuthenticationManager.h"

bool AuthenticationManager::loginUser(const std::string& username, const std::string& password, const std::string& filename) {
    std::ifstream inFile(filename);

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string storedUsername;
        std::string storedPassword;
        ss >> storedUsername >> storedPassword;

        if (username == storedUsername && password == storedPassword) {
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}
