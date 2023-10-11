#include<bits/stdc++.h>
using namespace std;
// c1: sử dụng sắp xếp r dùng binary search để tim phan tu
void Mang(int n) {
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    // so luong truy van
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if(binary_search(a, a + n, x)) {
            cout << "\nYES";
        }
        else
        {
            cout << "\nNO";
        }
        
    }
    
}

// c2: dùng set
void Set(int n) {
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    int q; cin >> q;
    while (q--)
    {
        int y; cin >> y; 
        if(s.count(y) != 0) {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        
    }
}

// c3: dung map
void Map(int n) {
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x] = true;
    }
    int q; cin >> q;
    while (q--)
    {
        int y; cin >> y; 
        if(mp.count(y) != 0) {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        
    }
}
int main() {
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        Map(n);
    }
    return 0;
}