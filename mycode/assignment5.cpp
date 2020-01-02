//class Account
//file:Account.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
using namespace std;
class Account {
protected:
	string No; //编号
	double balance; //余额
	double annual_interest_rat; //年利率
	int date_created; //开户日期
public:
	Account();
	void deposit() {} //存款
	void withdraw() {} //取款
	void display();
	string ToString()const {}
};
//file:Account.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include "Account.h"
using namespace std;
Account::Account()
{
	No = "25496100"; 
	balance = 0; 
	annual_interest_rat = 0; 
	date_created = 2019;
}
void Account::display()
{
	cout << "您的账号为：" << No << endl;
	cout << "开户日期为：" << date_created << "年" << endl;
	cout << "选择您需要的服务项目：（1.存款,2.取款）" << endl;
}
//class saveAccount
//file:saveAccount.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include "Account.h"
using namespace std;
class saveAccount :public Account {
private:
	double principal;
	int data_current;
public:
	string ToString() const;
	saveAccount(int x, double y);
	void deposit();
	void withdraw();
	~saveAccount() {}
};
//file:saveAccount.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include "Account.h"
#include "saveAccount.h"
using namespace std;
saveAccount::saveAccount(int x, double y) {
	data_current = x;
	principal = y;
}
void saveAccount::deposit()
{
	cout << "输入存入金额" << endl;
	double a;
	cin >> a;
	annual_interest_rat = 4.750;
	balance = (a + principal) * (1 + annual_interest_rat * 0.01 * (data_current - (long long)date_created));
	cout << "您的账户余额为 " << balance << endl;
}
void saveAccount::withdraw()
{
	cout << "输入取款金额" << endl;
	double b;
	cin >> b;
	balance = principal * (1 + annual_interest_rat * 0.01 * (data_current - (long long)date_created));
	if (b > balance)
		cout << "超过限额，取款失败" << endl;
	else
	{
		balance -= b;
		cout << b << " 元已取出，" << "当前余额 " << balance << endl;
	}

}
string saveAccount::ToString()const {
	ostringstream oss;
	oss << No << '\t' << balance;
	cout << oss.str() << endl;
	return oss.str();
};
//class checkAccount
//file:checkAccount.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include "Account.h"
using namespace std;
class checkAccount :public Account {
private:
	double overdraft_limit;
	double principal;
	int data_current;
public:
	string ToString()const;
	checkAccount(int x, double y);
	void deposit();
	void withdraw();
	~checkAccount() {}
};
//file:checkAccount.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include "Account.h"
#include "checkAccount.h"
using namespace std;
checkAccount::checkAccount(int x, double y) {
	data_current = x;
	principal = y;
	overdraft_limit = 1000;
}
void checkAccount::deposit()
{
	cout << "输入存入金额" << endl;
	double a;
	cin >> a;
	annual_interest_rat = 0.350;
	balance = (a + principal) * (1 + annual_interest_rat * 0.01 * (data_current - (long long)date_created));
	cout << "您的账户余额为 " << balance << endl;
}
void checkAccount::withdraw()
{
	cout << "输入取款金额" << endl;
	double b;
	cin >> b;
	balance = principal;
	if (b > balance + overdraft_limit)
		cout << "超过限额，取款失败" << endl;
	else
	{
		balance -= b;
		cout << b << " 元已取出，" << "当前余额 " << balance << endl;
	}
}
string checkAccount::ToString()const {
	ostringstream oss;
	oss << No << '\t' << balance;
	cout << oss.str() << endl;
	return oss.str();
};
//file:Bank.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
#include "Account.h"
#include "checkAccount.h"
#include "saveAccount.h"
using namespace std;
int main()
{
	int i, j, k,cur;
	double pri;
	cout << "选择账户类型：(1.支票账户，2.储蓄账户)" << endl;
	cin >> i;
	if ( i == 1)
	{
		cout << "输入当前年份及存款金额（不存输入0）" << endl;
		cin >> cur >> pri;
		checkAccount* C = new checkAccount(cur,pri);
		C->display();
		cin >> j;
		if ( j == 1)
			C->deposit();
		if ( j == 2)
			C->withdraw();
		C->ToString();
	}
	if (i == 2)
	{
		cout << "输入当前年份及存款金额（不存输入0）" << endl;
		cin >> cur >> pri;
		saveAccount *S=new saveAccount(cur,pri);
		S->display();
		cin >> k;
		if (k == 1)
			S->deposit();
		if (k == 2)
			S->withdraw();
		S->ToString();
	}
	return 0;
}
