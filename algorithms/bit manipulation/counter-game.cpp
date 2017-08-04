#include <iostream>

using namespace std;

const bool louise = true;
const bool richard = false;

bool counterGame(unsigned long long n)
{
	bool turn = louise;
	unsigned long long bitmask = 1ll << 63;

	while (n != 1) {
//		cout << bitmask << " " << n << " " << (bitmask & n) << endl;
		if ((bitmask & n) != 0)  {
//			cout << "bitmask & n is not 0" << endl;
			if (n == bitmask)  {
				n = n >> 1;
//				cout << "n is equal to bitmask " << n << endl;
			}
			else {
				n = n - bitmask;
//				cout << "n is not equal to bitmask " << n << endl;
			}

			turn ^= true;
		}
		else {
//			cout << "bitmask is " << (bitmask & n) << endl;
		}
		
		bitmask = bitmask >> 1;
	}

	return !turn;
}


int main()
{
	int numCase;
	cin >> numCase;
	do
	{
		unsigned long long init;
		cin >> init;

		if (counterGame(init) == louise)
			cout << "Louise" << endl;
		else
			cout << "Richard" << endl;

	} while (--numCase);
}