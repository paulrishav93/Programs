#include<iostream>
#include<fstream>
using namespace std;
//unsigned long c=0;
unsigned long merge(int *a,int p, int q, int r)
{
     int n1=q-p+1;
     int n2=r-q;

     int *L=new int[n1+1];
     int *R=new int[n2+1];
     int i;
     for(i=0;i<n1;i++)
             {L[i]=a[p+i];}
     int arrLen=i-1;
     //cout<<endl;
     for(int j=0;j<n2;j++)
             {R[j]=a[q+j+1];}
    // cout<<endl;


     i=0;int j=0;

     L[n1]=1000000;
     R[n2]=1000000;
    unsigned long c=0;

     for(register int k=p;k<=r;k++)
     {
             if(L[i]<R[j])  a[k]=L[i++];
             else {
                  a[k]=R[j++];
                  c+=arrLen-i+1;
                  }
             //cout<<"==C inside==:"<<c<<endl;
     }
     //cout<<"==Count==:"<<c<<endl;
     return c;
}

unsigned long mergesort(int *a, int lo, int hi)
{
     if(lo==hi) return 0;
      unsigned long  mid=(lo+(hi-lo)/2); //cout<<"LOW: "<<lo<<"MID: "<<mid<<"HI:"<<hi<<endl;
      unsigned long x=mergesort(a,lo,mid);
      unsigned long y=mergesort(a,mid+1,hi);
      unsigned long z=merge(a,lo,mid,hi);
      return x+y+z;
}

int inversions(int *a,int lo, int hi)
{
        unsigned long x=mergesort(a,lo,hi);
        cout<<x<<endl;
}


int main()
{
    ifstream fin;
    fin.open("IntegerArray.txt");
    int b[100000];
    for(int i=0;i<=99999;++i)
        fin>>b[i];
    inversions(b,0,99999);
    return 0;
}
