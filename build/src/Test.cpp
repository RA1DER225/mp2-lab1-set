#include "tset.h"
#include "tbitfield.h"

#include<iostream>
using namespace std;
int main() {
	int len1 = 8;
	int len2 = 16;
	TBitField a(len1);
	TBitField a0(len1);
	TBitField d(len2);
	TBitField b(a);


	std::cout << "Input a : 0 or 1 (000111)\n";
	std::cin >> a;
	std::cout << "You input :" << a;


	std::cout << "Input d : 0 or 1 (10001001)\n";
	std::cin >> d;
	std::cout << "You input :" << d;


	std::cout << "Input a0 : 0 or 1 (101010)\n";
	std::cin >> a0;
	std::cout << "You input :" << a0;


	std::cout << "GetLength: "<< a.GetLength()<<endl;


	std::cout << "GetBit [5] : " << a.GetBit(5) << endl;
	std::cout << a;


	std::cout << "SetBit [5] : ";
	a.SetBit(2);
	std::cout << "SetBit[5] completed\n";
	std::cout << a;


	std::cout << " ClrBit[5] : ";
	a.ClrBit(5);
	std::cout << "ClrBit[5] completed\n";
	std::cout << a;


	std::cout << "operator = \n";
	TBitField c = a;
	std::cout << "operator = complåted\n";
	std::cout << c;


	std::cout << "operator == \n";
	std::cout << "TEST 1\n";
	if (a == c)
	{
		std::cout << "operator == complåted\n";
	}
	else {
		std::cout << "operator == ERROR\n";
	}


	std::cout << "TEST 2\n";
	if (a == d)
	{
		std::cout << "operator == complåted\n";
	}
	else {
		std::cout << "operator == ERROR\n";
	}


	std::cout << "TEST 3\n";
	if (a == a0)
	{
		std::cout << "operator == complåted\n";
	}
	else {
		std::cout << "operator == ERROR\n";
	}

	std::cout << "operator != \n";
	if (a != d)
	{
		std::cout << "operator != complåted\n";
	}
	else {
		std::cout << "operator != ERROR\n";
	}


	std::cout << "operator | \n";
	TBitField tmp1(a | a0);
	std::cout << "operator | completed :" << tmp1<<endl;

	
	std::cout << "operator & \n";
	TBitField tmp2(a & a0);
	std::cout << "operator | completed :" << tmp2 << endl;



}