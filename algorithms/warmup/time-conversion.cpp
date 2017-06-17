#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int h, m, s;
    string input;
    
    cin >> input;
    
    h = stoi(input.substr(0, 2));
    m = stoi(input.substr(3, 2));
    s = stoi(input.substr(6, 2));
    
    if (input[8] == 'P') {
        if (h != 12)
            h = (h + 12) % 24;
    }
    else if (h == 12)
        h = 0;
    
    printf("%02d:%02d:%02d", h, m, s);
    
    return 0;
}
