// them 1 node p vao sau node q
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

/*
nhập danh sách liên kết đơn các số nguyên. Tìm giá trị lớn nhất trong dánh sách
*/
//=========== khai bao cau truc danh sach lien ket don cac so nguyen ===================
// khai bao struct node

int n = 0; // bien toan cuc chi so luong node co trong danh sach lien ket
struct node
{
    int data; // gia tri cua node
    node *pNext; // con tro de tro den gia tri tip theo trong danh sach lien ket
};

// khai bao 1 danh sach lien ket don gom 2 node: pHead, pTail
struct list
{
    node *pHead; // quan li cac node dau
    node *pTail; // quan li cac node cuui danh sach 
};

// khoi tao danh sach lien ket
void CreateList(list &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// khoi tao node
node* CreateNode(int privatedata) {
    node *p = new node;
    p->data = privatedata;
    p->pNext = NULL;
    return p;
}

// them node vao dau danh sach lien ket
void AddHead(list &l, node *p) {
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }

    else {
        p->pNext = l.pHead; // con tro cua node p nexr tro den p head
        l.pHead = p; // cap nhat lai con tro dau cua danh sach lien ket
    }
    
}

// them node vao cuoi danh sach lien ket
void AddTail(list &l, node *p) {
    if (l.pTail == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// xuat danh sach lien ket don
void Printlist(list &l) {
    for (node* i = l.pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << " ";
    }
    
}

// them node p vao sau node q(nam trong danh sach lien ket don)
void AddNodeAfter_q(list &l, node *p) {
    int x;
    cout << "\nNhap gia tri cho node q: ";
    cin >> x;
    node *q = CreateNode(x);    

    // neu danh sach lien ket chi cos 1 node la node q
    if (q->data == l.pHead->data && q->pNext == NULL)
    {
        AddTail(l, p);
    }

    else {
        // duyet tu dau danh sach den cuoi danh sach de tim node q
        for (node* i = l.pHead; i != NULL; i = i ->pNext)
        {
            // neu q ton tai
            if (q->data == i->data)
            {
                node* h = CreateNode(p->data); // tranh truong hơp trùng node khi danh sách liên kết có nhìu phần tử có nhìu data
                node* g = i->pNext; // cho node g tro den node sau node q
                h->pNext = g; // b1: tao moi lien ket tu node h den node g(node sau node q)
                i->pNext = h; // b2. tao moi lien ket tu node q den node h
            }
            
        }
        
    }
    
}

// them 1 node p truoc node q co trong danh sach lien ket don
void AddNodeBefore_q(list &l, node* p) {
    int x;
    cout << "\nNhap gia tri node q: ";
    cin >> x;
    node* q = CreateNode(x);
    
    if (q->data == l.pHead->data && q->pNext == NULL )
    {
        AddHead(l, p); // them node p vao dau danh sach
    }

    else
    {
        node* g = new node; // node g laf node giu lien ket vs node nam truoc node q co trong danh sach
        // duyet tu dau danh sach den cuoi danh sach
        for (node* i = l.pHead; i != NULL; i = i->pNext)
        {
            // node q co ton tai trong danh sach thi them node p vao truoc node co trong danh sach do
            if (q->data == i->data)
            {
                // thuc hien them node p vao sau node k <=> them node lp namf trc node q
                node* h = CreateNode(p->data);
                h->pNext = i; 
                g->pNext = h;
            }
            g = i; // giu lien ket vs node nam trc cai node q trong danh sach
        }
        
    }
    
    
}

// them node p vao vi tri bat ki (them node p vao vi tri bat ki)
// them node vao vi tri vt
// void AddNodeRandomly(list &l, node *p, int pos, int n)  {
    
    

//     if (l.pHead == NULL || pos == 1)
//     {
//         // them node p vao dau
//         AddHead(l, p);
//     }
//     else if (pos == n + 1)
//     {
//         AddTail(l, p);
//     }
//     // trong doan [2, n] dùng hàm thêm nốt p vào trc node q
//     else {
//         int count; // biến đếm xác định vị trí cần thêm
//         node* g = new node; // node g laf node giu lien ket vs node nam truoc node q co trong danh sach
//         // duyet tu dau danh sach den cuoi danh sach
//         for (node* i = l.pHead; i != NULL; i = i->pNext)
//         {
//             count++;
//             // node q co ton tai trong danh sach thi them node p vao truoc node co trong danh sach do
//             if (count == pos)
//             {
//                 // thuc hien them node p vao sau node k <=> them node lp namf trc node q
//                 node* h = CreateNode(p->data);
//                 h->pNext = i; 
//                 g->pNext = h;
//                 break;
//             }
//             g = i; // giu lien ket vs node nam trc cai node q trong danh sach
//         }
//     }


    
    
// } 

// cach 2:
void AddNodeRandomly(list &l, node *p, int pos)  {
    if (l.pHead == NULL || pos == 1)
    {
        // them node p vao dau
        AddHead(l, p);
    }
    else if (pos == n + 1)
    {
        AddTail(l, p);
    }
    // trong doan [2, n] dùng hàm thêm nốt p vào trc node q
    else {
        int count; // biến đếm xác định vị trí cần thêm
        node* g = new node; // node g laf node giu lien ket vs node nam truoc node q co trong danh sach
        // duyet tu dau danh sach den cuoi danh sach
        for (node* i = l.pHead; i != NULL; i = i->pNext)
        {
            count++;
            // node q co ton tai trong danh sach thi them node p vao truoc node co trong danh sach do
            if (count == pos)
            {
                // thuc hien them node p vao sau node k <=> them node lp namf trc node q
                node* h = CreateNode(p->data);
                h->pNext = i; 
                g->pNext = h;
                break;
            }
            g = i; // giu lien ket vs node nam trc cai node q trong danh sach
        }
    }


    
    
} 

// =============================== XOA NODDE================================================
// xoa dau
void DeleteHead(list &l) {
    if (l.pHead == NULL)
    {
        return;
    }
    else {
        node *p = l.pHead;
        l.pHead = l.pHead->pNext; // cap nhat lai l.phead la phan tu ke tiep
        delete p;
    }
    
}

// xoa cuoi
void DeleteTail(list &l) {
    if (l.pTail == NULL)
    {
        return;
    }
    else {
        for (node* i = l.pHead; i != NULL; i = i->pNext)
        {
            // phat hien node ke cuoi
            if (i->pNext == l.pTail)
            {
                delete l.pTail; // xoa di phan tu cuoi
                i->pNext = NULL;
                l.pTail = i;
            }
            
        }
        
    }
    
}

// ham xoa 1 node nam sau node q trong danh sach
void DeleteAfterQ(list &l, node* q) {
    // duyet tu dau danh sach den cuoi danh sach
    for (node* i = l.pHead; i != NULL; i = i->pNext) 
    {
        // phat hien node q
        if (i->data == q->data)
        {
            node *g = i->pNext; // node g la node sau node i(nam sau node q) <=>la node ta phai xoa
            i->pNext = g->pNext; // cap nhat lai moi lien ket cua cac node co trong danh sach
            delete g; 
        }
        
    }
    
}

// xoa node tai vi tri bat ki
void DeleteNodeRandomly(list &l, int x) {
    // neu node can xoa nam dau danh sach
    if (l.pHead == NULL)
    {
        return;
    }
    
    if (l.pHead->data == x)
    {
        DeleteHead(l);
        return;
    }

    // neu node can xoa nam cuoi danh sach 
    else if (l.pTail->data == x)
    {
        DeleteTail(l);
        return;
    }

    node *g = new node;

    for (node* i = l.pHead; i != NULL; i = i->pNext)
    {
        // phat hien phan tu can xoa
        if (i->data == x)
        {
            g->pNext = i->pNext;
            delete i;
            return;
        }
        g = i;// cap nhat vi tri cho node phia trc node can xoa
    }
}

// ham giai phong vùng nhờ cho danh sách liên kết đơn
void FreeMemory(list &l) {
    node* i = NULL;
    while (i != NULL)
    {
        i = l.pHead;
        l.pHead = l.pHead->pNext;
        delete i;
    }
    
    
}
 
// menu
void Menu(list &l) {
    int luachon;
    while (69)
    {
        system("cls");
        cout << "\n\n\t\t ======================= MENU =========================";
        cout << "\n\t\t1. Them node vao danh sach";
        cout << "\n\t\t2. Xuat danh sach lien ket";
        cout << "\n\t\t3. Them node p vao sau node q";
        cout << "\n\t\t4. Them node p vao trc node q";
        cout << "\n\t\t5. Them node p vao vi tri bat ki";
        cout << "\n\t\t6. Xoa node dau";
        cout << "\n\t\t7. Xoa node cuoi";
        cout << "\n\t\t8. Xoa node sau q";
        cout << "\n\t\t9. Xoa node co vi tri bat ki";
        cout << "\n\t\t0. EXIT";
        cout << "\n\n\t\t ======================== END ==========================";

        cout << "\nMhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            
            int x;
            cout << "\nNhap gia tri so nguyen: ";
            cin >> x;
            node *p = CreateNode(x);
            AddTail(l, p);
            n++;
        }
        
        else if (luachon == 2)
        {
            Printlist(l);
            system("pause");
        }

        else if (luachon == 3)
        {
            int x;
            cout << "\nNhap gia tri cho node p: ";
            cin >> x;
            node *p = CreateNode(x);
            AddNodeAfter_q(l, p);
            n++;
        }

        else if (luachon == 4)
        {
            int x;
            cout << "\nNhap gia tri cho node p: ";
            cin >> x;
            node *p = CreateNode(x);
            AddNodeBefore_q(l, p);
            n++;
        }
        
        
        else if (luachon == 5) {
            // cah 1: 
            // vong lap lay so luong node danh sach
            // int n = 0;
            // for (node* i = l.pHead; i != NULL; i = i->pNext)
            // {
            //     n++; // so luong node
            // }
            int x; 
            cout << "\nNhap gia tri node p can them: ";
            cin >> x;

            node *p = CreateNode(x);

            int pos; // vi tri muon them vao danh sach lien ket
            
            do
            {
                cout << "\nNhap vi tri can them cho node p: ";
                cin >> pos;
                if (pos < 1 || pos > n + 1) {
                    cout << "\nVi tri can them nam trong doan [1, "<< n + 1 <<"]";
                    system("pause");
                }
            } while (pos < 1 || pos > n + 1);
            
            // AddNodeRandomly(l, p, pos, n); c1
            AddNodeRandomly(l, p, pos);
            n++;
        }

        else if (luachon == 6)
        {

            DeleteHead(l);
        }

        else if (luachon == 7)
        {
            DeleteTail(l);
        }

        else if (luachon == 8)
        {
            int x;
            cout << "\nNhap node q";
            cin >> x;
            node *q = CreateNode(x);
            DeleteAfterQ(l, q);
        }

        else if (luachon == 9)
        {
            int x;
            cout << "\nNhap node can xoa: ";
            cin >> x;
            DeleteNodeRandomly(l, x);

        }
        
        
        
        

        else {
            break;
        }
        
    }
     
    
    
}

int main() {
    list l;
    CreateList(l); // luon goi ham khoi tao danh sach lien ket don
    Menu(l);
    FreeMemory(l);
    system("pause");
    return 0;



}