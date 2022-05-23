#include <iostream>
// #include <bits/stdc++.h>
#include <fstream>
#include <string.h>
using namespace std;
class Student
{

    int roll_no;
    char name[20], div[20], addr[20];

public:
    void accept(int key);
    int Search(int key);
    void Display();
};
void Student::accept(int key)
{
    roll_no = key;
    cout << "\n name:";
    cin >> name;
}
int Student::Search(int key)
{
    if (key == roll_no)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Student::Display()
{
    cout << roll_no << "\t" << name;
}
int main()
{
    fstream f, f1;
    Student s;
    int key, ch, ch1, t = 0;
    do
    {
        cout << "\n Select \n 1.Create Database \n2.Insert new info \n 3. search \n 4. Display \n5.Delete\n 6.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            f.open("abc.txt", ios::out);
            do
            {
                cout << "\nEnter NO:";
                cin >> key;
                s.accept(key);
                f.write((char *)&s, sizeof(s));
                cout << "More?";
                cin >> ch1;
            } while (ch1);
            f.close();
            break;
        case 2:
            f.open("abc.txt", ios::out | ios::in);
            cout << "\nENter NO.";
            cin >> key;
            while (f.read((char *)&s, sizeof(s)))
            {
                t = s.Search(key);
                if (t==1)
                {
                    cout << "\nAlready exists";
                    break;
                }
            }
            f.close();
            f.open("abc.txt", ios::out | ios::app);
            if (t != 1)
            {
                s.accept(key);
                f.write((char *)&s, sizeof(s));
            }
            f.close();
            break;
        case 3:
            f.open("abc.txt", ios::in);
            cout << "\nENter NO.";
            cin >> key;
            while (f.read((char *)&s, sizeof(s)))
            {
                t = s.Search(key);
                if (t)
                {
                    cout << "\nFound";
                    break;
                }
            }
            if (t != 1)
            {
                cout << "\n Not found.";
            }
            f.close();
            break;
        case 4:
            cout << "roll_no"
                 << "\t"
                 << "name";
            f.open("abc.txt", ios::in);
            while (f.read((char *)&s, sizeof(s)))
            {
                s.Display();
            }
            f.close();
            break;
        case 5:
            cout << "\nEnter NO.";
            cin >> key;
            t = 0;
            f.open("abc.txt", ios::in);
            f1.open("temp.txt", ios::out);
            while (f.read((char *)&s, sizeof(s)))
            {
                t = s.Search(key);
                if (t != 1)
                {
                    f1.write((char *)&s, sizeof(s));
                }
            }
            f.close();
            f1.close();
            rename("temp.txt", "abc.txt");
            cout << "\nThe new contents of file:";
            cout << "roll_no"
                 << "\t"
                 << "name";
            f.open("abc.txt", ios::in);
            while (f.read((char *)&s, sizeof(s)))
            {
                s.Display();
            }
            f.close();
            break;
        default:
            break;
        }
        /* code */
    } while (ch !=6);

    return 0;
}