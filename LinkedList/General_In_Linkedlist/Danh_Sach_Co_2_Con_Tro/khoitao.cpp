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
//=========== khai bao cau truc danh sach lien ket don cac so nguyen =================  
// khai bao struct node
struct node
{
    int data; // du lieu cua node (có thể là kiểu dữ liệu khác)
    struct node *pNext; // con trỏ để liên kết các con trỏ với nhau
};

// // khai bao cau truc danh sach lien ket don 
// // co the khai bao duy nhat con tro phead
// // cái danh sách liên kết được quản lí bởi hai con trỏ là con trỏ đầu và con trỏ cuối danh sách
struct list
{
    node *pHead;// node quan li dau danh sach
    node *pTail;// node quan li cuoi danh sach
};

//==================== khoi tao danh sach lien ket don cac so nguyen =====================
void CreateList(list &l) {
    // cho hai con trỏ trỏ đến null do danh sách liên kết đơn ch có ptu

    l.pHead = NULL;
    l.pTail = NULL;
}

// ham tao ra 1 cai node
node* CreateNode(int privatedata) {
    node *p = new node; // cap phat vung nho cho node p (tất cả các node cần được cấp phát vùng nhớ)
    p->data = privatedata; // truyen gia trij cua privatedata cho data trong node
    p->pNext = NULL;// khi khai báo node thì node này ch liên kết một node khác => con trỏ thuộc node này phải trỏ đến null
    return p;
}

// ham them node vao dau danh sach lien ket 
void AddHead(list &l, node *p) {
    if (l.pHead == NULL) // danh sach lien ket dang rong (torng danh sach ko co ptu)
    {
        l.pHead = l.pTail = p;

    }
    else // danh sach da co ptu 
    {
        p->pNext = l.pHead;// cho con tro cua node can them (la node p) lien ket den node dau (phead)
        l.pHead = p;// cap nhat lại list (phead là node p)
    }
}

// ham them node vao cuoi danh sach lien ket
void AddTail(list &l, node *p) {
    if (l.pHead == NULL) // danh sach lien ket dang rong (torng danh sach ko co ptu)
    {
        l.pHead = l.pTail = p;

    }
    else // danh sach da co ptu 
    {
        l.pTail->pNext = p;// cho con tro ptail lien ket voi node p
        l.pTail = p;// cap nhat lại list (ptail là node p) 
    }
}

// ham xuat danh sach lien ket don

void PrintList(list &l) {
    for (node* i = l.pHead; i == NULL; i = i->pNext)
    {
        cout << i->data;
    }
    
}

int main() {
    list l;
    CreateList(l);// khoi tao danh sach lien ket don 

    int n;
    cout << "\nNhap so luong node can them: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "\nNhap gia tri so nguyen: ";
        cin >> x;
        node *p = CreateNode(x); 
        
        AddHead(l, p);// them node p vaof dau danh sach lien ket don

    }
    cout << "\n\n\t\t ========= DANH SACH LIEN KET DON =============\n";
    PrintList(l);
    system("pause");
    
    return 0;
}
