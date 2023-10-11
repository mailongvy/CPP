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

// cau truc node
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

// ham them vvao dau
void AddHead(node* &pHead, node* p) {
    if (pHead == NULL)
    {
        pHead = p;
    }
    else {
        p->pNext = pHead;
        pHead = p;
    }
}

// ham them vao cuoi
void AddTail(node* &pHead, node* p) {
    if (pHead == NULL)
    {
        pHead = p;
    }
    else {
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

// ham xuat danh sach lien ket
void Xuat_Danh_Sach(node* pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << " ";
    }
    
}

// ham giai phong vung nho
void FreeMemory(node* &pHead) {
    node* k = NULL;
    while (pHead != NULL)
    {
        k = pHead;
        pHead = pHead->pNext;
        delete k;
    }
}

// ham sap xep danh sach giam dan
void Sap_Xep_Giam_Dan(node* &pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        for (node* j = i->pNext; j != NULL; j = j->pNext)
        {
            if (i->data <= j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data =temp;
            }
        }
    }
}

// ham ktra co phai so ddoi xung k
bool Ktra_So_Doi_Xung(int n) {
    int sodaonguoc;
    int tam = n;

    if (n < 0)
    {
        return false;
    }
    
    else if (n>= 0 && n <= 9) {
        return true;
    }
    else {
        while (n != 0)
        {
            sodaonguoc = sodaonguoc * 10 + (n % 10);
            n /= 10;
        }
        
        if (sodaonguoc == tam)
        {
            return true;
        }
        
    }
    return false;
}

// ham xuat cac so dooi xung
void Xuat_Cac_So_Doi_Xung(node* pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        if (Ktra_So_Doi_Xung(i->data))
        {
            cout << i->data << " ";
        }
        
    }
    
}

// xoa phan tu co khoa k bat ki
void DeleteRandomly(node* &pHead, int x) {
    if (pHead == NULL)
    {
        return;
    }
    else {
        node* g = NULL;
        for (node* i = pHead; i != NULL; i = i->pNext)
        {
            if (i->data == x)
            {
                g->pNext = i->pNext;
                delete i;
                break;
            }
            g = i;
        }
        
    }
    
}
// void menu
void Menu(node* pHead) {
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ========================== QUAN LY DANH SACH LIEN KET DON =====================";
        cout << "\n\t\t1. Them phan tu vao danh sach";
        cout << "\n\t\t2. Xuat danh sach";
        cout << "\n\t\t3. Sap xep danh sach giam dan";
        cout << "\n\t\t4. Xuat cac so la so doi xung";
        cout << "\n\t\t5. Xoa phan tu  vi tri bat ki";
        cout << "\n\n\t\t =================================== END =======================================";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            int x;
            cout << "\nNHap phan tu can them: ";
            cin >> x;
            node* p = CreateNode(x);
            AddTail(pHead, p);
        }

        else if (luachon == 2)
        {
            cout << "\n\t DANH SACH LIEN KET\n";
            Xuat_Danh_Sach(pHead);
            system("pause");
        }

        else if (luachon == 3)
        {
            Sap_Xep_Giam_Dan(pHead);

        }

        else if (luachon == 4)
        {
            Xuat_Cac_So_Doi_Xung(pHead);
            system("pause");
        }

        else if (luachon == 5)
        {
            int x;
            cout << "\nNhap khoa k can xoa: ";
            cin >> x;
            DeleteRandomly(pHead, x);
        }
        
        
        
        
    }
    
}




int main() {
    node* pHead = NULL;
    Menu(pHead);
    system("pause");
    return 0;
}