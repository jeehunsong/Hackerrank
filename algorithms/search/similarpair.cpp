#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

//#define DEBUG

using namespace std;

inline int abs(int a) { return a > 0 ? a : -a; }
inline int min(int a, int b) { return a > b ? b : a; }
inline int max(int a, int b) { return a > b ? a : b; }

int numNode, range;
vector<vector<int> > sibling;
set<int> ancestor;

int solve(int head) {
	int retVal = 0;
#ifdef DEBUG
	cout << "Solve from head " << (head + 1) << endl;
#endif // DEBUG

	for (auto it = ancestor.lower_bound(head - range) ; it != ancestor.upper_bound(head + range) ; ++it) {
		++retVal;
	}

	ancestor.insert(head);

	for (auto it = sibling[head].begin(); it != sibling[head].end(); ++it)
	{
		retVal += solve(*it);
	}

	ancestor.erase(head);

	return retVal;
}

int main()
{
	cin >> numNode >> range;
	sibling.resize(numNode);

	int a, b;
	vector<bool> isHead(numNode, true);
	for (int i = 0; i < numNode - 1; i++) {
		cin >> a >> b;
		sibling[--a].push_back(--b);
		isHead[b] = false;
	}

	int head;
	for (head = 0; head < numNode; head++)
	{
		if (isHead[head])
			break;
	}
	
	cout << solve(head) << endl;
}