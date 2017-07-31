#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG
#ifdef DEBUG
	#define	debugprint(x)	cout << x << '\n';
#else
	#define debugprint(x)	
#endif

int n, q;
vector<int> v;

// Complexity O(n^2)
void exhaustive(int x, int y)
{
	int retVal = 0, numX, numY;

	for (int from = 0; from < v.size(); ++from)
	{
		numX = numY = 0;
		for (int to = from; to < v.size(); ++to)
		{
			if (v[to] == x)
				numX++;
			else if (v[to] == y)
				numY++;
			if (numX == numY)
				retVal++;
		}
	}

	cout << retVal << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> q;
	
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}


	for (int i = 0; i < q; ++i)
	{
		int x, y;
		cin >> x >> y;
		exhaustive(x, y);
	}
}
