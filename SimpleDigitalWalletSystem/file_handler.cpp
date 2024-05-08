#include "file_handler.h"
#include <fstream>

bool FileHandler::saveUserData(const std::vector<User>& users, const std::string& filename) {
  void saveUserData() {
    std::ofstream file("users.txt");
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.username << " " << user.password << " " << user.balance << std::endl;
        }
        file.close();
        std::cout << "User data saved successfully." << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}





};

bool FileHandler::loadUserData(std::vector<User>& users, const std::string& filename) {

void loadUserData() {
    std::ifstream file("users.txt");
    if (file.is_open()) {
        std::string username, password;
        double balance;
        while (file >> username >> password >> balance) {
            users.push_back({username, password, balance});
        }
        file.close();
        std::cout << "User data loaded successfully." << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
    }
}
};
