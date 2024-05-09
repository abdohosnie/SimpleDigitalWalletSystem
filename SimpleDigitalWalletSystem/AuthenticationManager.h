#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include <fstream>
#include <sstream>
#include "User.h"

class AuthenticationManager {
public:
    static bool loginUser(const std::string& username, const std::string& password, const std::string& filename);
};

#endif // AUTHENTICATIONMANAGER_H
