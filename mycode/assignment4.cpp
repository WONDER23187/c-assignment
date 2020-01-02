#include <iostream>
using namespace std;
class Rational
{
private:
	int a;
	double b;
public:
	Rational(int x, double y) { a = x; b = y; }
	Rational() { a = 0; b = 1.0000; }
	int add_a() { a++; return a; }
	double add_b() { b++; return b; }
	void operator++(int)
	{ ++a; }
	operator double() { return a/b; }
	friend ostream& operator<<(ostream& output, const Rational& R)
	{
		output << R.a / R.b;
		return output;
	}
	friend Rational operator+(Rational& rat1, int)
	{ return Rational(rat1.a + 34, rat1.b); }
	friend Rational operator+(int, Rational& rat2)
	{ return Rational(12 + rat2.a, rat2.b); }
	friend Rational operator-(Rational& rat0)
	{ return Rational(-rat0.a, rat0.b); }
};

int main()
{
	Rational rat0;
	cout << rat0 << endl;
	Rational rat1 = -rat0;
	cout << rat1 << endl;
	Rational rat2 = rat1 + 34;
	cout << rat2 << endl;
	Rational rat3;
	rat3 = 12 + rat2;
	rat3++;
	cout << rat3 << endl;
	cout << (double)rat3 << endl;

	Rational ratx;
	double rats=0;
	for (int i = 0; i < 49; i++)
	{
		ratx.add_a();
		ratx.add_b();
		rats = rats + (double)ratx;	
	}
	cout << rats << endl;
	return 0;
}
