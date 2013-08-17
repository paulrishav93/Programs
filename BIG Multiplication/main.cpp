#include<iostream>
#include<fstream>
using namespace std;


void fact(unsigned long long a)
{
    uint8_t arr[2000000];
    register int i=0;
    int m,x;
    unsigned long long temp=0;
    unsigned long long b=a-1;
    int c=0;
    while(a>0)
    {
        arr[i++]=a%10;
        a/=10;
    }

    m=i;

    while(b>=1)
    {
        i=0;

        while(i<m)
        {
            x=arr[i]*b+temp;
            arr[i]=x%10;
            temp=x/10;
            i++;
        }

        while(temp!=0)
        {
            arr[m++]=temp%10;
            temp/=10;
        }

        b--;
    }


    for(int i=0;i<m;i++)
        {
            if(arr[i]==0)  c++;
            else break;
        }

    cout<<c<<endl;
}
int main()
{

    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        fact(n);
    }

    return 0;
}
