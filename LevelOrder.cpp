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
int height(node* root)
{
    if(root==NULL)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
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
    cout<<height(root)<<endl;
    Print(root);
    return 0;
}
