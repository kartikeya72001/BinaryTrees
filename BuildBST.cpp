#include<iostream>
#include<vector>
#include<queue>
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
node* buildBst(vector<int> v, int s, int n)
{
	if(s>n)
	{
		return NULL;
	}
	int mid = (s+n)/2;
	node* temp = new node(v[mid]);
	temp->left = buildBst(v, s, mid-1);
	temp->right = buildBst(v, mid+1, n);
	return temp;
}
void PrintPre(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    PrintPre(root->left);
    PrintPre(root->right);
}
void BFS(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
node* search(node* root,int key){
	if (root == NULL or root->data == key)
		return root;
	else if (root->data < key)
		return search(root->right,key);
	return search(root->left,key);
}
int main() {
	node* root = NULL;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	root = buildBst(v, 0, n-1);
	PrintPre(root);
	cout<<endl;
	BFS(root);
	cout<<endl;
	if(search(root,5) == NULL)
		cout<<"Key Not Found"<<endl;
	else
		cout<<"Key Found"<<endl;
	return 0;
}
