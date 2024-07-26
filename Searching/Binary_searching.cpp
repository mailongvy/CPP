#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool ls(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}

// binary search (O(logn))
// cac phan tu phai dc sawp xep
// c1: cach binh thuong linear search
bool Bs(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
        {
            return true;
        }
        else if (a[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return false;
}

// c2: dung de quy
bool Binary_search(int a[], int l, int r, int x) {
    if (l > r)
    {
        return false;
    }
    int m = (l + r) / 2;
    if (a[m] == x)
    {
        return true;
    }
    else if (a[m] > x)
    {
        return Binary_search(a, l, m - 1, x);
    }
    else
    {
        return Binary_search(a, m + 1, r, x);
    }
    
}
// tim vi tri dau tien cua 1 phan tu x trong mot mang da sap xep
/*
10 3
1 2 2 2 3 3 3 3 3 4 
*/
int first_pos(int a[], int l, int r, int x) {
    int res = - 1;
    while (l <= r)
    {
        int m = (l + r)/2;
        if (a[m] == x)
        {
            res = m;
            // tip tuc tim ben trai xem con phan tu nao = x ko 
            r = m - 1;
            // neu nhu tim phan tu cui cung thi l = m + 1
        }
        else if (a[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return res;
}
int main() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << first_pos(a, 0, n - 1, x);
    system("pause");
    
    
    return 0;
}