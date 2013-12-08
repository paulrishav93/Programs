#include <fstream>

#include <math.h>

using namespace std;

#define SIZE 1000000
#define DATATYPE int

bool isPrime(int i)
{
    if(i==0 || i==1)    return false;

    if(i==2)            return true;

    int m=sqrt(i);

    for(DATATYPE j=3; j<=m; j+=2)
        if(i%j==0)  return false;

    return true;
}

int main()
{

    ofstream fout;
    fout.open("Output.txt");

    bool *a=new bool[SIZE];

    for(DATATYPE i=2; i<=SIZE ; ++ i)
        a[i]=true;

    DATATYPE m=sqrt(SIZE);

    for(DATATYPE i=2; i <= m ; i++)
        if(isPrime(i))
        {
            for(DATATYPE j=i*i ; j <= SIZE ; j+=i)
                a[j]=false;
        }

    for(DATATYPE i=2; i <= SIZE ; ++ i)
        if( a[i]==true )
            fout<<i<<" ";
    return 0;
}
