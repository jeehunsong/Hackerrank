// TODO
// 1. Implement node-contain
// 2. Implement node-connection


#include <iostream>
#include <vector>

using namespace std;

#define DEBUG
#ifdef DEBUG
	#define	debugprint(x)	cout << x << endl;
#else
	#define debugprint(x)	
#endif

struct nodeset;

vector<nodeset> vNodeset;

struct nodeset
{
	int nodeNum, parent;
	vector<int> adj, child;

	nodeset(int nodeNum = 0): nodeNum(nodeNum), parent(-1) {
		debugprint("Make nodeset with " << this->nodeNum << " nodes, sizeof node " << vNodeset.size())
	}

	
};

int main()
{
	int numOperation;
	cin >> numOperation;

	do
	{
		char c;
		int a;
		cin >> c >> a;
		if(c == 'A') {
			vNodeset.emplace_back(a);
		}
		else if (c == 'B') {
			int b;
			cin >> b;


		}
		else if (c == 'C') {
			vNodeset.emplace_back();

		}
	} while (--numOperation);
}