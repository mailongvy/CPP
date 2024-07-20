#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void Input(vector<vector<int>> &a, int n, int m ) {
    
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cout << "Nhap so can nhap vao ma tran tai hang " << i + 1 << " cot " << j + 1 << ": ";
            cin >> x;
            temp.push_back(x);
        }
        a.push_back(temp);
        
    }
}

void output(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
}

double sum (vector<vector<int>> &a, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            if(a[i][j] % 2 == 0)
                sum += a[i][j];
        }
        
    }
    return sum;
    
}

int Phantuduongnhonhat (vector<vector<int>> &a, int n, int m) {
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j] > 0 && a[i][j] < min)
                min = a[i][j];
        }
            
    }
    return min;

}

void sapxep(vector<int> &a, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i] < a[j])
                swap(a[i], a[j]);
        }
        
    }
    
}
int main() {
    vector<vector<int>> a;
    int n, m;
    cout << "Nhap so hang va so cot";
    cin >> n >> m;
    Input(a, n, m);
    output(a);
    return 0;
}