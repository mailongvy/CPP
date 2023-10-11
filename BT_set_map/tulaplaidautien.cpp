#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s); 
        set<string> se;
        stringstream ss (s);
        string word;
        vector<string> v; 
        while(ss >> word) {
            v.push_back(word);
        }
        for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        {
            if (se.find((*it)) != se.end())
            {
                cout << (*it) << endl;
                break;
            }
            se.insert((*it));
        }
        
        
    }
    
    return 0;
}