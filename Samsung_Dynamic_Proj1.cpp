// Samsung_Dynamic_Proj1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The Problem: we have an array(massive) of size n, n<=100(but you can try bigger). The array contains pipes(or blocks, it doesn't metter) of different lenght l.
// Maximum sum of lenghts of all pipes <=1 000. 
// We need to build 2 equal columns with maximum height.
// You don't need to use all of pipes => you can skip some of them
// you can't use any of methods/functions or predefined data structures(like vector, max function etc.). if you need something, make it yourself

#include "pch.h"
#include <iostream>

#include <set> // just to show how many uniq lenghts we get.



using namespace std;


int test1[] = { 5,27,24,12,12,2,15,25,32,21,37,29,20,9,24,35,26,8,31,5,25,21,28,3,5 }; // 25 elements  answear = 239
int test2[] = { 5,27,24,12,12,2,15,25,32,21,37,29,20,9,24,35,26,8,31,5,25,21,28,3,5, 5,27,24,12,12,2,15,25,32,21,37,29,20,9,24,35,26,8,31,5,25,21,28,3,5 }; // 50 elements  answear = ? 2*239???
int test3[] = { 5,27,24,12,12,2,15,25,32,21,37,29,20,9,24,35,26,8,31,5,25,21,28,3,5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int test4[] = { 5,27,24,12,12,2,15,25,32,21,37,29,20,9,24,35,26,8,31,5,25,21,28,3,5, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
int test5[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

int ValueMatrix[501][501];

int max(int a, int b, int c)
{
	if (a > b)
		if (a > c)
			return a;
		else
			return c;
	else
		if (b > c)
			return b;
		else
			return c;
}

int Count1 = 0; // you can try to check how many times you used Memoization (because of recursive, don't expect big number. but without memoization it will not work)
int Count2 = 0;


set<int> uniq;


int dp(int First, int Second, int index, int size_n)
{
	if (First < 501 && Second < 501)
	{
		if (ValueMatrix[First][Second] >= 0) // Memoization. If we already computed this state => just return answear without recomputing it
		{
			Count1++;
			return ValueMatrix[First][Second];
		}
		else
			if (ValueMatrix[Second][First] >= 0)
			{
				Count2++;
				return ValueMatrix[Second][First];
			}

		int longest = 0;
		int dp1 = 0, dp2 = 0, dp3 = 0;



		if (First == Second)
			longest = First;

		if (index < size_n)
		{
			dp1 = dp(First + test1[index], Second, index + 1, size_n);// add pipe to first column
			dp2 = dp(First, Second + test1[index], index + 1, size_n);// add pipe to second column
			dp3 = dp(First, Second, index + 1, size_n);// skip pipe
		}

		uniq.insert(dp1);
		uniq.insert(dp2);
		uniq.insert(dp3);


		int max_dp = max(dp1, dp2, dp3);
		if (longest < max_dp)
			longest = max_dp;

		ValueMatrix[First][Second] = longest;

		return longest;
	}
	else
		return 0;
}

void Zeroes()
{
	for (int i = 0; i < 501; ++i)
	{
		for (int j = 0; j < 501; ++j)
		{
			ValueMatrix[i][j] = -1;
		}
	}
}


int main()
{
	Zeroes();
	int n = size(test1);

	int summ = 0;
	for (int i = 0; i < n; ++i)
	{
		summ += test1[i];
	}
	cout <<"sum = "<< summ << endl;
	int t = dp(0, 0, 0, n);

	cout <<"maximum columns height = "<< t << endl;


	cout << "press any button to exit:";
	int end;
	cin >> end;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
