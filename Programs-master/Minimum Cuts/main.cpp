#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;


class graph
{
public:
    class edge;
    class node
    {
    public:
        edge* nodeEdgePtr;
        edge* tempPtr;
        node(int i)
        {
            label=i;
            tempPtr=NULL;
            nodeEdgePtr=NULL;
        }

        node()
        {
            tempPtr=NULL;
            nodeEdgePtr=NULL;
        }

        void addEdge(edge* e)
        {
            if(nodeEdgePtr==NULL)
            {
                nodeEdgePtr=e;
                tempPtr=e;
                return;
            }

            tempPtr->next=e;
            tempPtr=tempPtr->next;
        }

        int label;
    };

    node* nodeptr;

    class edge
    {
    public:
        edge(int u, int v)
        {
            U=u;
            V=v;
            next=NULL;
        }

        edge()
        {
            next=NULL;
        }
        edge* next;
        int U,V;
    };

    edge* edgeptr;

    graph(int vertices)
    {
        int v=vertices;
        nodeptr=new node[v+1];

        for(int i=1;i<=v;++i)
            nodeptr[i].label=i;

        edgeptr=new edge[3000];
    }
};
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("kargerMinCut.txt");
    fout.open("Output.txt");

   for(int i=1;i<=30;++i)
   {
        int a;
        fin>>a;
        cout<<a<<'\t';

   }
    //graph G(200);
    return 0;
}
