#include <iostream>
#include<cstdlib>
using namespace std;

void insertionsort(int *a,int n)
{
    for(int i=1;i<n;++i)
    {
        int j=i-1;
        int key=a[i];

        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n=rand()%100;
    int *a=new int[n];

    for(int i=0;i<n;i++)
        a[i]=rand()%100;

    insertionsort(a,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


