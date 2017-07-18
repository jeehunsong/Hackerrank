#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> array[2];
int numElement;

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
			int tempGcd = gcd(array[0][i], array[1][j]);
			if (tempGcd > maxGcd || (tempGcd == maxGcd && (array[0][i] + array[1][j]) > sum)) {
				maxGcd = tempGcd;
				sum = (array[0][i] + array[1][j]);
			}
		}
	}

	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	int input;
	cin >> numElement;

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < numElement; ++i)
		{
			cin >> input;
			array[j].push_back(input);
		}
	}
	
	exhaustive();
}