#include<iostream>
using namespace std;

char* stringReverse(char *s)
{
     char *head, *tail;
    head = tail = s;
    int i = 0;

    while(s[i])
    {
        tail=&s[i];
        i++;
    }

    while(head<=tail)
    {
        char temp=*head;
        *head = *tail;
        *tail=temp;
        tail--;
        head++;
    }

    return s;
}

 int main()
 {
     char a[]="abcdefghijklmnopqrstuvwxyz1234567890";
     char *b=stringReverse(a);
     cout<<b;

    return 0;
 }
