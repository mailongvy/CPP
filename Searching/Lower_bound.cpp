#include<bits/stdc++.h>
#include<algorithm>
// ham lower_bound dc dung cho mang hoac vecto dc sap xep
// ham lower_bound(iter1, iter2. key) => tra ve phan tu dau tien cos gia tri >= key
// ham upper_bound(iter1, iter2, key) => tra ve phan tu dau tien co gia tri > key
using namespace std;
int main() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    //tim vi tri dau tien cua phan tu >= x co trong mang a
    int *it = lower_bound(a, a + n, x);
    cout << it << endl;
    cout << it - a << endl;
    
    return 0;
}