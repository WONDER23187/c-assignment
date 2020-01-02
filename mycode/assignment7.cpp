#include<iostream>
#include<cstring>
using namespace std;
class Person {
protected:
	int No;
	string Name;
	int Age;
	string Gender;
	string Department;
public:
	Person(int no, string na, int ag, string ge, string de) :No(no), Name(na), Age(ag), Gender(ge), Department(de) {}
	void print();
};
class Doctor :virtual public Person {
private:
	string title;
public:
	Doctor(int no, string na, int ag, string ge, string de, string ti) :Person(no, na, ag, ge, de), title(ti) {}
	void onDuty();
	string diagnose(string, string&);
	void print();
};
class Patient :virtual public Person {
private:
	string illnessDetails;
	string diagnosis;
	string treatment;
public:
	Patient(int no, string na, int ag, string ge, string de) :Person(no, na, ag, ge, de)
	{
		illnessDetails = "ill";
		diagnosis = "dia";
		treatment = "tre";
	}
	void Register();
	void seeDoctor(Doctor& );
	void print();
};
void Person::print() {}
void Patient::Register()
{
	cout << "请输入姓名，年龄，性别，住址" << endl;
	cin >> Name >> Age >> Gender >> Department;
	cout << "挂号成功！您的编号为：" << No << endl;
}
void Patient::seeDoctor(Doctor& d)
{
	cout << "输入症状：" ;
	cin >> illnessDetails;
	treatment = d.diagnose(illnessDetails, diagnosis);
}
string Doctor::diagnose(string ill, string& diagnosis)
{
	cout << "输入诊断结果：";
	cin >> diagnosis;
	string treat;
	cout << "输入治疗方案：";
	cin >> treat;
	return treat;
}
void Patient::print()
{
	cout << "病人信息如下：" << endl;
	cout << No << " " << Name << " " << Age << " " << Gender << " " << Department << " " << endl;
	cout << "挂号成功！" << endl;
	cout << "病症：" << illnessDetails << " 诊断结果：" << diagnosis << " 治疗方案：" << treatment << endl;
}
void Doctor::onDuty()
{
	cout << "主治医师：" << No << " " << Name << " " << Age << " " << Gender << " " << title << " " << endl;
}
void Doctor::print()
{
	cout << "诊断结束，是否叫下一个病人？" << endl;
}
int main()
{
	Patient pa(0, "a", 0, "c", "b");
	Doctor d(217, "班德", 42, "男", " ", "儿科");
	pa.Register();
	string t;
	pa.seeDoctor(d);
	d.onDuty();
	pa.print();
	d.print();
	return 0;
}
