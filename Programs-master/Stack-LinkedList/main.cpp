#include <iostream>
#include<new>
using namespace std;


class linkedStack
{
private:
    class node
    {
    public:

        int val;
        node *next;
    };
    node *head, *temp;
    int item;
public:

    linkedStack()
    {
        head=NULL;
    }
    void add(int a)
    {
        try{temp=new node;
        }catch(bad_alloc xa){
        cout<<"Stack is Full\n";
        return;
        }

        temp->val=a;

        if(head==NULL)
        {
            head=temp;
            temp->next=NULL;
        }

        else
        {
            temp->next=head;
            head=temp;
        }
    }

    int removeItem()
    {
        item=head->val;
        head=head->next;
        return item;
    }

    void display()
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<"\n";
            temp=temp->next;
        }
    }

    bool isEmpty()
    {
        return head==NULL;
    }
};


int main()
{
    linkedStack A;
    bool check=true;
    int choice,item;
    while(check)
    {
        cout<<"1. ADD\n2. POP\n3. EXIT\n4. DISPLAY\n";
        cin>>choice;

        switch(choice){
        case 1:cout<<"\n Enter Item\n";
                cin>>item; A.add(item);
                break;
        case 2:if(!A.isEmpty())A.removeItem();
                else cout<<"Stack Empty\n";
                break;
        case 3: check=false; break;
        case 4: A.display(); break;
        default:cout<<"Incorrect choice\n"; return 0;
        }
    }

    return 0;
}
