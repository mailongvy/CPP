#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s); 
        map<string, int> mp;
        stringstream ss (s);
        string word;
        while(ss >> word) {
            mp[word]++;
        }
        string res; int fre = 0;
        for (map<string, int>:: iterator it = mp.begin(); it != mp.end(); it++)
        {
            if((*it).second > fre) {
                fre = (*it).second;
                res = (*it).first;
            }
        }
        cout << res << " " << endl;
        
    }
    
    return 0;
}