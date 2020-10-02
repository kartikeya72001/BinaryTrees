#include <iostream>
#include <climits>
using namespace std;

class Node
{
    public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;
    int height = 0;
    int bal = 0;

    Node()
    {
    }

    Node(int data)
    {
        this->data = data;
    }

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

updateHeightAndBalance(Node *node)
{
    int lh = -1;
    int rh = -1;

    if (node->left != NULL)
        lh = node->left->height;
    if (node->right != NULL)
        rh = node->right->height;

    node->height = max(lh, rh) + 1;
    node->bal = lh - rh;
}

Node *ll(Node *x)
{
    Node *y = x->left;
    Node *yright = y->right;

    y->right = x;
    x->left = yright;

    updateHeightAndBalance(x);
    updateHeightAndBalance(y);

    return y;
}

Node *rr(Node *x)
{
    Node *y = x->right;
    Node *yleft = y->left;

    y->left = x;
    x->right = yleft;

    updateHeightAndBalance(x);
    updateHeightAndBalance(y);

    return y;
}

Node *rotation(Node *node)
{
    updateHeightAndBalance(node);
    if (node->bal == 2)
    { // ll,lr
        if (node->left->bal == 1)
        { // ll
            return ll(node);
        }
        else
        { // lr
            node->left = rr(node->left);
            return ll(node);
        }
    }
    else if (node->bal == -2)
    { // rr,rl
        if (node->right->bal == -1)
        { // ll
            return rr(node);
        }
        else
        {
            node->right = ll(node->right);
            return rr(node);
        }
    }

    return node;
}

Node *addData(Node *node, int data)
{
    if (node == NULL)
        return new Node(data);

    if (data < node->data)
        node->left = addData(node->left, data);
    else
        node->right = addData(node->right, data);

    node = rotation(node);
    return node;
}

int maxInTree(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    Node *rnode = root;
    while (rnode->right != NULL)
    {
        rnode = rnode->right;
    }

    return rnode->data;
}

Node *removeNode(Node *node, int data)
{
    if (node == NULL)
        return NULL;

    if (node->data == data)
    {
        if (node->left == NULL || node->right == NULL)
        {
            return node->left == NULL ? node->right : node->left;
        }

        int maxdata = maxInTree(node->left);
        node->data = maxdata;

        node->left = removeNode(node->left, maxdata);
    }
    else if (data < node->data)
        node->left = removeNode(node->left, data);
    else
        node->right = removeNode(node->right, data);

    node = rotation(node);
    return node;
}

void display(Node *node)
{
    if (node == NULL)
        return;
    string ans = "";

    ans += node->left != NULL ? to_string(node->left->data) : ".";
    ans += " -> " + to_string(node->data) + "(" + to_string(node->bal) + ")" + " <- ";
    ans += node->right != NULL ? to_string(node->right->data) : ".";
    cout << ans << endl;

    display(node->left);
    display(node->right);
}

int main(int argc, char **argv)
{
    int arr[15] = {};
    for (int i = 0; i < 15; i++)
        arr[i] = (i + 1) * 10;

    Node *root = NULL;
    for (int ele : arr)
        root = addData(root, ele);

    display(root);
    cout << endl;
    int i = 0;

    cout<<"Removing first 6 Elements"<<endl;
    for (int ele : arr)
    {
        root = removeNode(root, ele);
        if (i++ == 6)
            break;
    }
    display(root);
}
