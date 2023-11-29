#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct node
{
    int key;
    int value;
    node *next;

    node() : key(0), value(0), next(NULL){}
    node(int &key, int &value) : key(key), value(value), next(NULL){}
    node(node &data) :  key(data.key), value(data.value), next(data.next){}
};


class Hashing
{
private:
    vector<node*> table;
    int count;
public:
    Hashing(int m) : count(0) 
    {
        table.resize(m);
        for (int  i = 0; i < m; i++)
        {
            table[i] = NULL;
        }
    } 
    int HashFunction(int &key);
    void InsertNode(node *&data);
    void DeleteNode(int &key);
    int Search(int &key);
    void DisplayTable();
    int GetterCount() {
        return this->count;
    }
};

int Hashing::HashFunction(int &key) {
    return key % table.size();
}

void Hashing::InsertNode(node *&data) {
    int index = HashFunction(data->key);
    if(index >= table.size()) {
        table.push_back(data);
    }
    if (table[index] == NULL)
    {
        table[index] = data;
    }
    else
    {
        node* next = table[index]->next;
        table[index]->next = data;
        data->next = next;
    }
}

void Hashing::DeleteNode(int &key) {
    int index = HashFunction(key);
    node *cur = table[index]; // use pointer to traversal in list
    node *prev = NULL;
    /*3 cases:
    1: not found in table
    2: the first node in table
    3: the node is found at other pos in list
    */
   while (cur != NULL && cur->key != key)
   {
        prev = cur;
        cur = cur->next;
   }

   if (cur == NULL) {
        cout << "\nData not found";
        system("pause");
        return;
   }

   else {
        if (prev == NULL) {
            table[index] = cur->next;
        }
        else {
            prev->next = cur->next;
        }
        delete cur;
   }
   
}

int Hashing::Search(int &key) {
    int index = HashFunction(key);
    node* cur = table[index];
    while (cur != NULL)
    {
        if(cur->key == key) {
            return cur->value; 
        }
        cur = cur->next;
    }
    return -1111;
}

void Hashing::DisplayTable() {
    for (int i = 0; i < table.size(); i++)
    {
        cout << "\nSlot " << i << ": ";
        node* cur = table[i];
        while (cur != NULL)
        {
            cout << "("<< cur->key << "," << cur->value <<") --> ";
            cur= cur->next;
        }
        cout << endl;
    }
    cout << endl;
    
}


void Menu(Hashing &table) {
    int choice;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t==================HASH TABLE=====================";
        cout << "\n\t1. InsertNode";
        cout << "\n\t2. DeleteNode";
        cout << "\n\t3. SearchNode";
        cout << "\n\t4. DisplayHashtable";

        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            int k;
            cout << "\nNhap key ban can lua tru: ";
            cin >> k;
            int v;
            cout << "\nNhap gia tri cho node ban can dua vao mang";
            cin >> v;
            node* newnode = new node(k, v);
            table.InsertNode(newnode);
        }

        else if(choice == 2) {
            int k;
            cout << "\nNhap khoa ban can xoa: ";
            cin >> k;
            table.DeleteNode(k);
        }
        else if (choice == 3) {
            int k;
            cout << "\nNhap khoa can tim: ";
            cin >> k;
            cout << table.Search(k);
            system("pause");
        }

        else if (choice == 4) {
            table.DisplayTable();
            system("pause");
        }
    }
}


int main() {
    int m;
    cout << "\nNhap size cho table: ";
    cin >> m;
    Hashing table(m);
    Menu(table);
    return 0;
}