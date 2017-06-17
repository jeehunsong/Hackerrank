#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, input, num[3] = {0, 0, 0};
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        cin >> input;
        if (input > 0) ++num[0];
        else if (input < 0) ++num[1];
        else ++num[2];
    }
    
    for (int i = 0 ; i < 3 ; ++i)
        printf("%.6lf\n", (double)num[i] / (double)n);
    
    return 0;
}
