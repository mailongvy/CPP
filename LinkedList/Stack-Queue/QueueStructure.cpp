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
/*Nhap danh sach queue chua cac so nguyen, r xuat ra man hinh cac so nguyen do*/
// ======================================= QUEUE ==========================================
// khai bao cau truc 1 node
struct node
{
    int data; // bien kieu so nguyen
    node* pNext;
};

// ham tao mot node
node* CreateNode(int &privatedata) {
    node* p = new node();
    p->data = privatedata;
    p->pNext = NULL;
    return p;
}

// khai bai cay truc cua queue
struct queue
{
    node* pHead; // dung con tro dau de quan li queue
    node* pTail;
};

// ham khoi tao queue
void CreateQueue(queue &Queue) {
    Queue.pHead = NULL;
    Queue.pTail = NULL;
}

// ham kiem tra co rong hay khong
bool IsEmpty(queue &q) {
    // neu danh sach rong dua ve gia tri true
    if (q.pHead ==  NULL)
    {
        return true;
    }

    return false;
    
}

// ham them mot doi tuong vao dau stack - LIFO
bool Push(queue &q, node* &p) {
    if (p == NULL)
    {
        return false;
    }
    
    if (IsEmpty(q) == true)
    {
        q.pHead = q.pTail = p; // p chinh la queue
    }
    else {
        q.pTail->pNext = p;
        q.pTail = p;
    }

    return true;
}

// ham lay mot phan tu dau cua queue tra ve gia tri cua doi tuong dau queue va huy no di
bool Pop(queue &q, int &x) { // x chinh la gia tri can lay trong queue
    if (IsEmpty(q) == true)
    {
        return false;
    }
    else {
        node* p = q.pHead;
        x = p->data; // gan gia tri dau queue vao bien x
        q.pHead = q.pHead->pNext;
        delete p;
    }
    return true; // lay ptu dau queue thanh cong 
}

// xem thong tin cua phan tu dau queue ma ko huy node di 
bool Top(queue &q, int &x) { // x chinh la gia tri can lay ra de xem
    if(IsEmpty(q) == true) {
        return false;
    }
    x = q.pHead->data;
    return true;
}

// ham xuat queue ra man hinh
void Xuat_Queue(queue q) {
    while (IsEmpty(q) == false)
    {
        int x;
        Pop(q, x);
        cout << x << " ";  
    }

    if (IsEmpty(q) == true)
    {
        cout << "\nKhong co phan tu trong queue";
    }
    else {
        cout << "\nDanh sach da ton tai phan tu";
    }
    
    
    
}

// ham nhap danh sach cac so  nguyen  trong queue
void NhapQueue(queue &q) {
    int luachon;
    while(true) {
        system("cls");
        cout << "\n\n\t\t ==================== MENU ====================";
        cout << "\n\t\t1. THEM PHAN TU VAO QUEUE - Push";
        cout << "\n\t\t2. XUAT DANH SACH STACK";
        cout << "\n\t\t3. XEM THONG TIN PHAN TU DAU";
        cout << "\n\t\t0. EXIT";
        cout << "\n\n\t\t ==================== END =====================";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            int x;
            cout << "\nNhap phan tu can them: ";
            cin >> x;
            node* p = CreateNode(x);
            Push(q, p);
        }

        else if (luachon == 2)
        {
            Xuat_Queue(q);
            system("pause");
        }

        else if (luachon == 3)
        {
            int x;
            Top(q, x);
            cout << "\nPhan tu dau trong queue la: " << x;
            system("pause");
        }
        
        
        else {
            break;
        }
        
    }
}

int main () {
    queue q;
    CreateQueue(q);
    NhapQueue(q);
    system("pause");
    return 0;
}