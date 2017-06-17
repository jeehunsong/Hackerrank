#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long long min = 0, max = 0;
    vector<int> v(5);
    
    for (int i = 0 ; i < 5 ; ++i) {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    for (int i = 0 ; i < 4 ; ++i) {
        max += v[4 - i];
        min += v[i];
    }
    cout << min << " " << max;
    
    return 0;
}
