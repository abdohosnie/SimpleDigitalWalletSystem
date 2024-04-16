#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class User {
private:
	string username;
	string password;
	double balance;
	vector<Transaction> transactionHistory;

public:
	User(const string& username, const string& password, double initialBalance);

	string getUsername() const;
	double getBalance() const;
	vector<Transaction> getTransactionHistory() const;

	bool authenticate(const string& passwordInput) const;
	bool sendMoney(const string& recipient, double amount);
	bool requestMoney(const string& sender, double amount);
	void updateBalance(double amount, const string& transactionType);
	void addToTransactionHistory(const Transaction& transaction);

};