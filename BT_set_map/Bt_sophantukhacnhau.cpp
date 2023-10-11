#include<bits/stdc++.h>
using namespace std;
void SET(int n) {
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size();
}
void MAP(int n) {
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x] = true;
    }
    cout << mp.size();
}
int main() {
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        SET(n);
    }
    
    return 0;
}
