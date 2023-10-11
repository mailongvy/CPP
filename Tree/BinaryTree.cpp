#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
/*
Đề bài: nhập vào ccaay nhị phân cacs số nguyên. Xuất ra màn hình các số nguyên đ
*/
// khai báo cấu trúc của cây nhị phân đó

/*
tìm kiếm cây nhị phân
xuất các node có 2 con (có tồn tại cây con trái và cây con phải)
xuất các node có 1 con (có tồn tại cây con trái hoặc cây con phải)
xuất các node lá (node ko tồn tại cây con trái và cây con phải)
tim node mang giá trị min max trong cây nhị phần 
xoá 
*/
struct node
{
    int data; // dữ liệu của node
    node* right; // node bên phải <=> cây con phải
    node* left;// ndoe bên trái <=> cay con trái
};
typedef node* tree;

void CreateTree(tree &t) {
    t = NULL;

}

// hàm thêm phân tử vào cây
void Addnode(tree &t, int x) {
    // nếu cây rỗng
    if (t == NULL)
    {
        node* p = new node; // khởi tạo 1 node để thêm vào cây
        p->data = x; // thêm dữ liệu cho node
        p->left = NULL;
        p->right = NULL;
        t = p; // node p chính là node gốc (root)
    }
    else // cây có phân tại phần tử
    {
        if (t->data > x )// nếu phân tử thêm vào nhỏ hơn node gốc <=> thêm vào bên trái
        {
            Addnode(t->left, x);// duyệt qua trái để thêm phân tử x
        }
        else if (t->data < x) // nếu phân tử thêm vào lớn hơn node gốc <=> thêm vào bên phải
        {
            Addnode(t->right, x);// duyệt qua phải để thêm phân tử x
        }
    }
}

// ham xuat cay nhi phan theo NLR
void NLR(tree t) {
    if (t != NULL)
    // nếu cây nhị phân còn phần tử thi tiếp tụcc duyệt các phần tử
    {
        cout << t->data << " ";// xuat du lieu trong node
        NLR(t->left);
        NLR(t->right);
    }
    
}

// tim kiem node nếu tồn node có giá trị cần tìm thì trả về node đó, nếu ko có thì trả về null
tree BSTsearch(tree t, int k) {
    // neu cay rong hoac node goc co gia tri = k thi tra ve node goc 
    if (t == NULL || t->data == k)
    {
        return t;
    }
    else
    {
        if (k < t->data)
        {
            BSTsearch(t->left, k);
        }
        else
        {
            BSTsearch(t->right, k);
        }
        
    }
    
    
}

// ham xuat ra cac node co 2 con
void Node_2_Child(tree t) {
    if (t != NULL)
    {
        // xử lí
        if (t->left != NULL && t->right != NULL)
        {
            cout << t->data << " ";
        }
        
        Node_2_Child(t->left);
        Node_2_Child(t->right);
    }
    
}

// ham xuat ra cac node co 1 con
void Node_1_Child(tree t) {
    if (t != NULL)
    {
        // xử lí
        if ((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
        {
            cout << t->data << " ";
        }
        
        Node_1_Child(t->left);
        Node_1_Child(t->right);
    }
}

// ham xuat ra cac node la
void Node_Leaf(tree t) {
    if (t != NULL)
    {
        // xử lí
        if ((t->left == NULL && t->right == NULL))
        {
            cout << t->data << " ";
        }
        
        Node_Leaf(t->left);
        Node_Leaf(t->right);
    }
}

// hàm tìm node có giá trị lớn nhất trong cây
node* MAX_NODE(tree t) {
    if (t->right == NULL)
    {
        return t;
    }
    else
    {
        return MAX_NODE(t->right);
    }
}

// hàm tìm node có giá trị nhỏ nhất trong cây
node* MIN_NODE(tree t) {
    if (t->left == NULL)
    {
        return t;
    }
    else
    {
        return MIN_NODE(t->left);
    }
}


// hàm nhap du lieu
void Menu(tree &t) {
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ================== MENU ====================";
        cout << "\n\t1. Nhap du lieu";
        cout << "\n\t2. Xuat du lieu";
        cout << "\n\t3. Tim kiem cay nhi phan";
        cout << "\n\t4. Node co 2 con";
        cout << "\n\t5. Node co 1 con";
        cout << "\n\t6. Node la";
        cout << "\n\t7. Node co gia tri lon nhat";
        cout << "\n\t0. EXIT";
        cout << "\n\n\t\t =================== END =====================";
        
        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 0)
        {
            break;
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\nNhap so nguyen x can nhap vao cay: ";
            cin >> x;
            Addnode(t,x);
        }
        else if (luachon == 2)
        {
            cout << "\n\t\tDuyet cay theo NLR: ";
            NLR(t);
            system("pause");
        }

        else if (luachon == 3)
        {
            int x;
            cout << "\n\tNhap phan tu can tim kiem: ";
            cin >> x;
            node *p = NULL;
            p = BSTsearch(t, x);
            if (p == NULL)
            {
                cout << "\nKhong ton tai";
                system("pause");
            }
            else
            {
                cout << "\nTon tai";
                system("pause");
            }
        }

        else if (luachon == 4) {
            cout << "\n\t NODE CO 2 CON: ";
            Node_2_Child(t);
            system("pause");
        }

        else if (luachon == 5)
        {
            cout << "\n\tNODE CO 1 CON: ";
            Node_1_Child(t);
            system("pause");
        }

        else if (luachon == 6)
        {
            cout << "\n\tNODE LA: ";
            Node_Leaf(t);
            system("pause");
        }

        else if (luachon == 7)
        {
            cout << "\n\tNODE CO GIA TRI LON NHAT: ";
            cout << MAX_NODE(t)->data;
            system("pause");
        }
        
        
        
        
    }
    
}


int main() {
    tree t;
    CreateTree(t);
    Menu(t);
    system("pause");
    return 0;

}