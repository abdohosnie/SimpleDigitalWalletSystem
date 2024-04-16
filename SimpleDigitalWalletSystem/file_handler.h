#include <string>
#include "user.h"

class FileHandler {
public:
	static bool saveUserData(const vector<User>& users, const string& filename);
	static bool loadUserData(vector<User>& users, const string& filename);
};