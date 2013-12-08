#include <iostream>

#include <math.h>

using namespace std;

bool isPrime(int i)
{
    if(i==0 || i==1)    return false;

    if(i==2)            return true;

    int m=sqrt(i);

    for(int j=3; j<=m; j+=2)
        if(i%j==0)  return false;

    return true;
}

int main()
{


    bool *a=new bool[40];

    for(int i=2; i<=40 ; ++ i)
        a[i]=true;

    int m=sqrt(40);

    for(int i=2; i <= m ; i++)
        if(isPrime(i))
        {
            for(int j=i*i ; j <= 40 ; j+=i)
                a[j]=false;
        }



    int t,l,r;

    cin>>t;


    while(t--)
    {
        cin>>l>>r;

        int c=0,sum=0,rem;

        for(int i=l;i<=r;i++)
            {
                int num=i;

                while(num>0)
                {
                 rem=num%10;
                 sum+=rem;
                 num=num/10;
                 }

                if(a[sum]==true)
                  c++;

                sum=0;
            }

        cout<<c<<endl;
    }
    return 0;
}
