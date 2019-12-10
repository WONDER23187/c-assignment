#include "cat.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cage _cage;
	cout << "press a Enter key to add the next cat.\n";
	while (cin.get() == '\n')
	{
		_cage.enter();
		_cage.checkFight();
		
		cout << "Do you add the next cat? yes-press a Enter key' no-press a N key.";
		if (cin.get() == 'n')
			break;
	}
	return 0;
}
