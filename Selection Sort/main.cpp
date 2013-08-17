#include <iostream>
#include<cstdlib>


using namespace std;

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void selectionsort(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        int k; int m=a[i];

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<=m)
                {
                    m=a[j];
                    k=j;
                }
        }

        if(m!=a[i])
        swap(a[i],a[k]);

        cout<<"Pass: "<<i+1<<"  :- ";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n=rand()%100;
    int *a=new int[n];

    for(int i=0;i<n;i++)
        a[i]=rand()%100;

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    selectionsort(a,n);

    return 0;
}


