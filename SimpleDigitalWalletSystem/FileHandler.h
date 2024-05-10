#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <fstream>
#include <unordered_map>
#include "User.h"

class FileHandler {
public:
    static bool saveUserData(const std::string& filename, const std::unordered_map<std::string, User>& userTable);
    static bool loadUserData(const std::string& filename, std::unordered_map<std::string, User>& userTable);

    //static bool saveTransactions(const std::string& filename, const std::queue<Transaction>& transactions);
    //static bool loadTransactions(const std::string& filename, std::queue<Transaction>& transactions);

};

#endif // FILE_HANDLER_H