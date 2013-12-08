#include <iostream>
#include<vector>

#define usig unsigned long long

using namespace std;


class Graph
{

public:

    vector< vector<int> > edge;
    vector<bool> marked;
    int vertices;
    usig cc,cv,perm;

    Graph(int V)
    {
        edge.resize(V+1);
        marked = vector<bool> (V+1, 0);
        vertices=V;
        cc=0,cv=0;perm=1;
    }

    void add_Edge(int a, int b)
    {
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    void dfs(int vertex)
    {
        marked[vertex]=1;

        cv++;

        for(int i=0;i<edge[vertex].size();++i)
        {
            int j=edge[vertex][i];

            if(!marked[j])
                dfs(j);
        }
    }

    void connected_components()
    {

        for(int i=1;i<=vertices;++i)
        {
            if(!marked[i])
            {
                cc++;

                cv=0;

                dfs(i);

                perm=cv * perm % 1000000007;


            }
        }

        cout<<cc<<" "<<perm<<endl;
    }

};

int main()
{

    int T,N,M,I,J;

    cin>>T;

    while(T--)
    {
        cin>>N>>M;

        Graph G(N);

        for(int h=1; h<=M; ++h)
        {
            cin>>I>>J;

            G.add_Edge(I,J);
        }

        G.connected_components();
    }
    return 0;
}
