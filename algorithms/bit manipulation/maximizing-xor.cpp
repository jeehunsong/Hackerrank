#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int l, r, a, b;

	cin >> l >> r;

	int retVal = -1;

	for ( a = l ; a <= r ; a++ ) 
		for (b = a ; b <= r ; b++) {
		int xorAB = a ^ b;
		if (xorAB > retVal)
			retVal = xorAB;
		}
	cout << retVal << endl;
}