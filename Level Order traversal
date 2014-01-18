#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    node(int data)
    {
        left = 0;
        right = 0;
        this->data = data;
    }

    node* left;
    node *right;
    int data;
};

int main()
{

    queue<node> Q;
    node *root = new node(5);

    root -> left = new node(6);
    root -> right = new node(7);
    root -> left -> left = new node(8);
    root -> right-> left = new node(9);

    node *temp = root;

    while(temp)
    {
        cout << temp->data << " ";

        if(temp->left) Q.push(*temp->left);
        if(temp->right) Q.push(*temp->right);

        if(Q.empty())   temp = 0;
        else temp=&(Q.front());
        Q.pop();
    }
	return 0;
}
