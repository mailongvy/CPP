#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main() {
    string s = "";
    int n;
    cout << "Nhap n: ";
    cin >> n;
    while (n>0)
    {
        s = s + char(n%2 + 48);
        n = n/2;
    }
    reverse(s.begin(), s.end());
    cout << s;
    system("pause");
    return 0;
}