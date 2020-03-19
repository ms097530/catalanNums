#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Catalan Numbers
//Program to calculate the nth Catalan Number


int getCatalanNum(int n)
//input : desired Catalan number in the sequence of integers starting from the 0th number
//output: nth Catalan number or -1 if negative number is input
{

	if (n < 0)
		return -1;
	if (n == 0)
	{
		//cout << 1 << endl;
		return 1;
	}


	vector<int> catalan(n + 1, 0);

	catalan[0] = catalan[1] = 1;

	//cout << catalan[0] << " " << catalan[1] << " " << catalan[2] << endl;

	for (int i = 2; i <= n; ++i)
	{
		//cout << "catalan[" << i - 1 << "] = " << catalan[i - 1] << endl;
		for (int j = i; j > int(ceil(i / 2.0)); --j)
		{
			//cout << "Before: catalan[" << i << "-1] = " << catalan[i-1] << "   j = " << j << endl;
			catalan[i] += 2 * catalan[j - 1] * catalan[i - j];

		}
		if (i % 2 != 0)
			catalan[i] += catalan[int(floor(i / 2.0))] * catalan[int(floor(i / 2.0))];
	}

	//cout << catalan[n] << endl;

	return catalan[n];
}

int main()
{
	for (int i = 0; i <= 6; ++i)
		getCatalanNum(i);
	
	return 0;
}