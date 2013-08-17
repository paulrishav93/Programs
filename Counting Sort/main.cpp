#include <iostream>
#include<stdio.h>
using namespace std;

int countSort(int *a, int n)
{
    int *b=new int[1000001];

    int *aux=new int[n];

    for(int i=0;i<1000001;++i)
        b[i]=0;

    for(int i=0;i<n;++i)
        b[a[i]+1]++;

    for(int i=1;i<1000001;++i)
        b[i]+=b[i-1];


    for(int i=0;i<n;++i)
        aux[b[a[i]]++]=a[i];

    for(int i=0;i<n;++i)
        a[i]=aux[i];

}


int main()
{
    int n;

    cin>>n;

    int *a=new int [n];

    for(register int i=0;i<n;++i)
        scanf("%d",&a[i]);

    countSort(a,n);

    for(int i=0;i<n;++i)
        printf("%d\n",a[i]);

    return 0;
}
