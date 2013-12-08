#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;

class BIT
{
      vector<int> tree;
      int max_Val;

      public:

      BIT(int N):tree(vector<int> (N+1, 0)),max_Val(N){}

      //need to update all the nodes which are part of the
      //left subtree where idx lies
      //-idx= complement(idx) + 1
      //idx & -idx keeps only the last digit which was 1 (from LSB)
      //remaining all are made zero
      //when this value is repeated added to idx, when traverse upward the
      //left subtree and update each element
      void update(int idx, int val)
      {
           while (idx <= max_Val)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }

      //Returns the cumulative frequency of index idx
      //moving down the tree
      //so using idx-=(expression)
      int readCF(int idx)
      {
        int sum=0;
        while (idx>0)
        {
              sum+=tree[idx];
              idx-=(idx & -idx);
        }
        return sum;
      }

      //return the frequency
      int readF(int idx)
      {
          return readCF(idx)-readCF(idx-1);
      }
};

int main()
{
    srand(time(0));
    const int MAX=100;
    int x;

    BIT B(MAX);

    for (int i=0;i<100;i++)
    {
        B.update(MAX*rand()/RAND_MAX,1);
    }
    while (cin>>x)
    {
          cout<<"CF: "<<B.readCF(x)<<endl;
          cout<<"F : "<<B.readF(x)<<endl;
    }
}
