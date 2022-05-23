#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
#define TRUE 1
#define FALSE 0
#define Hash(x) x % SIZE

class normal
{
    int data[SIZE], flag[SIZE], chain[SIZE], i = 0;
    string name[SIZE];

public:
    normal()
    {
        for (i; i < SIZE; i++)
        {
            data[i] = FALSE;
            flag[i] = FALSE;
            chain[i] = -1;
        }
    }
    void insert(int x, string Name);
    void search(int x);
    void Display();
    void Delete(int x);
};
void normal::insert(int x, string Name)
{
    int i = 0, j, start;
    start = Hash(x);
    while (flag[start] == TRUE && i < SIZE)
    {
        if (data[start] % SIZE == x % SIZE)
        {
            break;
        }
        i++;
        start = (start + 1) % SIZE;
    }
    if (i == SIZE)
    {
        cout << "\nFULL";
        return;
    }

    while (chain[start] != -1)
    {
        start = chain[start];
    }

    j = start;

    while (flag[j] && i < SIZE)
    {
        j = (j + 1) % SIZE;
        i++;
    }
    if (i == SIZE)
    {
        cout << "\nFULL";
        return;
    }
    data[j] = x;
    name[j] = Name;
    flag[j] = TRUE;
    if (j != start)
    {
        chain[start] = j;
    }
}

void normal::search(int x)
{
    int i = 0, start;
    start = Hash(x);
    /* Locate Beginnning */
        while (i < SIZE && flag[start] && data[start] % SIZE != x % SIZE)
    {
        i++;
        start = (start + 1) % SIZE;
    }
    if (!flag[start] || i == SIZE)
    {
        cout << "\n CHALA JA BSDK";
    }
    while (start != -1)
    {
        if (data[start] == x)
        {
            cout << "\nfound at " << start;
            return;
        }
        start = chain[start];
    }
    cout << "\n Not found";
}

void normal::Display()
{
    cout << endl
         << "SrNo"
         << "    "
         << "TeleNo"
         << "    "
         << "chain";
    for (int i = 0; i < SIZE; i++)
    {
        if (flag[i] == TRUE)
        {
            cout << endl
                 << i << "    " << data[i] << "    " << chain[i];
        }
        else
        {
            cout << endl
                 << i << "    "
                 << "-----";
        }
    }
}

void normal ::Delete(int x)
{
    int i = 0, start;
    start = Hash(x);
    /* Locate Beginnning */
        while (i < SIZE && flag[start] && data[start] % SIZE != x % SIZE)
    {
        i++;
        start = (start + 1) % SIZE;
    }
    if (!flag[start] || i == SIZE)
    {
        cout << "\n CHALA JA BSDK";
    }
    while (start != -1)
    {
        if (data[start] == x)
        {
            data[start] == 0;
            name[start] = "";
            flag[start] = FALSE;
            chain[start] = -1;
            cout << "Data has been deleted";
            return;
        }
        start = chain[start];
    }
    cout << "\n Not found";
}
/*-------------------Replace------------------------*/
class Replace
{
    int data[SIZE], flag[SIZE], chain[SIZE], i = 0;
    string name[SIZE];

public:
    Replace()
    {
        for (i; i < SIZE; i++)
        {
            data[i] = FALSE;
            flag[i] = FALSE;
            chain[i] = -1;
        }
    }
    void insert(int x, string Name);
    void search(int x);
    void Display();
};

void Replace::insert(int x, string Name)
{
    int i = 0, j, start;
    start = Hash(x);
    /* 1. Hashed location is empty*/
    if (flag[start] == 0)
    {
        data[start] = x;
        name[start] = Name;
        flag[start] = TRUE;
        return;
    }
    /* 2. Hashed location does not contain a synonym*/
    if (Hash(data[start]) != Hash(x))
    {
        /* locate empty*/
        i = 0;
        j = start;
        while (flag[j] && i < SIZE)
        {
            j = (j + 1) % SIZE;
            i++;
        }
        if (i == SIZE)
        {
            cout << "FULL HAI BHAI";
            return;
        }
        /* DELETING ELEMENT TO MODIFY CHAIN*/
        i = data[start] % SIZE; /*BEGINNIGN OF THE CHAIN*/
        while (chain[i] != start)
        {
            i = chain[i];
        }
        chain[i] = chain[start];
        /* add THE ELEMENT AT THE END OF THE CHAIN */
            while (chain[i] != -1)
                i = chain[i];
        chain[i] = j;
        data[j] = data[start];
        chain[start] = -1;
        flag[j] = 1;
        chain[j] = -1;
        /* insert current key */
            data[start] = x;
        chain[start] = -1;
        name[start] = Name;
        return;
    }
    /* 2. Hashed location does not contain a synonym*/
    /*LOCATE AN EMPTY LOCATION*/
    i = 0;
    j = start;
    while (flag[j] && i < SIZE)
    {
        j = (j + 1) % SIZE;
        i++;
    }
    if (i == SIZE)
    {
        cout << "FULL HAI RE";
        return;
    }
    data[j] = x;
    name[j] = Name;
    flag[j] = 1;
    chain[j] = -1;
    /* go to the end of the chain*/

    i = start; /* beginning of chain*/
    while (chain[i] != -1)
    {
        i = chain[i];
    }
    chain[i] = j;
}
void Replace::search(int x)
{
    int i = 0, j;
    j = Hash(x);
    /* locate beginning of chain */
        while (i < SIZE && flag[j] && data[j] % SIZE != x % SIZE)
    {
        i++;
        j = (j + 1) % SIZE;
    }
    if (!flag[j] || i == SIZE)
    {
        cout << "\nNOT FOUND";
        return;
    }
    /* locate element in the chain */
        while (j != -1)
    {
        if (data[j] == x)
        {
            cout << "\nfound " << data[j] << " " << name[j] << " at " << j;
            return;
        }
        j = chain[j];
    }
    cout << "\nNahi mmila bhai";
    return;
}

void Replace::Display()
{
    cout << endl
         << "SrNo"
         << "    "
         << "TeleNo"
         << "    "
         << "NAME"
         << "    "
         << "chain";
    for (int i = 0; i < SIZE; i++)
    {
        if (flag[i] == TRUE)
        {
            cout << endl
                 << i << "    " << data[i] << "    " << name[i] << "    " << chain[i];
        }
        else
        {
            cout << endl
                 << i << "    "
                 << "-----";
        }
    }
}
/*-------------------------------------MAIN-------------------------------*/
int main()
{
    int ch, x, s;
    string Name;
    normal n;
    Replace r;
    cout << "DEKH";
    do
    {
        cout << "\n1. Insert  \n2. Display chaining with replacement \n3.Display chaining without replacement  \n 4.Search in with replacement \n 5. Search in without replacement \n 6.Delete \n 7.EXIT";
        cout << "\nENTER CHOICE: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n ENter no.: ";
            cin >> x;
            cout << "\n ENter Name: ";
            cin >> Name;
            n.insert(x, Name);
            r.insert(x, Name);
            break;
        case 2:
            r.Display();
            break;
        case 3:
            n.Display();
            break;
        case 4:
            cout << "\n ENter element";
            cin >> s;
            r.search(s);
            break;
        case 5:
            cout << "\n ENter element";
            cin >> s;
            n.search(s);
            break;
        case 6:
            cout << "\n ENter";
            cin >> x;
            n.Delete(x);
            break;
        case 7:
            break;
        default:
            cout << "\nWRONG INPUT";
            break;
        }
    } while (ch != 7);
    return 0;
}