#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//#define DEBUG
#ifdef DEBUG
	#define	debugprint(x)	cout << x << '\n';
#else
	#define debugprint(x)	
#endif

vector<int> numArray[2];
int numElement, maxElement;

inline int max(int a, int b) {
	return a > b ? a : b;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void exhaustive()
{
	int maxGcd = -1, sum = 0;
	for (int i = 0; i < numElement; ++i)
	{
		for (int j = 0; j < numElement; ++j)
		{
			int tempGcd = gcd(numArray[0][i], numArray[1][j]);
			if (tempGcd > maxGcd || (tempGcd == maxGcd && (numArray[0][i] + numArray[1][j]) > sum)) {
				maxGcd = tempGcd;
				sum = (numArray[0][i] + numArray[1][j]);
			}
		}
	}

	cout << sum << '\n';
}

void solve_nsqrtn()
{
	//SOLUTION REFFERED FROM http://codeforces.com/blog/entry/10618
	vector<int> numDivisor[2];
	vector<int> maxDivisor[2];
	for (int i = 0; i < 2; ++i)
	{
		numDivisor[i].resize(maxElement + 1);	// # of element in array divided by index
		maxDivisor[i].resize(maxElement + 1);	// maximum element in array divided by index
	}

	debugprint("")
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < numElement; ++j)
		{
			for (int divisor = 1; divisor * divisor <= numArray[i][j]; ++divisor)
			{
				if (numArray[i][j] % divisor == 0) {
					debugprint(divisor << " divide " << numArray[i][j])
					++numDivisor[i][divisor];
					++numDivisor[i][numArray[i][j] / divisor];
					
					if (maxDivisor[i][divisor] < numArray[i][j]) {
						maxDivisor[i][divisor] = numArray[i][j];
					}
					if (maxDivisor[i][numArray[i][j] / divisor] < numArray[i][j]) {
						maxDivisor[i][numArray[i][j] / divisor] = numArray[i][j];
					}
				}
			}
		}
		debugprint("")
	}

#ifdef DEBUG
	for (int i = 0; i <= maxElement; ++i)
	{
		cout << i << "\t" << numDivisor[0][i] << "\t" << numDivisor[1][i] << '\n';
	}
	cout << '\n';
#endif

	for (int i = maxElement ; i >= 0 ; i--)
	{
		if (numDivisor[0][i] >= 1 && numDivisor[1][i] >= 1) {
			debugprint("GCD " << i << " element " << maxDivisor[0][i] << " and " << maxDivisor[1][i] )
			cout << (maxDivisor[0][i] + maxDivisor[1][i]) << '\n';
			break;
		}
	}
}

void solve_nlogn()
{
	//SOLUTION REFFERED FROM http://codeforces.com/blog/entry/9923
	debugprint("Max element " << maxElement)

	vector<int> isInNumArray[2];
	isInNumArray[0].resize(maxElement + 1, 0);
	isInNumArray[1].resize(maxElement + 1, 0);

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < numArray[i].size(); ++j)
		{
			isInNumArray[i][numArray[i][j]] = 1;
			debugprint("Array " << i << " element " << numArray[i][j])
		}
	}

	vector<int> maxDivisor[2];
	maxDivisor[0].resize(maxElement + 1, 0);
	maxDivisor[1].resize(maxElement + 1, 0);

	for (int i = 1; i <= maxElement; ++i)
	{
		for (int j = 1; j <= maxElement / i; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				if (isInNumArray[k][i * j]) {
					maxDivisor[k][i] = max(maxDivisor[k][i], i * j);
					maxDivisor[k][j] = max(maxDivisor[k][j], i * j);
					debugprint("i: " << i << " j: " << j << " k: " << k << " maxdiv i " << maxDivisor[k][i] << " maxdiv j " << maxDivisor[k][j] )
				}
			}
		}
	}
	
	for (int i = maxElement; i >= 0 ; --i)
	{
		debugprint(i)
		if (maxDivisor[0][i] && maxDivisor[1][i]) {
			debugprint("i " << i << " element in 1st " << (maxDivisor[0][i]) << " element in 2nd " << (maxDivisor[1][i]))
			cout << (maxDivisor[0][i] + maxDivisor[1][i]) << endl;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int input;
	cin >> numElement;

	maxElement = -1;
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < numElement; ++i)
		{
			cin >> input;
			numArray[j].push_back(input);
			if (input > maxElement)
				maxElement = input;
		}
	}
	
	//exhaustive();

	//solve_nsqrtn();

	solve_nlogn();
}


// another link: http://codeforces.com/blog/entry/8672
