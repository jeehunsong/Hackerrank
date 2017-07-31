#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define DEBUG

vector<int> freq(26);

void solve() {
	bool verdict = false;

	for (int i = 1 ; i < 26 ; ++i)
	{
		if (freq[i] == 0) {
			verdict = true;
			break;
		}
		if (freq[i] == freq[0] - 1 && (i == 25 || freq[i + 1] == 0)) {
			verdict = true;
			break;
		}
		if (freq[i] != freq[0])
			break;
	}

	if (verdict == false) {
		int startPos;
		for (int i = 25; i >= 0 ; --i)
		{
			if (freq[i] > 0) {
				startPos = i;
#ifdef DEBUG
				cout << "StartPos " << i << endl;
#endif
				break;
			}
		}
		if (freq[0] == freq[startPos] 
			|| (freq[0] - 1 == freq[1] && freq[1] == freq[startPos])) {
			verdict = true;
		}
	}

	if (verdict == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main()
{
	string input;

	cin >> input;
	for (int i = 0; i < input.size() ; ++i)
	{
		char& c = input[i];
		//if (c >= 'a' && c <= 'z')
			++freq[c - 'a'];
	}

	sort(freq.begin(), freq.end(), [](int a, int b){return a > b;});

#ifdef DEBUG
	for (auto i : freq)	cout << i << " "; cout << endl;
#endif

	solve();

	return 0;
}