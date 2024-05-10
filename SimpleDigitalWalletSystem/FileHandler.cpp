#include "FileHandler.h"
#include <iostream>
#include <sstream>

bool FileHandler::saveUserData(const std::string& filename, const std::unordered_map<std::string, User>& userTable) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return false;
    }

    for (const auto& entry : userTable) {
        const User& user = entry.second;
        outFile << user.getUsername() << " " << user.getPassword() << " " << user.getBalance()
            << " " << user.getIsAdmin() << " " << user.getIsSuspended() << "\n";
    }

    outFile.close();
    std::cout << "User data saved successfully." << std::endl;
    return true;
}

bool FileHandler::loadUserData(const std::string& filename, std::unordered_map<std::string, User>& userTable) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading." << std::endl;
        return false;
    }

    userTable.clear();

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string username;
        std::string password;
        double balance;
        bool isAdmin = false;
        bool isSuspended = false;
        ss >> username >> password >> balance >> isAdmin >> isSuspended;
        userTable[username] = User(username, password, balance);
        userTable[username].setIsAdmin(isAdmin);
        userTable[username].setIsSuspended(isSuspended);
    }

    inFile.close();
    std::cout << "User data loaded successfully." << std::endl;
    return true;
}


//bool saveTransactions(const std::string& filename, const std::queue<Transaction>& transactions) {
//
//    return true;
//}
//
//bool loadTransactions(const std::string& filename, std::queue<Transaction>& transactions) {
//
//    return true;
//}
