#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debugprint(x) cout << x << endl
#else
#define debugprint(x)
#endif

int n, k;

bool permutate(int pos, vector<int>& arr, vector<bool>& taken) {
	bool retVal = false;
	int positiveNextPos = k + pos, negativeNextPos = pos - k;

	debugprint("permutate from " << pos);

	if (pos == n + 1)
		return true;

	if (negativeNextPos >= 1 && arr[pos] == negativeNextPos) {
		debugprint("taken[" << negativeNextPos << "] is not taken");
		retVal = permutate(pos + 1, arr, taken);
	}

	if (retVal == false && positiveNextPos <= n && taken[positiveNextPos] == false && taken[pos] == false) {
		debugprint("taken[" << positiveNextPos << "] is not taken");
		// try positive next position
		arr[pos] = positiveNextPos;
		taken[positiveNextPos] = true;
		arr[positiveNextPos] = pos;
		taken[pos] = true;
		retVal = permutate(pos + 1, arr, taken);
		taken[positiveNextPos] = false;
		taken[pos] = true;
	}
	

	return retVal;
}

void exhaustive()
{
	vector<int> arr;
	vector<bool> taken(n + 1, false);

	for (int i = 0; i < taken.size(); ++i)
	{
		arr.push_back(i);
	}

	if (k == 0 || permutate(1, arr, taken) == true) {
		for (int i = 1; i <= n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main()
{
	int caseNum;
	cin >> caseNum;
	do
	{
		cin >> n >> k;

		exhaustive();
	} while (--caseNum);
}