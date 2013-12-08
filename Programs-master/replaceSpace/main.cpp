#include <iostream>

using namespace std;


void replaceSpace(char *str)
{
    int i=0,c=0,length,newLength;

    while(str[i])
        i++;

    length=i;
    i=0;

    while(str[i])
    {
        if(str[i]==' ')
        {
            c++;
        }
        i++;
    }

    newLength=length+(2*c);

    str[newLength]='\0';

    newLength=newLength-1;

    for(i=length-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            str[newLength--]='0';
            str[newLength--]='2';
            str[newLength--]='%';
        }

        else
        {
            str[newLength--]=str[i];
        }
    }
}

int main()
{
    char s[]="Hello, how do you do?";
    replaceSpace(s);
    cout<<s;
    return 0;
}
