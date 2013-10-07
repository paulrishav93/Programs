#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define edge pair< int, int>

class Graph
{
public:
    vector< pair < int, edge > > graph, MST;
    int totalCost, V, E;
    vector<int> parent;

    Graph(int vertices, int edges)
    {
        V=vertices;
        E=edges;
        parent.resize(V+1);

        for(int i=1;i<=V;++i)
            parent[i]=i;
    }

    void reset()
    {
        MST.clear();
        graph.clear();
        for(int i=1;i<=V;++i)
            parent[i]=i;
    }

    void insertEdge(int u, int v, int w)
    {
    	graph.push_back(pair< int, edge >(w, edge(u, v)));
    }

    int findSet(int x, vector<int> parent)
    {
        if(x!=parent[x])
            parent[x]=findSet(parent[x],parent);

        return parent[x];
    }

    void kruskal()
    {
        int i, parentu, parentv, MSTsize;

        totalCost=0;

        sort(graph.begin(),graph.end());

        for(i=0; i<E;++i)
        {
            parentu=findSet(graph[i].second.first,parent);
            parentv=findSet(graph[i].second.second,parent);

            if(parentu!=parentv)
            {
                MST.push_back(graph[i]);
                totalCost+=graph[i].first;
                parent[parentu]=parent[parentv];
            }
        }

        MSTsize=MST.size();

        for(i=0; i<MSTsize; ++i)
        {

            cout<<MST[i].second.first<<" "<<MST[i].second.second<<" "<<MST[i].first<<endl;
        }

        cout<<totalCost<<endl;
    }
};

int main()
{
    int V,E,u,v,w;
    cout<<"Enter number of vertices and edges\n";
    cin>>V>>E;

    Graph G(V,E);

    for(int i=0;i<E;++i)
    {
    	cin>>u>>v>>w;
    	G.insertEdge(u,v,w);
    }

    G.kruskal();
}
