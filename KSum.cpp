#include<iostream>
using namespace std;
int sum = 0;
class node{
public:
	int data, child;
	node* left;
	node* right;
	node(int d, int ch){
		child = ch;
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* BuildTree()
{
    int d, ch;
    cin>>d>>ch;
    node* root = new node(d,ch);
	if(ch == 0)
		return root;
	else if(ch == 1)
    	root->left = BuildTree();
    else{
		root->left = BuildTree();
		root->right = BuildTree();
	}
    return root;
}
void KSum(node* root, int k)
{
	if(root==NULL)
		return;
	if(k==0){
		sum+=root->data;
		k++;
		return;
	}
	KSum(root->left,k-1);
	KSum(root->right,k-1);
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
int main() {
	node* root = NULL;
	root = BuildTree();
	//PrintPre(root);
	int k;
	cin>>k;
	KSum(root,k);
	cout<<sum;
	return 0;
}
/*1 2
2 2
3 0
4 0
5 2
6 0
7 0
2*/
