#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    char data;
    node *left, *right;
    node()
    {
        data = ' ';
        right = left = NULL;
    }
};

class Stack
{
public:
    node *arr[20];
    int top;

    Stack()
    {
        top = -1;
    }
    void push(node *n)
    {
        arr[++top] = n;
    }
    node *pop()
    {
        return arr[top--];
    }
    int isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class tree
{
    public:
    node *root;
    node *expression(char prefix[]);
    void postorder(node *root);
    void Delete(node *root);
};
node *tree::expression(char prefix[])
{
    Stack s;
    node *t1, *t2;
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--)
    {
        root = new node();
        if (isalpha(prefix[i]))
        {
            root->data = prefix[i];
            root->left = root->right = NULL;
            s.push(root);
        }
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '/' || prefix[i] == '*')
        {
            t1 = s.pop();
            t2 = s.pop();
            root->data = prefix[i];
            root->left = t1;
            root->right = t2;
            s.push(root);
        }
    }
    root = s.pop();
    return root;
}
void tree::postorder(node *root)
{
    Stack s1, s2;
    node *temp;
    s1.push(root);
    while (!s1.isEmpty())
    {
        temp = s1.pop();
        if (temp->left != NULL)
            s1.push(temp->left);
        if (temp->right != NULL)
            s1.push(temp->right);
        s2.push(temp);
    }
    cout << "\n The postfix expression is ";
    while (!s2.isEmpty())
    {
        temp = s2.pop();
        cout << temp->data << " ";
    }
}
void tree::Delete(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Delete(root->left);
    Delete(root->right);
    delete (root);
}
int main()
{
    tree t;
    char prefix[30];
    cout << "Enter the prefix expression";
    cin >> prefix;
    t.expression(prefix);

    cout << "\nPostorder: ";
    t.postorder(t.root);

    cout << "\n Deleting the tree: ";
    t.Delete(t.root);
    return 0;
}