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


void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i; // gan pos cho vi tri dau tien
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
            {
                pos = j; // gan pos cho vi tri ma phan tu nho nhat dang dunng
            }
            
        }
        swap(a[i], a[pos]);
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
    SelectionSort(a, n);
    Test(a, n);
    system("pause");
    return 0;
}