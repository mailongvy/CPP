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
using namespace std;
// struct node
struct node
{
    int data;
    node* pNext;
};

node* CreateNode(int privatedata) {
    node* p = new node;
    p->data = privatedata;
    p->pNext= NULL;
    return p;
}

void AddHead(node* &pHead, node* p) {
    if (pHead == NULL)
    {
        pHead = p;
    }
    else
    {
        p->pNext = pHead;
        pHead = p;
    }
}

void AddTail(node* &pHead, node* p) {
    if (pHead == NULL)
    {
        pHead = p;
    }
    else
    {
        for (node* i = pHead; i != NULL; i = i->pNext)
        {
            if (i->pNext == NULL)
            {
                i->pNext = p;
                break;
            }
        }
    }
}

void Xuat_Danh_Sach(node* pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << " ";
    }
}

void FreeMemory(node* &pHead) {
    node* k = NULL;
    while (pHead != NULL)
    {
        k = pHead;
        pHead = pHead->pNext;
        delete k;
    }
    
}

void Doc_File_So_Nguyen(node* &pHead, ifstream &filein, int &n) {
    
    for (int i = 0; i < n; i++)
    {
        int x;
        filein >> x;
        node* p = CreateNode(x);
        AddTail(pHead, p);
    }
    
}

// ktra so chinh phuong
bool Ktra_So_Chinh_Phuong(int x) {
    for (int i = 0; i*i <= x; i++)
    {
        if (i*i == x)
        {
            return true;
        }
        
    }
    return false;
}

// xuat cac so chinh phuong
void Xuat_So_Chinh_Phuong(node* pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        if (Ktra_So_Chinh_Phuong(i->data))
        {
            cout << i->data << " ";
        }
        
    }
    
}

// tim so lon nhat co trong danh sach lien key don
int Max(node* pHead) {
    int max = 0;
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        if (max <= i->data)
        {
            max = i->data;
        }
        
    }
    return max;
}

// ghi so lon nhat
void Ghi_So_Lon_Nhat(node* &pHead, ofstream &fileout) {
    fileout << Max(pHead);
}

// ham sap xep tang dan
void Sap_Xep_Tang(node* &pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        for (node* j = i->pNext; j != NULL; j = j->pNext)
        {
            if (i->data >= j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            
        }
        
    }
    
}

// ham ghi day tang dan vao file
void Ghi_File_Tang_Dan(node* pHead, ofstream &fileout, int n) {
    Sap_Xep_Tang(pHead);
    fileout << n << endl;
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        fileout << i->data << " ";
    }
    
}
// menu
void Menu(node* &pHead, ifstream &filein, int n) {
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t================ DANH SACH CAC SO NGUYEN =================";
        cout << "\n\t\t1. Xuat cac so nguyen co trong danh sach";
        cout << "\n\t\t2. Xuat cac so chinh phuong co trong danh sach";
        cout << "\n\t\t3. Ghi file max vao output.txt";
        cout << "\n\t\t4. Sap xep theo thu tu tang dan cac phan tu";
        cout << "\n\t\t0. EXIT";
        cout << "\n\n\t\t========================= END =============================";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            Xuat_Danh_Sach(pHead);
            system("pause");
        }
        else if (luachon == 2)
        {
            Xuat_So_Chinh_Phuong(pHead);
            system("pause");
        }
        else if (luachon == 3)
        {
            ofstream fileout;
            fileout.open("OUTPUT.txt", ios_base::out);
            Ghi_So_Lon_Nhat(pHead, fileout);
            fileout.close();
        }
        else if(luachon == 4) {
            ofstream fileout;
            fileout.open("Ketqua.txt", ios_base::out);
            Ghi_File_Tang_Dan(pHead, fileout, n);
            fileout.close();     
        }
        
        else {
            break;
        }
        
        
    }
    
}
int main() {
    node* pHead = NULL;
    int n;
    ifstream filein;
    filein.open("INPUT.txt", ios_base::in);
    
    filein >> n;
    Doc_File_So_Nguyen(pHead, filein, n);
    
    
    Menu(pHead, filein, n);
    // cout << Max(pHead);

    filein.close();
    
    FreeMemory(pHead);
    system("pause");
    return 0;
}