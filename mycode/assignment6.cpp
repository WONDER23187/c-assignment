#include <iostream>
using namespace std;
class people {
protected:
	string ID;
	string name;
public:
	people(string x, string y) { ID = x; name = y; }
	void display() {}
};
class Teacher :virtual public people {
protected:
	double hour;
	double salary;
public:
	Teacher(string x, string y, double w):people(x,y) { hour = w; salary = 0; }
	void calculating();
	void display();
};
class Student :virtual public people {
protected:
	string course;
	double studying_hour;
public:
	Student(string x, string y, string c, double s) :people(x,y){ course = c; studying_hour = s; }
	Student(string x, string y, string c) :people(x, y) { course = c; }
	void display();
};
class Teacher_Assistant :public Teacher,public Student {
public:
	Teacher_Assistant(string x, string y, string c, double w) :people(x,y),Teacher(x,y,w),Student(x,y,c) { course = c; hour = w; }
	void calculating();
	void display();
};
void Teacher::display()
{
	cout << ID << ' ' << name << ' ' << salary << '$' << endl;
}
void Student::display()
{
	cout << ID << ' ' << name << ' ' <<' '<< course <<' '<< studying_hour << 'h' << endl;
}
void Teacher_Assistant::display()
{
	cout << ID << ' ' << name << ' ' <<' '<< course <<' '<< salary << '$' << endl;
}
void Teacher::calculating()
{
	salary = 50 * hour + 4500;
}
void Teacher_Assistant::calculating()
{
	salary= 35 * hour;
}
int main()
{
	Student s("0421","小明","高数",300);
	s.display();
	Teacher t("9821","老王",250);
	t.calculating();
	t.display();
	Teacher_Assistant ts("2048","小李","英语",247);
	ts.calculating();
	ts.display();
	return 0;
}
