#ifndef _CAT_H_
#define _CAT_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
class cat{
public:
	cat();
	~cat();
	string getFurColor() const;
	string getFurLength() const;
	string getEyeColor() const;
	
	void setFurColor();
	void setFurLength();
	void setEyeColor();

	static string getColor(int n);
	static int* getColorNum();
private:
	string eyeColor;
	string furColor;
	string furLength;
	static string color[5];
	static int furColorNum[3];
};
class cage{
public:
	cage();
	void enter();
	void checkFight();
private:
	cat* _cat[30];
	int catNum;
};
#endif
