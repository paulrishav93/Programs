#include <iostream>
#include<math.h>
using namespace std;

class binaryTree
{
    class node
    {
    public:
        int key;
        int count;
        node *left;
        node *right;
        node(int val)
        {
            key=val;
            count=1;
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

        x->count=1+size(x->left)+size(x->right);

        return x;
    }

    int getHeight(node *x)
    {
        if(x==NULL) return 0;

        else return max(getHeight(x->left),getHeight(x->right)) +1;
    }

    bool isBalanced(node *x)
    {
        if(x==NULL) return true;

        int balanceFactor=(getHeight(x->left)-getHeight(x->right));

        if(balanceFactor>1 || balanceFactor<-1)
            return false;
        else return isBalanced(x->left) && isBalanced(x->right);
    }

    public:

    node *root;

    binaryTree()
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

    bool isBalanced()               // O(N^2) solution
    {
        return isBalanced(root);
    }

    void insertArray(int *a, int lo, int hi)
    {
        if(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            insert(a[mid]);

            insertArray(a,lo,mid-1);
            insertArray(a,mid+1,hi);
        }
    }

};

int main()
{
    binaryTree A;

    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    A.insertArray(a,0,15);
    cout<<A.isBalanced()<<endl;
    A.traversal();
    cout<<A.getSize()<<endl;
    A.deleteNode(41);
    cout<<endl;
    A.traversal();

    return 0;
}
