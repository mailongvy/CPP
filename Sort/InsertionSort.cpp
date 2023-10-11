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

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++)
    {
        // lay ra phan tu a[i]
        int x = a[i];
        int pos = i - 1;
        while ((pos >= 0) && (a[pos] > x))
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x; 
    }
    
}

void Test(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}

int main() {
    int n = 10;
    int a[n] = {1, 8, 6, 100, 15, 4, 7, 2, 65, 77};
    InsertionSort(a, n);
    Test(a, n);
    system("pause");
    return 0;
}
