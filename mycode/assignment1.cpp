#include <iostream>
#include <string>
using namespace std;
void input(string(&Name)[3], string& School, string& Clas_s, int(&No)[3])
{
	cout << "学校：";
	cin >> School;
	cout << "班级：";
	cin >> Clas_s;
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：";
		cin >> Name[i];
		cout << "学号：";
		cin >> No[i];
	}
}

void output(string(&Name)[3], int(&No)[3])
{
	for (int i = 0; i < 3; i++)
		cout << "姓名: " << Name[i] << "  学号: " << No[i] << endl;
}

void output(string School, string Clas_s)
{
	cout << "学校: " << School << "  班级: " << Clas_s << endl;
}

int main()
{
	string name[3];
	string school;
	string clas_s;
	int no[3];
cout << "请按提示输入学生信息" << endl;
	input(name, school, clas_s, no);
	output(school, clas_s);
	output(name, no);		
	return 0;
}
