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

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
            
        }
        
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
        BubbleSort(a, n);
        Test(a, n);
        system("pause");
        return 0;
    }