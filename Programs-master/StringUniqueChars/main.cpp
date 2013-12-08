#include <iostream>

using namespace std;

bool isUnique(char *s)
{
    int i=0;

    while(s[i])
    {
        i++;
        if(i>256)
            return false;
    }

    bool a[256];

    for(int i=0;i<256;i++)
        a[i]=false;

    i=0;

    while(s[i])
    {
        if(a[s[i]])
            return false;

        else a[s[i]]=true;

        i++;
    }

    return true;
}


int main()
{
    char s[]="abcdefghijklmnopqrstuvwxyz1234567890[]\;',./~!@#$%^&*()a";

    cout<<isUnique(s);
    return 0;
}
