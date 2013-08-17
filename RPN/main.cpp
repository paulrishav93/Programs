#include<iostream>
#include<string.h>
using namespace std;

char str[101]; int top=0;
void push(char a)
{
     str[top++]=a;
}

char peek()
{
     return str[top];
}

char pop()
{
     if (!top) return 49;
     return str[top--];
}

void swap(char &a, char &b)
{
    char temp=a;
    a=b;
    b=temp;
}

int countString(char *inString)
{
    int len=strlen(inString);
    int c=0;
    for(int i=0;i<len;++i)
    {
        if(inString[i]=='x')
            push('x');

        else if(inString[i]=='*')
        {
            char pop1=pop();
            char pop2=pop();
            if(pop1==49||pop2==49)
            {
                swap(inString[i],inString[i+1]);
                c++;
                i=-1;
                top=0;
            }

            else
            {
                push(pop1);
                push(pop2);
            }

        }
    }

    return c;
}

int main()
{
    char inString[100];
    int T;

    cin>>T;

    while(T--)
    {
        cin.getline(inString,100);
        cout<<countString(inString)<<endl;
    }

    return 0;
}
