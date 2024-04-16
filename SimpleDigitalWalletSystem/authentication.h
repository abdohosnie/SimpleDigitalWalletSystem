#include <string>
#include <vector>
#include "user.h"

using namespace std;

class Authentication {
public:

	static bool authenticateUser(const string& username, const string& password, const vector<User>& users);
};