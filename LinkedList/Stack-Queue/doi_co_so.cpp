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
/*doi 1 so nguyen sang co so 2 8 16*/
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

// ham doi co so 10 thanh 2 8 16
void Chuyen_Co_So(stack &s, int cosocandoi, int hethapphan) {
    while (hethapphan != 0) {
        int x = hethapphan % cosocandoi;
        node* p = CreateNode(x);
        Push(s, p); // them node p vao stack
        hethapphan /= cosocandoi;
    }
}

void Xuat_Stack(stack &s) {
    while (IsEmpty(s) == false)
    {
        int x;
        Pop(s, x);
        if (x < 10)
        {
            cout << x;
        }
        else {
            if (x == 10) {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12) {
                cout << "C";
            }
            else if (x == 13) {
                cout << "D";
            }
            else if (x == 14) {
                cout << "E";
            }
            else if (x == 15) {
                cout << "F";
            }

            
        }
    
        
    }
    
}

int main() {
    stack s;
    CreateStack(s);
    int hethapphan;
    cout << "\nNhap gia tri he thap phan can chuyen: ";
    cin >> hethapphan;

    int cosocandoi;
    cout << "\nNhap co so can doi: ";
    cin >> cosocandoi;

    Chuyen_Co_So(s, cosocandoi, hethapphan);
    Xuat_Stack(s);
    system("pause");
    return 0;
}