#include<iostream>
#include"Rational.h"
using namespace std;

int main() {
	Rational test1 ,test2(12,36);
	cin >> test1;
	cout <<"You enter rational: "<< test1 << endl;;
	cout << "(" << test1 << ")+(" << test2 << ")=" << test1 + test2 << endl;
	cout << "(" << test1 << ")-(" << test2 << ")=" << test1 - test2 << endl;
	cout << "(" << test1 << ")*(" << test2 << ")=" << test1 * test2 << endl;
	cout << "(" << test1 << ")/(" << test2 << ")=" << test1 / test2 << endl;

	system("PAUSE");
	return 0;
}