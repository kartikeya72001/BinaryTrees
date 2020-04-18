#include<iostream>
using namespace std;
int x=0;

class node{

    public:
    node*right=NULL;
    node*left=NULL;
    int data;

    node(int d){
        data=d;
    }

};

node*insert(node*&root){

    if(x==0){
        int k;
        cin>>k;
        x++;
        root=new node(k);
        //cout<<k<<endl;
        root->left=insert(root->left);
        root->right=insert(root->right);
        return root;
    }

    string s="abc";
    cin>>s;
    if(s!="abc")
	{
       	if(s=="true")
		{
			int d;
			cin>>d;
			node*nn=new node(d);
			nn->left=insert(nn->left);
			nn->right=insert(nn->right);
			return nn;
    	}

      else
         return root;

  }
    return root;
}
void print(node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	node* temp = NULL;
	print(root->left);
	temp = root->left;
	root->left = root->right;
	root->right = temp;
    print(root->right);
	return;

}
int main() {
   	node*root=NULL;
   	x=0;
    insert(root);
	print(root);
}
