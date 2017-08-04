#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//#define DEBUG

vector<int> freq(26);

void solve() {
	int n = freq.size();

	if ((freq[0] == freq.back()) || 
		(n <= 1) ||
		(freq[0] == freq[1] + 1 && freq[1] == freq.back()) ||
		(freq[0] == freq[n - 2] && (freq[0] == freq.back() + 1 || freq.back() == 1))){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main()
{
#if 0
	string input;
	
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		++freq[input[i] - 'a'];
	}
#endif
#if 0
	FILE* fp = fopen("input.txt", "r");
	char ch;
	while (EOF != (ch = fgetc(fp))) {
		putchar(ch);
		if (ch >= 'a' && ch <= 'z') {
			++freq[ch - 'a'];
		}
	}
	cout << endl;

	fclose(fp);
#endif
#if 1
	char c = getc(stdin);
	while (c >= 'a' && c <= 'z') {
		++freq[c - 'a'];
		c = getc(stdin);
	}
#endif

#ifdef DEBUG
	for (auto i : freq)	cout << i << " "; cout << endl;
#endif

	sort(freq.begin(), freq.end(), [](int a, int b) {return a > b; });
	while (freq.back() == 0) {
		freq.pop_back();
	}

#ifdef DEBUG
	for (auto i : freq)	cout << i << " "; cout << endl;
#endif

	solve();

	return 0;
}