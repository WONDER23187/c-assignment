//File:MyInteger.h
#pragma once
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
class MyInteger
{
public:
	MyInteger(int i) {
		value = i;
		cout << "参数都有默认值的默认构造函数调用并初始化value：" << value << endl;
	}; 
	int get() const { return value; } 
	int add(const MyInteger&b);
	int parseInt(const string&);
	~MyInteger(void);
private:
	int value; 
};
//File:MyInteger.cpp
#include "MyInteger.h"
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int MyInteger::add(const MyInteger&b)
{
	return this->value + b.value;
}
int MyInteger::parseInt(const string&c)
{
	int result = 0;
	for (int i = 0; i < c.length(); i++) {
		result *= 10;
		result += c[i] - 48;
	}
	return result;

}
MyInteger::~MyInteger(void)
{
	cout << "析构函数已执行!" << endl;
}

int main()
{
	string c; //存储键盘接受的数字字符串
	cout << "对于常量get函数及对于默认构造函数调用的测试:" << endl;
	MyInteger a(11),b(20); //加数11，20
	cout << b.get() << endl;
	cout << "对于加法函数的测试:" << endl;
	cout << a.add(b) << endl; //11+20=31
	cout << "对于parseInt函数的测试:" << endl;
	cout << "输入字符串:" << endl;
	cin >> c;
	cout <<"转换结果为："<<b.parseInt(c) << endl;
	return 0;
}
