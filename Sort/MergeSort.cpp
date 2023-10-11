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
void merge(int a[], int l, int m, int r) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            ++l;
            ++i;
        }
        else {
            a[l] = y[j];
            ++l;
            ++j;
        }
        
    }
    while (i < x.size())
    {
        a[l] = x[i];
        ++l;
        ++i;
    }
    while (j < y.size())
    {
        a[l] = y[j];
        ++l;
        ++j;
    }
    
    
}

// ham merge sort
void MergeSort(int a[], int l, int r) {
    if (l >= r)
    {
        return;
    }
    int m = (l + r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    merge(a, l, m, r);
    
}

void Test(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}

int main() {
    int n = 100;
    int a[100];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;

    }
    MergeSort(a, 0, n - 1);
    Test(a, n);
    
    return 0;
}