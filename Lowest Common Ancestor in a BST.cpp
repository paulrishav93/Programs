#include <iostream>

using namespace std;

class Node
{
public:
    Node(int data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
    int data;
    Node *left;
    Node *right;
};

Node* lca(Node *root, int num1, int num2)
{
    if(root==NULL)  return NULL;

    else if(num2<root->data && num1<root->data)
        return lca(root->left,num1,num2);

    else if(num1>root->data && num2>root->data)
        return lca(root->right,num1,num2);

    return root;
}

int main()
{
    Node *root               = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);

    cout<<lca(root,4,22)->data<<endl;

    return 0;
}
