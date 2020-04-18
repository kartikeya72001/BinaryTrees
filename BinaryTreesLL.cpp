#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* Tree()
{
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    node* root = new node(d);
    root->left = Tree();
    root->right = Tree();
    return root;
}
void Print(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
}
int main()
{
    node* root = Tree();
    Print(root);
    return 0;
}
