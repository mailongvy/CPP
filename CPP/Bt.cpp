#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// ============================ PHAN HOACH HOARE ======================================
int partitionoddeven(int a[], int l, int r) {
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (a[i] % 2 == 0);
        do
        {
            --j;
        } while (a[j] % 2 == 1);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            return j;
        }
        
    }
    
}

// sap xep 
int hoarepartition(int a[], int l, int r) {
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (a[i] < pivot);
        do
        {
            --j;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            return j;
        }
        
        
    }
    
}

void quicksort2(int a[], int l, int r) {
    if (l >= r)
    {
        return;
    }
    else {
        int p = hoarepartition(a, l, r);
        quicksort2(a, l, p);
        quicksort2(a, p + 1, r);
    }
    
}

void sort(int a[], int l, int r) {
    int k = partitionoddeven(a, l, r);
    quicksort2(a, l, k);
    quicksort2(a, k + 1, r);
}



void Test(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}


int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Test(a, n);
    system("pause");
    sort(a, 0, n - 1);
    Test(a, n);
    system("pause");

    return 0;
}