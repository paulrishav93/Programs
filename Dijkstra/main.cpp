#include<iostream>
#include<vector>
#include<queue>
#define ii pair<int,int>

using namespace std;

class Graph
{
public:

    priority_queue<ii,vector<ii>, greater<ii> > Q;

    vector<int> distance;

    vector< vector<ii> > edge;

    int V;

    Graph(int vertices)
    {
        V=vertices;
        distance=vector<int> (V+1, 987654321);
        edge.resize(V+1);
    }

    void addEdge(int u, int v, int w)
    {
        edge[u].push_back(pair<int,int>(v,w));
       // edge[v].push_back(ii(u,w));
    }

    void dijkstra(int source)
    {
        distance[source]=0;

        Q.push(ii(0,source));

        while(!Q.empty())
        {
            ii top=Q.top();

            Q.pop();

            int d=top.first,v=top.second;

            if(d<=distance[v])
            {
                for(unsigned int i=0;i<edge[v].size();++i)
                {
                    int v2=edge[v][i].first;
                    int d2=edge[v][i].second;

                    if(distance[v2]>distance[v]+d2)
                    {
                        distance[v2]=distance[v]+d2;
                        Q.push(ii(distance[v2],v2));
                    }
                }
            }
        }
    }

    void printDistance()
    {
        for(int i=1;i<=V;++i)
            cout<<distance[i]<<" ";
    }
};

int main()
{
    Graph G(5);

    G.addEdge(1,2,1);
    G.addEdge(1,3,2);G.addEdge(2,3,2);G.addEdge(2,4,1);G.addEdge(1,4,5);G.addEdge(4,5,1);

    G.dijkstra(1);

    G.printDistance();

    return 0;
}
