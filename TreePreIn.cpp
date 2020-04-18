#include<iostream>
#include<vector>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};
node* PrePostTree(vector<int> pre, vector<int> ino, int s, int n)
{
	static int i = 0;
	if(s>n)
		return NULL;

	node* root  = new node(pre[i]);
	int index = -1;
	for(int j = s;s<=n;j++)
	{
		if(ino[j] == pre[i])
		{
			index = j;
			break;
		}
	}
	i++;
	root->left = PrePostTree(pre, ino, s, index-1);
	root->right = PrePostTree(pre, ino ,index+1, n);
	return root;
}
void printStyle(node *root)
{
    if(root==NULL)
        return ;
    if(root->left==NULL)
        cout<<"END => ";
    else
        cout<<root->left->data<<" => ";
    cout<<root->data;
    if(root->right==NULL)
        cout<<" <= END"<<endl;
    else
        cout<<" <= "<<root->right->data<<endl;
    printStyle(root->left);
    printStyle(root->right);

}
int main()
{
	int n1;
	cin>>n1;
	vector<int> pre(n1);
	for(int i=0;i<n1;i++)
	{
		cin>>pre[i];
	}
	int n2;
	cin>>n2;
	vector<int> ino(n2);
	for(int i=0;i<n2;i++)
	{
		cin>>ino[i];
	}
	node* root = NULL;
	root = PrePostTree(pre,ino,0,n2-1);
	printStyle(root);
	return 0;
}
/*3
1 2 3
3
3 2 1*/
