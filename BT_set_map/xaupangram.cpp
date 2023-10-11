#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        set<char> se;
        for (int i = 0; i < s.length(); i++)
        {
            se.insert(tolower(s[i]));
        }
        if (se.size() == 26)
        {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }
    return 0;
}