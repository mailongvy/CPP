#include<bits/stdc++.h>
using namespace std;
// c1 dung mang dem 
void Mang() {
    string s;
    getline(cin, s);
    int a[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i]]++;
    }
    char res; int fre = 0;
    for (int i = 0; i < 256; i++)
    {
        if (a[i] > fre)
        {
            fre = a[i];
            res = (char)(i);
        }   
    }
    cout << res << " ";
}

// c2 dung map
void Map() {
    string s;
        getline(cin, s);
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        char res; int fre = 0;
        for (map<char, int>:: iterator it = mp.begin(); it != mp.end(); it++)
        {
            if((*it).second > fre) {
                fre = (*it).second;
                res = (*it).first;
            }
        }
        cout << res;
        
}
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        Map();
    }
    return 0;
}    