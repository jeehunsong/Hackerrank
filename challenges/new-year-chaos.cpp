#include <iostream>
#include <vector>

using namespace std;

int numTest, numPerson;
vector<int> queue;

void solve()
{
#if 0
	int retVal = 0;
	for (int idx = 0 ; idx < numPerson ; ++idx) {
		if (queue[idx] - idx > 3 ) {
			cout << "Too chaotic" << endl;
			return;
		}
		if (queue[idx] - idx <= 3 && queue[idx] - idx > 1) {
			retVal += queue[idx] - idx - 1;
		}
	}
	cout << retVal << endl;
#endif
	vector<int>& q = queue;
	int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) {
            	// Count number of "TAKE OVER"
            	ans++;
            	cout << "i " << i << " q[i] " << q[i] << " j " << j << " q[j] " << q[j] << endl;
            }
    }
	cout << ans << endl;
}

int main()
{
	cin >> numTest;

	do
	{
		cin >> numPerson;
		queue = vector<int>(numPerson);

		for (int i = 0; i < numPerson; ++i)
		{
			cin >> queue[i];
		}

		solve();
	} while (--numTest);
}