#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class hashing
{
public:
    node *HT[10];
    hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HT[i] = NULL;
        }
    }

    // hashing function used : modulus method
    int HFunc(int value)
    {
        return (value % 10);
    }

    // creates the nodes
    node *create(int val)
    {
        node *temp;
        temp = new node();
        temp->next = NULL;
        temp->data = val;
        return temp;
    }

    // insert the entered data in the node
    void insert(int val)
    {
        int hash_val = HFunc(val);
        node *temp;
        temp = new node();
        node *head;
        head = new node();
        head = create(val);
        temp = HT[hash_val];
        if (temp == NULL)
        {
            HT[hash_val] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }

    // function display to display the entered data
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            node *temp;
            temp = new node();
            temp = HT[i];
            cout << "\na[" << i << "] : ";
            while (temp != NULL)
            {
                cout << " ->" << temp->data;
                temp = temp->next;
            }
        }
    }

    // search the data through the specified key
    int search(int val)
    {
        bool flag = false;
        int hash_val = HFunc(val);
        node *enter = HT[hash_val];
        while (enter != NULL)
        {
            if (enter->data == val)
            {
                cout << "\nElement " << enter->data << "found at : ";
                cout << " : " << hash_val << endl;
                flag = true;
            }
            enter = enter->next;
        }
        if (!flag)
        {
            return -1;
        }
    }

    // delete the specified node
    void del(int val)
    {
        int hash_val = HFunc(val);
        node *enter = HT[hash_val];
        if (enter == NULL)
        {
            cout << "Element not found ";
            return;
        }
        if (enter->data == val)
        {
            HT[hash_val] = enter->next;
            return;
        }
        while ((enter->next)->data != val)
        {
            enter = enter->next;
        }
        enter->next = (enter->next)->next;
    }
};

int main()
{
    int ch;
    int data, search, del;
    hashing h;
    do
    {
        cout << "\nTelephone : \n1.Insert \n2.Display\n3.Search \n4.Delete \n5.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter 10 phone nos. to be inserted : ";
            for (int i = 0; i < 10; i++)
            {
                cin >> data;
                h.insert(data);
            }
            break;
        case 2:
            h.display();
            break;
        case 3:
            cout << "\nEnter the phone no. to be searched : ";
            cin >> search;
            if (h.search(search) == -1)
            {
                cout << "No element found at key ";
                continue;
            }
            break;
        case 4:
            cout << "\nEnter the phone no. to be deleted : ";
            cin >> del;
            h.del(del);
            break;
        }
    } while (ch != 5);
    return 0;
}