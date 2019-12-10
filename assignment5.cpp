#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;
class Account{
public:
	Account(string, double, string);
	void deposit(double amount);
	double withdraw();
	string toString() const;
protected:
	string ID;
	double balance;
	double interestRate;
	string openDate;
};
Account::Account(string id, double rate, string date)
{
	ID = id; balance = 0.0; interestRate = rate; openDate = date;
}
void Account::deposit(double amount)
{
	balance += amount;
}
double Account::withdraw()
{
	return 0.0;
}
string Account::toString() const
{
	return " ";
}
/////////////////////////////////////////////////
class checkAccount: public Account{
public:
	checkAccount(string = "", double = 0.003, string = "2020-01-01", double = 0.0);
	void deposit(double amount);
	double withdraw();
	string toString() const;
private:
	double overdraft;
};
checkAccount::checkAccount(string id, double rate, string date, double limit) :Account(id, rate, date), overdraft(limit)
{}
void checkAccount::deposit(double amount)
{
	Account::deposit(amount);
}
double checkAccount::withdraw()
{
	cout << "your balance is " << balance << endl;
	cout << "you allow to overdraft about" << overdraft << endl;
	cout << "Enter amount ";
	double amount;
	cin >> amount;
	if (amount > balance +overdraft)
		return 0.0;
	else
	{
		if (amount > balance)
		{
			overdraft -= amount - balance; balance = 0.0; 
		}
		else
			balance -= amount;
		return amount;
	}
}
string checkAccount::toString() const
{
	ostringstream stream;
	stream << balance;       // a double value converts a string 
	return ID + ";balance:" + stream.str();
}
//////////////////////////////////////////////////////////////////
class saveAccount : public Account{
public:
	saveAccount(string = "", double = 0.025, string = "2020-01-01");
	void deposit(double amount);
	double withdraw();
	string toString() const;
};
saveAccount::saveAccount(string id, double rate, string date) :Account(id, rate, date)
{}
void saveAccount::deposit(double amount)
{
	Account::deposit(amount);
}
double saveAccount::withdraw()
{
	balance += balance*interestRate;
	cout << "your balance is " << balance << endl;
	cout << "Enter amount ";
	double amount;
	cin >> amount;
	if (amount > balance)
		return  0.0; 
	else
	{
		balance -= amount; 	return amount;
	}
}
string saveAccount::toString() const
{
	ostringstream stream;
	stream << balance;       // a double value converts a string 
	return ID + ";balance:" + stream.str();
}
int main()
{
	checkAccount check("1001", 0.0001, "20191120", 1000);
	check.deposit(10000.0);
	cout << check.withdraw() << endl;
	cout << check.toString() << endl;

	saveAccount save("2001", 0.025, "20190101");
	save.deposit(2000);
	cout << save.withdraw() << endl;
	cout << save.toString() << endl;
	return 0;
}
