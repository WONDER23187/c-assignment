#include <iostream>
#include <string>
using namespace std;
class person{
public:
	person() = default;
	person(string, string, int, bool, string);
	virtual void print();
protected:
	string id;
	string name;
	int age;
	bool gender;
	string department;
};
person::person(string no, string na, int a, bool g, string d) :id(no), name(na), age(a), gender(g), department(d){}
void person::print()
{
	cout << "id: " << id << endl;
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "gender: " << gender << endl;
	cout << "department: " << department << endl;
}
/////////////////////////////////////////////////
//the definition of the doctor class           //
////////////////////////////////////////////////
class doctor : public person{
public:
	doctor(string, string, int, bool, string, string);
	string diagnose(const string&);
	virtual void print();
private:
	string professional_title;
	string diagnosis;
};
doctor::doctor(string no, string na, int a, bool g, string d, string title) :person(no, na, a, g, d)
{
	professional_title = title;
	diagnosis = " ";
}
string doctor::diagnose(const string &str)
{
	string treatment1 = "no method";
	cin >> diagnosis;
	if (str == "eye")
		treatment1 = "method1";
	if (str == "mouth")
		treatment1 = "method2";
	if (str == "nose")
		treatment1 = "method3";
	if (str == "hand")
		treatment1 = "method4";
	return treatment1;
}
void doctor::print()
{
	cout << "**************report for doctor***************\n";
	person::print();
	cout << "professional_title: " << professional_title << endl;
	cout << "diagnosis: " << diagnosis << endl;
}
/////////////////////////////////////////////////////
// the definition of the patient class             //
/////////////////////////////////////////////////////
class patient : public person{
public:
	patient();
	void regist();
	void seedoctor(doctor&);
	virtual	void print();
private:
	string illness;
	string treatment;
};
patient::patient() :person()
{	
}
void patient::regist()
{
	cout << "id:  " << endl;
	cin >> id;
	cout << "name:  " << endl;
	cin >> name;
	cout << "age:  " << endl;
	cin >> age;
	cout << "gender:  " << endl;
	cin >> gender;
	cout << "department:  " << endl;
	cin >> department;
	illness = "";
	treatment = "";
}
void patient::seedoctor(doctor& a)
{
	cin >> illness;
	treatment = a.diagnose(illness);
}
void patient::print()
{
	cout << "*********** the report for patient****************\n";
	person::print();
	cout << "illness detail: " << illness << endl;
	cout << "treatment detail: " << treatment << endl;
}

int main()
{
	person *p;
	doctor d("1120", "Liu", 50, 1, "ophthalmology", "professor");
	patient patient1;
	patient1.regist();
	patient1.seedoctor(d);
	p = &patient1;
	p->print();
	p = &d;
	p->print();
	return 0;
}
