#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // sum is max N*A = 10^11 < 2^37
    unsigned long long sum = 0;
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        unsigned long long temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum;
    return 0;
}
