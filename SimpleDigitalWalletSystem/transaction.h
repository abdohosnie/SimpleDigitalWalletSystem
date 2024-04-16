#include <string>

using namespace std;

struct Transaction {
	string senderUsername;
	string recipientUsername;
	double amount;
	string transactionType;

	Transaction(const string& sender, const string& recipient, double amount, const string& type);
};