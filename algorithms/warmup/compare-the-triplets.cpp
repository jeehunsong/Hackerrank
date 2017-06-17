#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int score[2][3], alice = 0, bob = 0;
    for(int i = 0 ; i < 3 ; ++i)   {
        cin >> score[0][i];
    }
    for (int i = 0 ; i < 3 ; ++i) {
        cin >> score[1][i];
        if (score[0][i] > score[1][i]) ++alice;
        else if (score[1][i] > score[0][i]) ++bob;
    }
    
    cout << alice << " " << bob;
    
    return 0;
}
