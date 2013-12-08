#include <iostream>
using namespace std;

class DelNMth
{
    class node
    {
    public:
        int val;
        node *next;
    };

    node *temp,*head,*tempPrev,*curPos;

    public:

    DelNMth()
    {
        temp=head=tempPrev=NULL;
    }

    void add(int ele)
    {
        temp=new node;
        temp->val=ele;
        temp->next=NULL;

        if(!head)
        {
            head=temp;
            curPos=head;
            return;
        }
        else
        {
            curPos->next=temp;
            curPos=curPos->next;
            return;
        }
    }

    void delNode(int ele)
    {
        temp=head;
        if(temp->val==ele)
        {
           head=head->next;
           delete temp;
        }
        else
        while(temp->next!=NULL)
        {
            tempPrev=temp;
            temp=temp->next;

            if(temp->val==ele)
            {
                tempPrev->next=temp->next;
                delete temp;
                return;
            }
        }
        return;
    }

    void delMth(int m)
    {
        int c=1;temp=head;

        while(c!=m)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                cout<<"Insufficiently large M\n";
                return;
            }
            c++;
        }

        curPos=temp;
        temp=head;

        while(curPos->next!=NULL)
        {
            curPos=curPos->next;
            temp=temp->next;
        }

        cout<<"The "<<m<<" th element from the last is: "<<temp->val<<endl;

        return;

    }

    void display()
    {
        temp=head;
        cout<<"Head";
        while(temp)
        {
            cout<<" -> "<<temp->val;
            temp=temp->next;
        }
        cout<<" -> NULL";
        cout<<endl;
    }

};



int main()
{
    DelNMth Ob;

    for(int i=0;i<10;++i)
    Ob.add(i);

    Ob.delMth(10);
    Ob.display();
    return 0;
}
