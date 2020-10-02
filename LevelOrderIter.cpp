#include<iostream>
#include<queue>
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
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
// void BFSL(node* root)
// {
//     queue<node*> q;
//     q.push(root);
//
//     while(!q.empty()){
//         int nodecount = q.size();
//         node* temp = q.front();
//         cout<<temp->data<<" ";
//         q.pop();
//
//         if(temp->left!=NULL)
//             q.push(temp->left);
//         if(temp->right!=NULL)
//             q.push(temp->right);
//     }
// }
int main()
{
    node* root = Tree();
    cout<<"BFS: ";
    BFS(root);
    cout<<endl;
    cout<<"PRe-Order: ";
    Print(root);
    return 0;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
