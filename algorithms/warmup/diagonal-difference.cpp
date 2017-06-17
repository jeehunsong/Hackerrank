#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, primaryDiagonal = 0, secondaryDiagonal = 0;
    cin >> n;
    for (int irow = 0 ; irow < n ; ++irow) {
        for (int icol = 0 ; icol < n ; ++icol) {
            int temp;
            cin >> temp;
            if (irow == icol)
                primaryDiagonal += temp;
            if (irow == (n - icol - 1))
                secondaryDiagonal += temp;
        }
    }
    cout << ((primaryDiagonal > secondaryDiagonal)?(primaryDiagonal - secondaryDiagonal):(-primaryDiagonal + secondaryDiagonal));
    
    return 0;
}
