#include "cat.h"

int cat::furColorNum[3] = { 0 };
string cat::color[5] = { "black", "gray", "brown", "green", "blue" };
cat::cat()
{
	srand((unsigned)time(0));
	setFurColor();
	setFurLength();
	setEyeColor();
}
cat::~cat()
{}
void cat::setFurColor()
{
	int x = rand() % 3;
	furColor = color[x];
	furColorNum[x]++;
}
void cat::setEyeColor()
{	
	int x = rand() % 3;
	if (x)
		x += 2;
	else
		x += 3;
	eyeColor = color[x];
}
void cat::setFurLength()
{
	int x = rand() % 2;
	if (x == 0)
		furLength = "short";
	if (x == 1)
		furLength = "long";
}
string cat::getFurColor() const
{
	return furColor;
}
string cat::getFurLength() const
{
	return furLength;
}
string cat::getEyeColor() const
{
	return eyeColor;
}
int* cat::getColorNum()
{
	return furColorNum;
}
string cat::getColor(int n)
{
	return color[n];
}
///////////////////////////////////////////////////////
//cage's defintion
//////////////////////////////////////////////////////

cage::cage() 
{
	catNum = 0;
}
void cage::enter()
{
	_cat[catNum] = new cat();
	cout << "Fur: " << _cat[catNum]->getFurColor() << " ;Eye:" << _cat[catNum]->getEyeColor() << " ;Fur length: " << _cat[catNum]->getFurLength() << endl;
	catNum++;
}
void cage::checkFight()
{
	cout << "check cat flighting\n";
	for (int i = 0; i < catNum; i++)
	{
		for (int j = i + 1; j < catNum; j++)
		{
			if (_cat[i]->getFurColor() == _cat[j]->getFurColor())
				if (_cat[i]->getEyeColor() != _cat[j]->getEyeColor())
				{
					cout << "The " << _cat[i]->getEyeColor() << " color fur, but different color eye cats are fighting!\n"; 
					break;
				}
		}
	}
	int *temp = cat::getColorNum();
	for (int i = 0; i < 3; i++) //3 different fur colors
		cout << temp[i] << endl;

	if (temp[0] != temp[1] && min(temp[0], temp[1]) > 0)
		temp[0]> temp[1] ? cout << cat::getColor(0) << " fur cats fight " << cat::getColor(1) << " fur cats!\n" : cout << cat::getColor(1) << " fur cats fight " << cat::getColor(0) << " fur cats!\n";
	if (temp[1] != temp[2] && min(temp[1], temp[2]) > 0)
		temp[1]> temp[2] ? cout << cat::getColor(1) << " fur cats fight " << cat::getColor(2) << " fur cats!\n" : cout << cat::getColor(2) << " fur cats fight " << cat::getColor(1) << " fur cats!\n";
	if (temp[0] != temp[2] && min(temp[0], temp[2]) > 0)
		temp[0]> temp[2] ? cout << cat::getColor(0) << " fur cats fight " << cat::getColor(2) << " fur cats!\n" : cout << cat::getColor(2) << " fur cats fight " << cat::getColor(0) << " fur cats!\n";
}
