#include <iostream>
#include <cstdlib>
using namespace std;

class redblackBST
{
    class node
    {
    public:
        int key;
        int count;
        bool color;     // 1 for red, 0 for black
        node *left;
        node *right;
        node(int val)
        {
            key=val;
            count=1;
            color=1;    // new node is always 'glued' to an existing node
            left=NULL;
            right=NULL;
        }
    };

    int size(node *x)
    {
        if (x==NULL)    return 0;

        return x->count;
    }

    void inorderTraversal(node *x)
    {
        if(x==NULL) return;

        inorderTraversal(x->left);
        cout<<x->key<<" ";
        inorderTraversal(x->right);

    }

    node* insert(node *x, int val)
    {
        if(x==NULL)  return new node(val);

        if(val<(x->key))
            x->left=insert(x->left,val);

        else if(val>(x->key))
            x->right=insert(x->right,val);

        else x->key=val;

        x->count=1+size(x->left)+size(x->right);

        return x;
    }

    node* maximum(node *x)
    {
        if(x==NULL) return NULL;
        else if(x->right==NULL) return x;
        x=maximum(x->right);
        return x;
    }

    node* floor(node *x, int val)               //FLOOR: Largest key which is <= Given Key
    {
        if (x==NULL)    return NULL;

        if(x->right)
        {
            if(x->key<=val && x->right->key>val)
                return x;
            if (x->key<val && x->right->key<=val)
                x=floor(x->right,val);
        }

        if(x->left)
        {
            if(x->key>val)
                x= floor(x->left,val);
            if(x->key<=val)
                return x;
        }

        if(!x->left && !x->right)
        {
            if(x->key>val)
                return NULL;
            else return x;
        }

        return x;
    }

    int rank(node *x, int val)
    {
        if(x==NULL) return 0;

        if(val<x->key)
            return rank(x->left,val);

        if(val>=x->key)
            return (1+size(x->left)+rank(x->right,val));
    }

    node* deleteMIN(node *x)
    {
        if(!x) return NULL;

        if(!x->left)   return x->right;

        x->left=deleteMIN(x->left);

        x->count=1+size(x->left)+size(x->right);

        return x;
    }

    node* minimum(node* x)
    {
        if(!x)  return NULL;
        if(!x->left)    return x;
        x=minimum(x->left);

        return x;
    }

    node* deleteNode(node *x,int val)
    {
        if(x==NULL)  return NULL;

        if(x->key>val)  x->left=deleteNode(x->left,val);
        else if (x->key<val)    x->right=deleteNode(x->right,val);
        else
        {
            if(x->right==NULL)  return x->left;

            node* t=x;
            x=minimum(t->right);
            x->right=deleteMIN(t->right);
            x->left=t->left;
        }

        if(isRed(x->right) && !isRed(x->left))
        {
            x=rotateLeft(x);
        }

        if(isRed(x->left) && isRed(x->left->left))
        {
            x=rotateRight(x);
        }

        if(isRed(x->left) && isRed(x->right))
        {
            flipColor(x);
        }
        x->count=1+size(x->left)+size(x->right);

        return x;
    }

    node* rotateLeft(node *h)
    {
        node *x=h->right;
        h->right=x->left;
        x->left=h;
        x->color=h->color;
        h->color=1;
        return x;
    }

    node* rotateRight(node* h)
    {
        node* x=h->left;
        h->left=x->right;
        x->right=h;
        x->color=h->color;
        h->color=1;
        return x;
    }

    void flipColor(node* h)
    {
        h->color=1;
        h->left->color=0;
        h->right->color=0;
    }

    bool isRed(node *h)
    {
        if(h==NULL) return false;
        return h->color==1;
    }

    public:

    node *root;

    redblackBST()
    {
        root=NULL;
    }

    void insert(int val)
    {
        root=insert(root,val);
    }

    int getMaximum()
    {
        node *x=maximum(root);
        if(x)
        {
            return x->key;
        }

        else
        {
            cout<<"Tree does not exist\n";
            return 0;
        }
    }

    int getFloor(int val)
    {
        node *x=floor(root,val);
        if(x)
            return x->key;
    }

    void traversal()
    {
        inorderTraversal(root);
    }

    int getSize()
    {
        return size(root);
    }

    int getRank(int val)                //No. of keys which are less than 'val'
    {
        return rank(root,val);
    }

    void deleteMIN()
    {
        root=deleteMIN(root);
    }

    void deleteNode(int val)
    {
        root=deleteNode(root,val);
    }

};

int main()
{
    redblackBST A;


    for(int i=0;i<=1000;++i)
    A.insert(rand()%100);

    A.traversal();
    cout<<endl;
    return 0;
}
