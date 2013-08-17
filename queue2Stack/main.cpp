#include <iostream>
using namespace std;

class Stack
{
    int a[100],top;

public:
    Stack()
    {
        top=-1;
    }

    void push(int ele)
    {
        if(top==99)
        {
            cout<<"Stack Full\n";
            return;
        }

        a[++top]=ele;
        return;
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack Empty\n";
            return 0;
        }

        return a[top--];
    }

    bool isEmpty()
    {
        return top==-1;
    }

    void displayStack()
    {
        for(int i=0;i<=top;i++)
            cout<<a[i]<<" ";
    }

    void displayReverseStack()
    {
        for(int i=top;i>=0;i--)
            cout<<a[i]<<" ";
    }
};


class myQueue
{
    Stack oldest, newest;

public:
    void enque(int a)
    {
        newest.push(a);
    }

    int dequeue()
    {
        if(oldest.isEmpty())
            while(!newest.isEmpty())
            oldest.push(newest.pop());

        return (oldest.pop());
    }

    void display()
    {
        oldest.displayReverseStack();
        newest.displayStack();
    }

};



int main()
{
    myQueue Q;

    for(int i=0;i<10;i++)
        Q.enque(i);

    Q.dequeue();
    Q.dequeue();
    Q.enque(56);
    Q.enque(34);
    Q.dequeue();

    Q.display();
    return 0;
}
