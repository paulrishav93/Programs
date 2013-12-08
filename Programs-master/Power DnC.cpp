#include <iostream>
#include<math.h>

using namespace std;

int power(int x, int n)
{
    unsigned long long y;


    if(n==1)
        return x;

    if(n==0)
        return 1;

    else if(n%2==0)
        {
            y=power(x,n/2);
            return y*y;
        }

    else
        {
            y=power(x,(n-1)/2);
            return y*y*x;
        }
}
int main()
{
    //cout<<power(2,20);

    for(int i=0;i<=20;++i)
    {
        cout<<pow(2,i);
    }

    return 0;
}