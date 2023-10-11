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

/*
ham heap sort dc dung nhu sap xep cac phan tu tren mot cay
ham heaplify nham bien doi cac phan tu lon nhat len root
*/
void heaplify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] >= a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] >= a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heaplify(a, n, largest);
    }
}    

void HeapSort(int a[], int n) {
    // build ham max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heaplify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heaplify(a, i, 0);
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
        a[i] = rand() % 1000;

    }
    Test(a, n);
    system("pause");
    HeapSort(a, n);
    Test(a, n);
    
    return 0;
}