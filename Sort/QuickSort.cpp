#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
// ============================= PHAN HOACH LOMUTO ==============================================
// ham partition co nhiem vu phan hoach doan tu left cho den right
int partition(int a[], int l, int r) {
    int pivot = a[r]; // lap mot cai chot la phan tu ben phai cung
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i = i + 1;
            swap(a[i], a[j]);
        }
        
    }
    // dua chot ve giua 
    // ssao cho cac phan tu nho hon chot la nam trai con phan tuu lon hon chot nam phai
    ++i;
    swap(a[i], a[r]);
    return i;

}

void quicksort(int a[], int l, int r) {
    if (l >= r)
    {
        return;
    }
    else
    {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
    
    
}

// ============================ PHAN HOACH HOARE ======================================
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
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }
    Test(a, n);
    system("pause");
    quicksort2(a, 0, n - 1);
    Test(a, n);
    return 0;
}