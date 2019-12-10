#include <iostream>
#include <string>
using namespace std;

class person{
public:
	person(string, string);
	virtual void display();
	~person();
protected:
	string ID;
	string name;
};

class student :virtual public person{
public:
	student(string, string, string, int);
	void display();
	~student();
protected:
	string courseName;
	int courseHour;
};

class teacher : virtual public person{
public:
	teacher(string, string, int);
	void display();
	double salary();
	~teacher();
protected:
	int workHour;
};

class teacherAssitant : public student, public teacher{
public:
	teacherAssitant(string, string, string, int, int);
	void display();
	double salary();
	~teacherAssitant();
};
////////////////////////////////////////////
// definition of the person class
//////////////////////////////////////////
person::person(string id, string name0)
{
	ID = id; name = name0;
	cout << "Constructing person class\n";
}
void person::display()
{
	cout << ID << name << endl;
}
person::~person()
{
	cout << "Destroying person class\n";
}
////////////////////////////////////////////
// definition of the student class
//////////////////////////////////////////
student::student(string id, string name0, string name1, int hour) :person(id, name0), courseName(name1), courseHour(hour)
{
	cout << "Constructing student class\n";
}
void student::display()
{
	cout << ID << name << courseName << courseHour << endl;
}
student::~student()
{
	cout << "Destroying student class\n";
}
////////////////////////////////////////////
// definition of the teacher class
//////////////////////////////////////////
teacher::teacher(string id, string name0, int hour) :person(id, name0), workHour(hour)
{
	cout << "Constructing teacher class\n";
}
void teacher::display()
{
	cout << ID << name << workHour << salary() << endl;
}
double teacher::salary()
{
	return workHour * 30 + 4500;
}
teacher::~teacher()
{
	cout << "Destroying teacher class\n";
}
////////////////////////////////////////////
// definition of the teacherAssitant class
//////////////////////////////////////////
teacherAssitant::teacherAssitant(string id, string name0, string name1, int chour, int whour) :person(id, name0), student(id, name0, name1, chour),
teacher(id, name0, whour)
{
	cout << "Constructing teacherAssitant class\n";
}
void teacherAssitant::display()
{
	cout << ID << name << courseName << courseHour << workHour << salary() << endl;
}
double teacherAssitant::salary()
{
	return workHour * 25;
}
teacherAssitant::~teacherAssitant()
{
	cout << "Destroying teacherAssitant class\n";
}
////////////////////////////////////////////
// definition of the top-level function
//////////////////////////////////////////
void fn(person& per)
{
	per.display();
}
////////////////////////////////////////////
// the main function tests all classes
//////////////////////////////////////////
int main()
{
	student st("001", "Zhao", "OOP", 48);
	fn(st);
	teacher te("001", "Liu", 48);
	fn(te);
	teacherAssitant ta("001", "Wang", "English", 64, 20);
	fn(ta);
	return 0;
}
