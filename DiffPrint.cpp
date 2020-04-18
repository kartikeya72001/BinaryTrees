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
void PrintPre(node* root)
{
    if(root==NULL)
        return;
    //root->left->right
    cout<<root->data<<" ";
    PrintPre(root->left);
    PrintPre(root->right);
}
void PrintIn(node *root)
{
    if(root==NULL)
        return;
    //Left->root->right
    PrintIn(root->left);
    cout<<root->data<<" ";
    PrintIn(root->right);
}
void PrintPost(node *root)
{
    if(root==NULL)
        return;
    //Left->right->root
    PrintPost(root->left);
    PrintPost(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node* root = Tree();
    cout<<"Pre Order: ";
    PrintPre(root);
    cout<<endl<<"In-Order: ";
    PrintIn(root);
    cout<<endl<<"Post Order: ";
    PrintPost(root);
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
