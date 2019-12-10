#include <iostream>
#include <string>
using namespace std;
class File{
public:
	File(string = "", string = ""); //定义缺省构造
	bool operator==(const File&); //运算符==重载
private:
	string name, type;
};
File::File(string _name, string _type) //定义
{
	name = _name;
	type = _type;
}
bool File::operator==(const File& f) //定义
{
	return type == f.type;
}
int main()
{
	File f1("aa", "txt"), f2("bb", "png"); //调用
	if (f1 == f2)
		cout << "the two file types are same\n";
	else
		cout << "their types are different\n";
	return 0;
}
