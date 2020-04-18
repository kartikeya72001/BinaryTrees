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
node *buildtree()
{
    int count=0;
    int d;
    queue<node*> q;
    cin>>d;
    node *root=new node(d);
    node *cur=root;
    root=cur;
    while(1)
    {
        cin>>d;
        if(d!=-1)
        {
            if(count==0)
            {
                cur->left=new node(d);
                count++;
                q.push(cur->left);
            }
            else if(count==1)
            {
                cur->right=new node(d);
                q.push(cur->right);
                count=0;
                if(q.front())
                cur=q.front();
                q.pop();
            }
        }
        else if(d==-1)
        {
            if(count==0)
            count++;

            else
            {
                count=0;
                if(q.front())
                cur=q.front();

                q.pop();
            }
        }
        if(q.empty())
        return root;
    }
}
void dfsbyLevel(node*root,int level,vector<int> &output)
{
    if(!root)
    {
        return;
    }
    if(level == output.size())
    {
        output.push_back(root->data);
    }
    dfsbyLevel(root->right,level+1,output);
    dfsbyLevel(root->left,level+1,output);
}

void rightSideView(node* root) {
    if(!root)
    {
        return;
    }
    vector<int> output;
    dfsbyLevel(root,0,output);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
}
int main()
{
    node* root = buildtree();
    rightSideView(root);
    return 0;
}
