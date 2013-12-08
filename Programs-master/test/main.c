#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int W;

    cin>>W;

    string *words=new string[W];

    for(uint16_t i=0;i<W;++i)
        cin>>words[i];

    for(uint16_t i=0;i<W;++i)
        cout<<words[i];

    return 0;

}
