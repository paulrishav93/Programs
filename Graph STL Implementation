#include <iostream>
#include <vector>
#include <queue>

#define usig unsigned long long

using namespace std;


class Graph
{

public:

    vector< vector<int> > edge;
    vector<bool> markeddfs;
    vector<bool> markedbfs;
    vector<int> distance;
    queue<int> Q;
    int vertices;
    usig cc,cv,perm;

    Graph(int V)
    {
        edge.resize(V+1);
        markeddfs = vector<bool> (V+1, 0);
        markedbfs = vector<bool> (V+1, 0);
        distance=vector<int> (V+1,-1);
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
        markeddfs[vertex]=1;

        cv++;

        for(int i=0;i<edge[vertex].size();++i)
        {
            int j=edge[vertex][i];

            if(!markeddfs[j])
                dfs(j);
        }
    }

    void bfs(int vertex)
    {
        Q.push(vertex);

        while(!Q.empty())
        {
            int v=Q.front();

            Q.pop();

            markedbfs[v]=true;
            cout<<v<<" ";

            for(int i=0;i<edge[v].size();++i)
            {
                int j=edge[v][i];
                if(!markedbfs[j])
                     Q.push(j);
            }
        }
    }

    void shortestpath(int source)
    {
        distance[source]=0;

        Q.push(source);

        while(!Q.empty())
        {
            int v=Q.front();

            Q.pop();

            markedbfs[v]=true;

            for(int i=0;i<edge[v].size();++i)
            {
                int j=edge[v][i];

                if(distance[j]==-1)
                {
                    distance[j]=distance[v]+1;
                    Q.push(j);
                }
            }
        }
    }

    void printDistance()
    {
        for(int i=1;i<=vertices;++i)
            cout<<distance[i]<<" ";

        cout<<endl;
    }

    void connected_components()
    {
        for(int i=1;i<=vertices;++i)
        {
            if(!markeddfs[i])
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

    Graph G(5);

    G.add_Edge(1,2);G.add_Edge(2,3);G.add_Edge(3,4);G.add_Edge(4,5);

    G.shortestpath(1);
    G.printDistance();

    return 0;
}
