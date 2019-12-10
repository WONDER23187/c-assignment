#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct student{
	long studentNo;
	char studentName[10];
};
bool input(string &sName, string &cName, student *s, int &num);
void output(string _school, string _class);
void output(student *s, int num);

int main()
{
	string schoolName, className;
	const int maxNumber = 30;
	student _student[maxNumber];
	int number;  //real student number in a class

	if (input(schoolName, className, _student, number))
	{
		cout << "The " << number << " Students Information\n";
		output(schoolName, className);
		output(_student, number);
	}
	else
		cout << "No student information\n";
	return 0;
}

bool input(string &sName, string &cName, student *s, int &num)
{
	cout << "Enter the school and class in which students are\n";
	cin >> sName >> cName;

	cout << "The number of students in a class\n";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "Enter students' no and name\n";
		cin >> s[i].studentNo >> s[i].studentName;
	}
	if (num)
		return true;
	else
		return false;
}

void output(string _school, string _class)
{
	cout << "School name: " << _school << "\t" << "Class name: " << _class << endl;
}

void output(student *s, int num)
{
	for (int i = 0; i < num; i++)
		cout << setw(8) << right << s[i].studentNo << setw(10) << right << s[i].studentName << endl;
}
