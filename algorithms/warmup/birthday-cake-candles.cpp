#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, input, max = 0, ret = 0;
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        cin >> input;
        if (input > max) {
            max = input;
            ret = 1;
        }
        else if (input == max) {
            ret++;
        }
    }
    
    cout << ret;
    
    return 0;
}
