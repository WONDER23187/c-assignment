#include <iostream>
#include <string>
using namespace std;
class File{
public:
	File(string = "", string = "");
	bool operator==(const File&);
private:
	string name, type;
};
File::File(string _name, string _type)
{
	name = _name;
	type = _type;
}
bool File::operator==(const File& f)
{
	return type == f.type;
}
int main()
{
	File f1("aa", "txt"), f2("bb", "png");
	if (f1 == f2)
		cout << "the two file types are same\n";
	else
		cout << "their types are different\n";
	return 0;
}
