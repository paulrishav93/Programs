#include <iostream>
#include<cstdlib>
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

    int peek()
    {
        return a[top];
    }
};
int main()
{
    Stack A;

    for(int i=0;i<21;++i)
        A.push(rand()%100);
    A.displayStack();
    Stack B;
    B.push(A.pop());

    while(!A.isEmpty())
    {
        int a=A.pop();

        if(!A.isEmpty())
        {
            int c=0;

            while(B.peek()>a && !B.isEmpty())
            {
                A.push(B.pop());
                c++;
            }

            B.push(a);

            while(c--)
            {
                B.push(A.pop());
            }

        }
    }
    cout<<endl;
    B.displayStack();
    return 0;
}
