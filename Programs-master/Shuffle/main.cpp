#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int a[10];
    for(int i=0;i<10;++i)
    a[i]=i;

    for(int i=1;i<10;++i)
    {
        int b = rand()%(i);
        swap(a[i],a[b]);
    }

    for(int i=0;i<10;++i)
        cout<<a[i]<<" ";
    return 0;
}
