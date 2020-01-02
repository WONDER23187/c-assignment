#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

class eye {
public:
	eye() {
		color = rand() % 3;
	}
	int getcolor() { return color; }
private:
	int color;         
};

class fur {
public:
	fur() {
		color = rand() % 3;
		length = rand() % 2;
	}
	int getcolor() { return color; }
	int getlength() { return length; }
private:
	int color, length;       
};

class cat {
public:
	int getecolor() { return ec.getcolor(); }
	int getfcolor() { return fc.getcolor(); }
	int getlength() { return l.getlength(); }
private:
	eye ec;
	fur fc, l;
};

class cage {
public:
	cage() { count = 0; }
	int number() { return count; }
	void putCat();
	void display();
private:
	cat* caught[10];
	int count;
};

void cage::putCat()
{
	while (getchar() == '\n')
	{
		cout << "正在笼子中放入第" << count + 1 << "只猫" << endl;
		caught[count] = new cat;
		count++;
	}
}

void cage::display()
{
		int a = 0, b = 0, c = 0;
		int x = 0, y = 0, z = 0;
		
		for (int i = 0; i < count; i++)
		{
			switch (caught[i]->getecolor()) //a,b,c
			{
			case 0:
			{
				cout << "第" << i + 1 << "只绿眼 ";
				a++;
				break;
			}
			case 1:
			{
				cout << "第" << i + 1 << "只蓝眼 ";
				b++;
				break;
			}
			case 2:
			{
				cout << "第" << i + 1 << "只棕眼 ";
				c++;
				break;
			}

			}
			switch (caught[i]->getfcolor()) //x,y,z
			{
			case 0:
			{
				cout << "黑毛\t";
				x++;
				break;
			}
			case 1:
			{
				cout << "灰毛\t";
				y++;
				break;
			}
			case 2:
			{
				cout << "棕毛\t";
				z++;
				break;
			}
			}

			switch (caught[i]->getlength())
			{
			case 0:
			{
				cout << "短毛\t" ;
				break;
			}
			case 1:
			{
				cout << "长毛\t" ;
				break;
			}
			}
			if (i == 0)
				cout << "不打架" << endl;
			
			else
			{
				if (i % 3 != 0)
					cout << "打架了" << endl;
				else
				{
					if ((x != y) || (x != z) || (y != z) || (a != b) || (a != c) || (b !=c))
						cout << "打架了" << endl;
					else
						cout << "不打架" << endl;
				}
			}
		}
}

int main()
{
	srand((unsigned)time(NULL));
	cage A;
	A.putCat();
	A.display();
	return 0;
}
