#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<int> se;
        for (int i = 0; i < m; i++)
        {
            int x; cin >> x;
            se.insert(x);
        }

        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            if(se.find(a[i]) == se.end()) {
                cout << a[i] << " ";
                ok = true;
            }
        }
        if (!ok) {cout << "Not found";}
        else
        {
            cout << endl;
        }
    }
    return 0;
}