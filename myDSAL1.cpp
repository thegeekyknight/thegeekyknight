#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
#define TRUE 1
#define FALSE 0
struct Employee
{
    long int TeleNo;
    int flag;
    int chain;
    // string Name;
};
/* -- -- -- -- -- -- -- -- -- -- --CLASS_DIRECTORY-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - */
class Directory
{
protected:
    Employee sm[SIZE];

public:
    Directory()
    {
        for (int i = 0; i < SIZE; i++)
        {
            sm[i].TeleNo = 0;
            sm[i].flag = FALSE;
            sm[i].chain = -1;
        }
    }
    int Hash(int x);
};
int Directory::Hash(int x) { return x % SIZE; }
/* -- -- -- -- -- -- -- -- -- -- --CLASS_LINEAR-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - */
class Linear : public Directory
{
public:
    // Linear(){ for(int i = 0; i< SIZE; i++){ sm[i].TeleNo =0; sm[i].flag = FALSE;}};
    void insert(int x);
    void search(int x);
    void Display();
};
void Linear::insert(int x)
{
    int start = Hash(x);
    for (int i = 0; i < SIZE; i++)
    {
        if (sm[start].flag == 0)
        {
            sm[start].TeleNo = x;
            sm[start].flag = TRUE;
            return;
        }
        else
        {
            start = (start + 1) % SIZE;
        }
    }
    cout << "\nThe hash table is full";
}
void Linear::search(int x)
{
    int start = Hash(x);
    for (int i = 0; i < SIZE; i++)
    {
        if (sm[start].TeleNo == x)
        {
            cout << "\nThe required no. is found at location " << start << " in the hash table";
            return;
        }
        else
        {
            start = (start + 1) % SIZE;
        }
    }
    cout << "There was no such element in the hash table";
}
void Linear::Display()
{
    cout << endl
         << "SrNo"
         << "    "
         << "TeleNo";
    for (int i = 0; i < SIZE; i++)
    {
        if (sm[i].flag == 1)
        {
            cout << endl
                 << i << "    " << sm[i].TeleNo;
        }
        else
        {
            cout << endl
                 << i << "    "
                 << "-----";
        }
    }
}
/* -- -- -- -- -- -- -- -- -- -- --CLASS_CHAINING-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - */
class Chaining : public Directory
{
public:
    void insert(int x);
    void search(int x);
    void Display();
};
void Chaining::insert(int x)
{
    int i = 0, j, start;
    start = Hash(x);
    /* Locate the beginning of the chain */
    while (sm[start].flag == TRUE && i < SIZE)
    {
        if (sm[start].TeleNo % SIZE == start)
            break;
        i++;
        start = (start + 1) % SIZE;
    }
    if (i == SIZE)
    {
        cout << "\nThe HashTable is full";
        return;
    }
    /*go to the end of the chain or empty location */
    while (sm[start].chain != -1)
    {
        start = sm[start].chain;
    }
    /*locate empty place for current data*/
    cout << i;
    j = start;
    while (sm[j].flag && i < SIZE)
    {
        j = (j + 1) % SIZE;
        i = i + 1;
    }
    if (i == SIZE)
    {
        cout << "\n The HashTable is full";
    }
    sm[j].TeleNo = x;
    sm[j].flag = TRUE;
    if (start != j)
    {
        sm[start].chain = j;
    }
}
void Chaining::search(int x)
{
    int i = 0, start;
    start = Hash(x);
    /* Tracing the beginning of the chain */
    while (i < SIZE && sm[start].flag && sm[start].TeleNo % SIZE != start)
    {
        start = (start + 1) % SIZE;
        i++;
    }
    if (i == SIZE)
    {
        cout << "\nNo such element is found";
    }
    /* locate the element in the chain */
    while (start != -1)
    {
        if (sm[start].TeleNo == x)
        {
            cout << "\nThe required data is found at " << start << endl;
            return;
        }
        start = sm[start].chain;
    }
    cout << "\nNo such element is found";
    return;
}

void Chaining::Display()
{
    cout << endl
         << "SrNo"
         << "    "
         << "TeleNo"
         << "    "
         << "chain";
    for (int i = 0; i < SIZE; i++)
    {
        if (sm[i].flag == TRUE)
        {
            cout << endl
                 << i << "    " << sm[i].TeleNo << "    " << sm[i].chain;
        }
        else
        {
            cout << endl
                 << i << "    "
                 << "-----";
        }
    }
}
/* -- -- -- -- -- -- -- -- -- -- --MAIN-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - */
int main()
{
    int ch, x;
    Directory d;
    Linear l;
    Chaining c;
    cout << "CHECK";
    do
    {
        cout << "\nEnter your choice: \n 1. Insert \n2.Search without chaining \n3.Search with chaining \n4.Display without chaining \n5.Display with chaining. \n6. Exit";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\n Enter x:";
            cin >> x;
            l.insert(x);
            c.insert(x);
            break;
        case 2:
            cout << "\nEnter the No. to be searched: ";
            cin >> x;
            l.search(x);
            break;
        case 3:
            cout << "\nEnter the No. to be searched: ";
            cin >> x;
            c.search(x);
            break;
        case 4:
            l.Display();
            break;
        case 5:
            c.Display();
            break;
        case 6:
            break;
        }
    } while (ch != 6);
    return 0;
}