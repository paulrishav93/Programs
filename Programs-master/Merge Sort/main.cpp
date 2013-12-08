#include <iostream>

using namespace std;

void countSplitInversions(int *a, int lo, int mid, int hi)
{
    int i=lo;
    int j=mid+1;
    int k=0;
    int c=0;

    int *b=new int[hi-lo+1];

    while(i<=mid && j<=hi)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
        {
            b[k++]=a[j++];
            c+=mid-i+1;
        }

    }

    while(j<=hi)
        {
            b[k++]=a[j++];
            c+=mid-i+1;
        }
}

void countInversions(int *a, int lo, int hi)
{
    if(lo<hi)
    {
        int mid=((lo+hi)/2);
        countInversions(a,lo,mid);
        countInversions(a,mid+1,hi);
        countSplitInversions(a,lo,mid,hi);
    }
}

int main()
{

    int a[]={3,4,5,9,8,6,-33,-4,45,78};

    int n=sizeof(a)/sizeof(int);

    cout<<n<<endl;
    countInversions(a,0,n-1);

    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";


    return 0;
}
