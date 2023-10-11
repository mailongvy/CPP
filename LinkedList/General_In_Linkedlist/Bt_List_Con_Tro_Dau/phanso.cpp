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

// nhap danh sach lien ket don cac phan so
// khi danh sach chi co con tro dau
// khai bao cau truc 1 phan so
struct phanso
{
    int tu;
    int mau;
};

// ham nhap phan so
void Nhap_Phan_So(phanso &ps) {
    cout << "\nNhap tu so: ";
    cin >> ps.tu;
    cout << "\nNhap mau so: ";
    cin >> ps.mau;
}

// ham xuat phan so
void Xuat_Phan_So(phanso ps) {
    cout << ps.tu << "/" << ps.mau;
}

// khai bao cau truc 1 node
struct node
{
    phanso data; // du lieu cua mot node
    node* pNext; 
};

// ham khoi tao 1 node
node* CreateNode(phanso privatedata) {
    node* p = new node;
    p->data = privatedata;
    p->pNext = NULL;
    return p; 
}

// struct list
// {
//     node* pHead;
// };

// // ham khai tao
// void CreateList(list &l) {
//     l.pHead = NULL;
// }

// them vao dau
void AddHead(node* &pHead, node* p) {
    // neu danh sach rong  
    if (pHead == NULL)
    {
        pHead = p;
    }
    else {
        p->pNext = pHead;
        pHead = p;// node dau chinh la node vau them vao
    }
}

// them vao cuoi
void AddTail(node* &pHead, node* p) {
    if (pHead == NULL)
    {
        pHead = p;
    }
    else {
        for (node* i = pHead; ; i = i->pNext)
        {
            if (i->pNext == NULL)
            {
                i->pNext = p;
                break;
            }
            
        }
        
    }
    
}

// xoa dau
void DeleteHead(node* &pHead) {
    if (pHead == NULL)
    {
        return;
    }
    else{ 
        node* p = new node;
        p = pHead;
        pHead = pHead->pNext;
        delete p;
    }
    
}

// xoa cuoi
void DeleteTail(node *&pHead)
{
	// danh sách đang rỗng
	if (pHead == NULL)
	{
		return;
	}
	// nếu danh sách tồn tại 1 cá node
	if (pHead->pNext == NULL)
	{
		node *p = pHead; // node p là node thế mạng giữ thằng đầu danh sách thông qua việc trỏ đến thằng pHead
		pHead = NULL;
		delete p; // xóa đi thằng p cũng chính là xóa đi thằng đầu danh sách
		return;
	}
	// đi kiếm cái NODE cuối
	for (node *k = pHead; ;k = k->pNext)
	{
		if (k->pNext->pNext == NULL)
		{
			delete k->pNext;
			k->pNext = NULL;
			break;
		}
	}
}

// ham them 1 node sau 1 node trong danh sach
void AddNode_P_After_Q(node* &pHead, node* p, node* q) {
    if ((q->data.tu == pHead->data.tu) && (q->data.mau == pHead->data.mau) && q->pNext == NULL)
    {
        AddTail(pHead, p);
        return;
    }
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        if (i->data.tu == q->data.tu && i->data.mau == q->data.mau)
        {
            node* h = CreateNode(p->data);
            h->pNext = i->pNext;
            i->pNext = h;

        }
        
    }
    
    
}

// hàm xóa 1 NODE k sau NODE q trong dannh sách - NODE q phải tồn tại thì mới xóa sau
void DeleteNode_P_After_Q(node *&pHead, node *q)
{
	// duyệt danh sách để kiểm tra xem có tồn tại node q hay không
	for (node *l = pHead; l != NULL; l = l->pNext)
	{
        
		if (l->data.tu == q->data.tu && l->data.mau == q->data.mau && l->pNext != NULL)
		{
            node *tam = l->pNext; // Bước 1: nhờ thằng tam giữ dùm địa chỉ của thằng nằm sau node l
			l->pNext = l->pNext->pNext; // Bước 2: cho node l liên kết đến node nằm sau node cần xóa
			delete tam; // Bước 3: xóa đi thằng tam <=> xóa đi thằng nằm sau node
            break;
		}
	}
}

// ham xuat danh sach cac phan so
void Xuat_Danh_Sach_Phan_So(node* pHead) {
    for (node* i = pHead; i != NULL; i = i->pNext)
    {
        Xuat_Phan_So(i->data);
        cout << endl;
    }
    
}


// menu
void Menu(node* pHead) {
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t==================== QUAN LI DANH SACH PHAN SO =======================";
        cout << "\n\t\t1. Nhap phan so";
        cout << "\n\t\t2. Xuat phan so";
        cout << "\n\t\t3. Xoa dau";
        cout << "\n\t\t4. Xoa cuoi";
        cout << "\n\t\t5. Them mot node p sau node q co trong danh sach";
        cout << "\n\t\t6. Xoa mot node sau node q co trong danh sach";
        cout << "\n\t\t0. EXIT";
        cout << "\n\n\t\t============================= END =====================================";

        int luachon;
        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            phanso ps;
            Nhap_Phan_So(ps);
            node* p = CreateNode(ps);
            // AddHead(pHead, p);
            AddTail(pHead, p);
        }

        else if (luachon == 2)
        {
            Xuat_Danh_Sach_Phan_So(pHead);
            system("pause");
        }

        else if (luachon == 3)
        {
            DeleteHead(pHead);
        }

        else if (luachon == 4)
        {
            DeleteTail(pHead);
        }

        else if (luachon == 5)
        {
            phanso x;
            cout << "\nNhap phan so can them: ";
            Nhap_Phan_So(x);
            node *p = CreateNode(x);

            phanso y;
            cout << "\nNhap phan so can tim: ";
            Nhap_Phan_So(y);
            node* q = CreateNode(y);

            AddNode_P_After_Q(pHead, p, q);
        }

        else if (luachon == 6) 
        {
            phanso y;
            cout << "\nNhap phan so can tim: ";
            Nhap_Phan_So(y);
            node* q = CreateNode(y);
            DeleteNode_P_After_Q(pHead, q);
        }
        

        else {
            break;
        }
        
        
        
        
    }
    
}

int main() {
    node* pHead = NULL;
    Menu(pHead);

    system("pause");
    return 0;
}