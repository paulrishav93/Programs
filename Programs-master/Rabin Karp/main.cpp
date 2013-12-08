#include <iostream>
#include<string.h>
using namespace std;

int checkaray(int value, int *a, int W)
{

}


void computeHash(string *s, unsigned long long *a, int W)
{


    for(int i=0;i<W;++i)
    {
        int j=s[i].length();
        int value=1;
        for(int k=0;k<j;++k)
        {
            a[i]=a[i]+s[i][k]*value;
            value*=10;
        }
    }
}

int main()
{

    int W,N;

    cin>>W;

    cin.ignore();

    string *words=new string[W];
    string *lyrics=new string[N];

    for(int i=0;i<W;i++)
        getline (cin,words[i]);

    cin>>N;
    cin.ignore();

    for(int i=0;i<N;++i)
        getline(cin,lyrics[i],'\n');


    unsigned long long* a=new unsigned long long [W];

    for(int i=0;i<W;++i)
        a[i]=0;

    computeHash(words,a,W);
    int *count=new int[W];

    for(int i=0;i<W;++i)
        count[i]=0;

    for(int i=0;i<N;++i)
    {
        int l=lyrics[i].length();

        for(int j=0;j<l;++j)
        {
            int value=0,mult=1;
            while(lyrics[i][j]!='-')
            {
                value+=mult*lyrics[i][j];
                mult*=10;

                int h=-1;
                for(int i=0;i<W;++i)
                    if(a[i]==value)
                        {
                            h=i;
                            break;
                        }


                if(h!=-1)
                count[h]++;
            }
        }
    }

    for(int i=0;i<W;++i)
        cout<<count[i]<<endl;

    return 0;
}
