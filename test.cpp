#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define C(a) ((a) * (a) * (a))

int main() {
    int x, y;
    for ( y = 9; y > -6; y--)
    {
        for ( x = -8; x < 9; x++)
        {
            cout << (C(x*x+y*y-25) < 25*x*x*y*y*y ? "*##*"[(x+10)%4] : '-');
        }
        cout << endl;
    }
    system("pause");
    return 0;
}