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
int count(node* root)
{
    if(root==NULL)
        return 0;
    return 1+count(root->left)+count(root->right);

}

int countNodes(node* root) {
    return count(root);
}
int main()
{
    node* root = Tree();
    cout<<countNodes(root);
    return 0;
}
