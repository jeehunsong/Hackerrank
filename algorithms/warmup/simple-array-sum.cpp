#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, retVal = 0;
    cin >> n;
    
    for(int i = 0 ; i < n ; ++i) {
        int input;
        cin >> input;
        retVal += input;
    }
    cout << retVal;
    
    return 0;
}
