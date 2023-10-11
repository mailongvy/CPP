#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        map<long long, int> mp;
        for (int i = 0; i < n; i++)
        {
            long long x; cin >> x;
            mp[x]++;
        }
        long long res, fre = 0;
        for (map<long long, int> :: iterator it = mp.begin(); it != mp.end(); it++)
        {
            if ((*it).second > fre)
            {
                fre = (*it).second;
                res = (*it).first;
            }
            
        }
        cout << res << " " << fre;
    }
    
    return 0;
}