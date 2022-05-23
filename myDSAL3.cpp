#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    node *insert(node *temp, int val);
    int LongPath(node *root);
    void min(node *root);
    void swap(node *root);
    void Search(node *root, int x);
    void Display();
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
};
node *BST::insert(node *root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        cout << "\nThe data already exists..";
    }
    return root;
}
void BST::min(node *root)
{
    node *temp;
    if (root == NULL)
    {
        cout << "Tree is empty";
    }
    else
    {
        temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << "\n Minimum no. is:  " << (temp->data);
    }
}
void BST::swap(node *root)
{
    node *temp;
    if (root != NULL)
    {
        temp = root->right;
        root->right = root->left;
        root->left = temp;
        swap(root->left);
        swap(root->right);
    }
}
void BST::Search(node *root, int x)
{
    if (root == NULL)
    {
        cout << "tree is empty";
        return;
    }
    if (root->data == x)
    {
        cout << "\n Element is found.";
    }
    else if (x > root->data && root->right != NULL)
    {
        Search(root->right, x);
    }
    else if (x < root->data && root->left != NULL)
    {
        Search(root->left, x);
    }
    else
    {
        cout << "\nTHe data doesn't exist";
    }
}
int BST::LongPath(node *root)
{
    int htleft, htright;
    if (root == NULL)
    {
        return 0;
    }
    else if (root->right == NULL && root->left == NULL)
    {
        return 1;
    }
    htleft = LongPath(root->left);
    htright = LongPath(root->right);
    if (htright >= htleft)
    {
        return (htright + 1);
    }
    else
    {
        return (htleft + 1);
    }
}
void BST::preorder(node *root)
{

    if (root != NULL)
    {
        cout << "\t" << root->data ;
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}
void BST::postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}

int main()
{
    BST bst;
    int val, x;
    int choice;
    do
    {
        cout << "\n-----------------" << endl;
        cout << "Operations on BST" << endl;
        cout << "-----------------" << endl;
        cout << "1.Insert Element " << endl;
        cout << "2.No. of nodes in longest path" << endl;
        cout << "3.Min value find" << endl;
        cout << "4.Swapping of nodes" << endl;
        cout << "5.Search an element" << endl;
        cout << "6.Display" << endl;
        cout << "7.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number to be inserted : ";
            cin >> val;
            bst.root = bst.insert(bst.root, val);
            break;
        case 2:
            cout << "\nNodes are : " << bst.LongPath(bst.root);
            break;
        case 3:
            bst.min(bst.root);
            break;
        case 4:
            bst.swap(bst.root);
            break;
        case 5:
            cout << "\nEnter ";
            cin >> x;
            bst.Search(bst.root, x);
            break;
        case 6:
            cout << "\n preorder ";
            bst.preorder(bst.root);
            cout << "\n inorder ";

            bst.inorder(bst.root);
            cout << "\npostorder ";

            bst.postorder(bst.root);
            break;
        case 7:
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice != 7);
    return 0;
}