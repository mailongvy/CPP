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
/*Nhap danh sach stack chua cac so nguyen, r xuat ra man hinh cac so nguyen do*/
using namespace std;

// ======================================= STACK ==========================================
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

// khai bai cay truc cua stack
struct stack
{
    node* pTop; // dung con tro dau de quan li stack
};

// ham khoi tao Stack
void CreateStack(stack &Stack) {
    Stack.pTop = NULL;
}

// ham kiem tra co rong hay khong
bool IsEmpty(stack &s) {
    // neu danh sach rong dua ve gia tri true
    if (s.pTop ==  NULL)
    {
        return true;
    }

    return false;
    
}

// ham them mot doi tuong vao dau stack - LIFO
bool Push(stack &s, node* &p) {
    if (p == NULL)
    {
        return false;
    }
    
    if (IsEmpty(s) == true)
    {
        s.pTop = p; // p chinh la stack
    }
    else {
        p->pNext = s.pTop;
        s.pTop = p; // cap nhat lai danh sach stack(ngan xep)
    }

    return true;
}

// ham lay mot phan tu dau cua stack tra ve gia tri cua doi tuong dau stack va huy no di
bool Pop(stack &s, int &x) { // x chinh la gia tri can lay trong stack
    if (IsEmpty(s) == true)
    {
        return false;
    }
    else {
        node* p = s.pTop;
        x = p->data; // gan gia tri dau stack vao bien x
        s.pTop = s.pTop->pNext;
        delete p;
    }
    return true; // lay ptu dau stack thanh cong 
}

// xem thong tin cua phan tu dau stack ma ko huy node di 
bool Top(stack &s, int &x) { // x chinh la gia tri can lay ra de xem
    if(IsEmpty(s) == true) {
        return false;
    }
    x = s.pTop->data;
    return true;
}

// ham xuat stack ra man hinh
void Xuat_Stack(stack s) {
    while (IsEmpty(s) == false)
    {
        int x;
        Pop(s, x);
        cout << x << " ";  
    }

    if (IsEmpty(s) == true)
    {
        cout << "\nKhong co phan tu trong stack";
    }
    else {
        cout << "\nDanh sach da ton tai phan tu";
    }
    
    
    
}

// ham nhap danh sach cac so  nguyen 
void NhapStack(stack &s) {
    int luachon;
    while(true) {
        system("cls");
        cout << "\n\n\t\t ==================== MENU ====================";
        cout << "\n\t\t1. THEM PHAN TU VAO STACK";
        cout << "\n\t\t2. XUAT DANH SACH STACK";
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
            Push(s, p);
        }

        else if (luachon == 2)
        {
            Xuat_Stack(s);
            system("pause");
        }
        
        else {
            break;
        }
        
    }
}

int main () {
    stack s;
    CreateStack(s);
    NhapStack(s);
    system("pause");
    return 0;
}