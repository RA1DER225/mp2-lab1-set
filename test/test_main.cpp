#include "tset.h"
#include<iostream>
using namespace std;

TSet Sieve_of_Eratosthenes(TSet &S)
{
	int N = S.GetMaxPower()-1;
	cout << "GetMaxPower : " << N<<endl;
	// 1) Заносим в множество все числа от 2 до N
	for (int i = 2; i <= N; ++i)
		S.InsElem(i);

	// 2) Просеиваем
	int lim = sqrt(N);
	for (int i= 2; i <= lim; ++i)
	{
		if (!S.IsMember(i))   // i уже вычеркнуто, пропускаем
			continue;

		// вычёркиваем кратные i, начиная с i*i
		for (int k = i * i; k <= N; k += i)
			S.DelElem(k);
	}

	// 3) Печатаем результат
	cout << "Prime numbers up to " << N << ":\n";
	int cnt = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (S.IsMember(i))
		{
			cout << i << ' ';
			++cnt;
		}
	}
	cout << "\nTotal: " << cnt << endl;
	cout << S<<endl;
	return S;
	
}

TSet Retern_Sieve_of_Eratosthenes(TSet &S)
{
	TSet tmp(~S);
	return tmp;
}


int main() {
	/*int len1 = 8;
	int len2 = 16;
	TBitField a(len1);
	TBitField a0(len1);
	TBitField d(len2);
	
	cout << "----TEST BITFIELD----\n";
	cout << endl;

	cout << "Input a : 0 or 1 (000111)\n";
	cin >> a;
	cout << "You input :" << a;
	cout << endl;


	cout << "Input d : 0 or 1 (1100110011)\n";
	cin >> d;
	cout << "You input :" << d;
	cout << endl;


	cout << "Input a0 : 0 or 1 (101010)\n";
	cin >> a0;
	cout << "You input :" << a0;
	cout << endl;

	TBitField b(a);
	cout << " TBitField b(a) : "<<b<<endl;
	cout << endl;

	cout << "GetLength a: " << a.GetLength() << endl;
	cout << endl;


	cout << "GetBit [5] a : " << a.GetBit(5) << endl;
	cout << a;
	cout << endl;


	cout << "SetBit [5] a: ";
	a.SetBit(2);
	cout << "SetBit[5] completed\n";
	cout << a;
	cout << endl;


	cout << " ClrBit[5] a: ";
	a.ClrBit(5);
	cout << "ClrBit[5] completed\n";
	cout << a;
	cout << endl;



	cout << "operator = \n";
	TBitField c = a;
	cout << "operator = complеted\n";
	cout << c;
	cout << endl;



	cout << "operator == \n";
	cout << "TEST 1\n";
	if (a == c)
	{
		cout << "operator == complеted\n";
	}
	else {
		cout << "operator == ERROR\n";
	}
	cout << endl;



	cout << "TEST 2\n";
	if (a == d)
	{
		cout << "operator == ERROR\n";
	}
	else {
		cout << "operator == completed\n";
	}
	cout << endl;



	cout << "TEST 3\n";
	if (a == a0)
	{
		cout << "operator == ERROR\n";
	}
	else {
		cout << "operator == completed\n";
	}
	cout << endl;


	cout << "operator != \n";
	if (a != d)
	{
		cout << "operator != complеted\n";
	}
	else {
		cout << "operator != ERROR\n";
	}
	cout << endl;



	cout << "operator | \n";
	cout << a<<endl;
	cout << a0 << endl;
	TBitField tmp1bf(a | a0);
	cout << "operator | completed :" << tmp1bf << endl;
	cout << endl;



	cout << "operator & \n";
	cout << a << endl;
	cout << a0 << endl;
	TBitField tmp2bf(a & a0);
	cout << "operator & completed :" << tmp2bf << endl;
	cout << endl;


	cout << "----TEST TSET----\n";

	TSet A(len1);


	cout << "GetMaxPower A : " << A.GetMaxPower() << endl;
	cout << endl;


	cout << "Input A(mp1) (2,3,4)";
	cin >> A;
	cout << "You input:" << A;
	cout << endl;

	TSet A0(len1);
	cout << "Input A(mp1) (5,6,7)";
	cin >> A0;
	cout << "You input:" << A0;
	cout << endl;

	TSet B(A);
	cout << "constructor B(A) completed\n";
	cout << B << endl;
	TSet C(a);
	cout << "constructor C(a) completed\n";
	cout << C<<endl;
	cout << endl;


	cout << "IsMember() : "<<A.IsMember(2);
	cout << "IsMember() completed\n";
	cout << endl;


	cout << "InsElem()  \n";
	A.InsElem(5);
	cout << "InsElem() completed \n";
	cout << A;
	cout << endl;

	cout << "DelElem()  \n";
	A.DelElem(5);
	cout << "DelElem() completed \n";
	cout << A;
	cout << endl;


	cout << "operator = \n";
	TSet D = A;
	cout << "operator = completed\n";
	cout << D;
	cout << endl;

	cout << "operator == \n";
	cout << endl;

	cout << "----TEST 1----\n";
	if (A == A0)
	{
		cout << "operator == ERROR\n";
	}
	else
	{
		cout << "operator == completed\n";
	}
	cout << endl;


	cout << "----TEST 2----\n";
	if (A == D)
	{
		cout << "operator == completed\n";
	}
	else
	{
		cout << "operator == ERROR\n";
	}
	cout << endl;


	cout << "operator != \n";
	cout << "----TEST 1----\n";
	if (A != A0)
	{
		cout << "operator != completed\n";
	}
	else
	{
		cout << "operator != ERROR\n";
	}
	cout << endl;


	cout << "----TEST 2----\n";
	if (A != D)
	{
		cout << "operator != ERROR\n";
	}
	else
	{
		cout << "operator != completed\n";
	}
	cout << endl;


	cout << "operator + (A+A0) \n";
	TSet tmp1(A + A0);
	cout << "A :" << A << endl;
	cout << "A0 :" << A0 << endl;
	cout << tmp1<<endl;
	cout << endl;
	
	
	cout << "operator - (tmp2 -7)\n";
	TSet tmp2(A0);
	cout << "tmp2 :" << tmp2 << endl;
	tmp2 = tmp2 - 7;
	cout << tmp2 << endl;
	cout << endl;

	cout << "operator + (A0+7)\n";
	TSet tmp3(tmp2);
	cout << "tmp3 :" << tmp3 << endl;
	tmp3 = tmp3 + 7;
	cout << tmp3 << endl;
	cout << endl;




	cout << "operator * (A*A0)\n";
	cout << "A :" << A << endl;
	cout << "A0 :" << A0 << endl;
	TSet tmp4(A*A0);
	cout << tmp4 << endl;
	cout << endl;

	cout << "operator ~ (~A)\n";
	TSet tmp5(~A);
	cout <<"A:"<< A << endl;
	cout << tmp5 << endl;
	cout << endl;*/

	cout << "----SIEVE_OF_ERATOSTHENES----\n";

	int N;
	cout << "N = ";
	cin >> N; 
	TSet S(N + 1);
	if (N < 2) {
		cout << "There are no prime numbers\n";
	}
	else
	{
		Sieve_of_Eratosthenes(S);
		cout << S<<endl;
	}
	cout << "----Retern_Sieve_of_Eratosthenes----\n";
	S=Retern_Sieve_of_Eratosthenes(S);
	cout << S;

	
	//a.~TBitField();
	//a0.~TBitField();
	//c.~TBitField();
	//b.~TBitField();
	//tmp1bf.~TBitField();
	//tmp2bf.~TBitField();
	//d.~TBitField();
}
