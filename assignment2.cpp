#include <iostream>
#include <string>
using namespace std;

class MyInteger{
public:
	MyInteger(int = 0); //缺省构造
	int get() const; //常成员函数
	MyInteger addition(const MyInteger&);
	int parseInt(const string&);
private:
	int value;
};
MyInteger::MyInteger(int v)
{
	value = v;
}
int MyInteger::get() const //常成员函数定义
{
	return value;
}
MyInteger MyInteger::addition(const MyInteger& myint)
{
	return MyInteger(this->value += myint.value); //this指针用法
}
int MyInteger::parseInt(const string& str)
{
	int j, sum = 0;
	int n, i, flag = 0;
	if (str[0] == '-')     //negative number
	{
		i = 1;
		flag = 1;
	}
	else
	{
		i = 0;
	}
	for (; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			j = str[i] - 48;
			n = str.length() - i - 1;
			sum += j * pow(10, n);
		}
		else
		{
			cout << "Input invalid" << endl;
			exit(1);
		}
	}
	if (flag)
		value = -sum;
	else
		value = sum;
	return value;
}
int main()
{
	MyInteger int1, int2(12); //two different objects
	cout << int1.get() << " | " << int2.get() << endl;  //return  the value of data member
	cout << int1.addition(int2).get () << endl;   //test the addition function
	
	string s;
	cin >> s;
	cout << int2.parseInt(s) << endl;  //test the parseInt function
	return 0;
}
