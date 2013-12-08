#include <iostream>

using namespace std;
char a[10000];
uint16_t LCS[1024][1024];

int LCSLength(char *X, int m, char *Y, int n)
{
    for(int i=0;i<=m;++i)
        LCS[i][n]=0;

    for(int i=0;i<=n;++i)
        LCS[m][i]=0;

    int k=0;

    for(int i=m-1;i>=0;i--)
        for(int j=n-1;j>=0;j--)
        {
            LCS[i][j]=LCS[i+1][j+1];
            a[k++]='b';

            if(X[i]==Y[j])
            {
                LCS[i][j]++;
            }


            if(LCS[i][j+1]>LCS[i][j])
            {
                LCS[i][j]=LCS[i][j+1];
                a[k]='c';
            }


            if(LCS[i+1][j]>LCS[i][i])
                {
                    LCS[i][j]=LCS[i+1][j];
                    a[k]='a';
                }
        }

        k=0;int i=0,j=0;
        while(i<m && j<n)
        {
            if(X[i]==Y[j])  cout<<X[i];

            if(a[k]=='a')
                i+=1;

            else if (a[k]=='b')
                {
                         i+=1;
                         j+=1;
                }

            else j+=1;

            k++;
        }

        return LCS[0][0];
}
int main()
{
    cout<<LCSLength("abcdefg",7,"acf",3);

    return 0;
}
