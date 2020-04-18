#include<bits/stdc++.h>

using namespace std;

class node{
public:
  int data;
  node* left;
  node* right;

  node(int d){
    data = d;
    left=NULL;
    right=NULL;
  }
};

node*createBST(node*root, int d){
    if(!root){
        root = new node(d);
        return root;
    }

    if(d>root->data){
        root->right = createBST(root->right,d);
    }else{
        root->left = createBST(root->left,d);
    }

    return root;
}

node* DeleteBst(node* root, int data)
{
	if(root== NULL)
		return NULL;

	else if(data < root->data)
	{
		root->left = DeleteBst(root->left, data);
		return root;
	}
	else if(data > root->data)
	{
		root->right = DeleteBst(root->right, data);
		return root;
	}
	else if(data == root->data)
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		if(root->right!=NULL and root->left==NULL)
		{
			node* temp = root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL and root->right==NULL)
		{
			node* temp = root->left;
			delete root;
			return temp;
		}
		node* replace = root->right;
		while(replace->left!=NULL){
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = DeleteBst(root->right, replace->data);
		return root;
	}
	else{
		root->right = DeleteBst(root->right, data);
		return root;
	}
}


void preOrder(node*root)
{
  if(!root)
  {
    return;
  }

  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}


int main()
{
  int t;
  cin>>t;



  while(t--)
  {
    int n;
    cin>>n;

    node*root=NULL;

    int x;
    while(n--)
    {
        cin>>x;
        root = createBST(root,x);
    }

    //preOrder(root);

    int m;
    cin>>m;

    while(m--)
    {
        cin>>x;
        root = DeleteBst(root,x);

    }

    preOrder(root);
    cout<<endl; //change

  }

  return 0;
  }
