#include <iostream>
using namespace std;

class Rational{
public:
	Rational();
	Rational(int, int);

	Rational& operator+=(Rational&);
	operator double();

	Rational operator+(int);
	Rational& operator-();
	Rational& operator=(Rational&);
	Rational operator++(int);

	friend Rational operator+(int, Rational&);
	friend ostream& operator<< (ostream&, Rational&);
private:
	double numerator;
	double denominator;

};
Rational::Rational() :numerator(0), denominator(1)
{}
Rational::Rational(int no, int den) : numerator((double)no), denominator((double)den)
{}

Rational& Rational::operator+=(Rational& rat)
{
	numerator = numerator * rat.denominator + denominator * rat.numerator;
	denominator = denominator * rat.denominator;
	return *this;
}
Rational Rational::operator+(int n)
{
	return Rational((double)n * denominator + numerator, denominator);
}
Rational& Rational::operator-()
{
	numerator = -numerator;
	return *this;
}
Rational& Rational::operator=(Rational& rat)
{
	numerator = rat.numerator;
	denominator = rat.denominator;
	return *this;
}
Rational Rational::operator++(int)
{
	Rational temp = *this;
	numerator += denominator;
	return temp;
}
ostream& operator<< (ostream& out, Rational& rat)
{
	out << rat.numerator << "/" << rat.denominator ;
	return out;
}
Rational operator+(int n, Rational& rat)
{
	return Rational((double)n * rat.denominator + rat.numerator, rat.denominator);
}

Rational::operator double()
{
	return numerator / denominator;
}
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
	//cout << rat3 << endl;
	cout << endl; rat3++;
	cout << rat3 << endl;

	cout << (double)rat3 << endl;

	// there are two ways to evaluate the expression of 1/2 + 2/3 +...+ 49/50
	//way1- overloading operator+=
	Rational sum;
	for (int i = 1; i < 50; i++)
	{
		sum += Rational(i, i + 1); 
		cout << i << " loop " << sum << " | " << (double)sum << endl;
	}
	cout << "1/2 + 2/3 + ....+ 49/50 = " << sum << "=" << (double)sum << endl;

	//way2 - using type conversion operator
	/*double dsum = 0.0;
	for (int i = 1; i < 50; i++)
		dsum += (double)Rational(i, i + 1);
	cout << "1/2 + 2/3 + ....+ 49/50 = " << dsum << endl;*/

	return 0;
}
