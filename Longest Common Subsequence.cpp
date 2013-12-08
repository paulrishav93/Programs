#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LCS(string x,string y)
{
    int m=x.length();
    int n=y.length();

    vector< vector<int> > LCSTable(m+1, vector<int> (m+1,0));

    for(int i=m-1;i>=0;--i)
    {
        for(int j= n-1;j>=0;--j)
        {
            LCSTable[i][j]=LCSTable[i+1][j+1];

            if(x[i]==y[j])
                LCSTable[i][j]=1+LCSTable[i+1][j+1];

            if(LCSTable[i][j+1]>LCSTable[i][j])
                LCSTable[i][j]=LCSTable[i][j+1];

            if(LCSTable[i+1][j]>LCSTable[i][j])
                LCSTable[i][j]=LCSTable[i+1][j];
        }
    }

    return LCSTable[0][0];
}
int main()
{
    string x="ABCDEFGH";
    string y="ACDG";

    cout<<LCS(x,y);
    return 0;
}
