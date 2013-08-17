#include <iostream>
using namespace std;

void buildheap(int A[], int length);
void heapify(int A[], int heapsize, int root);

void heapsort(int A[], int length)//	       (takes O(n lg n) time)
{
	int heapsize = length;

	buildheap(A, length);	//Take the unsorted list and make it a heap

	for (int i = length-1; i >=2; i--)
	{
		swap(A[1], A[i]);
		heapsize--;
		heapify(A, heapsize, 1);
	}
}

void buildheap(int A[], int length)	//     (takes O(n) time)
{
	for (int i = ((length)/2); i >= 1 ; i--)
		heapify(A, length, i);
}

void heapify(int A[], int heapsize, int root) //(takes O(h) time,
					// h is the height of root
{
	int left = 2*root,
		right = 2*root +1,
		largest;

	if ( (left < heapsize) && (A[left] > A[root]))
		largest = left;
	else
		largest = root;

	if ( (right < heapsize) && (A[right] > A[largest]))
		largest = right;

	if (largest != root)
	{
		swap(A[root], A[largest]);
		heapify(A, heapsize, largest);
	}
}
class graph
{

private:
    bool *color;
    int vertices;
    void addVertex(int u, int v)
    {
        node *temp=&ptr[u];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new node(v);
    }
public:

    int V()
    {
        return vertices;
    }
    class node
    {
    public:
        node(int name)
        {
            label=name;
            next=NULL;
        };

        node(){next=NULL;};

        int label;

        node *next;
    };

    class edge
    {
    public:
        edge(int u, int v)
        {
            U=u;
            V=v;
            next=NULL;
        }

        int U,V;

        edge *next;
    };

    node *ptr;
    bool *marked;
    edge *edgeList;
    edge *edgeTemp;
    graph(int v)
    {
        ptr=new node[v+1];
        vertices=v;
        for(int i=1;i<=v;++i)
            ptr[i].label=i;

        marked=new bool[V()+1];

        for(int i=1;i<=V();++i)
            marked[i]=false;

        edgeList=NULL;
    }

    void addEdge(int u, int v)
    {
        addVertex(u,v);
        //addVertex(v,u);       For undirected graphs only

        if(!edgeList)
        {
            edgeList=new edge(u,v);
            edgeTemp=edgeList;
        }

        else
        {
            edgeTemp->next=new edge(u,v);
            edgeTemp=edgeTemp->next;
        }

    }

    void printEdges()
    {
        edge *temp=edgeList;


        while(temp)
        {
            cout<<temp->U<<"-"<<temp->V<<endl;
            temp=temp->next;
        }
    }


    int *id=new int[V()+1];
    int *arrival=new int[V()+1];
    int *departure=new int[V()+1];
    int time=1;
    int count=1;

    void dfs(int vertex)
    {
        marked[vertex]=1;
        id[vertex]=count;

        arrival[vertex]=time++;

        node *temp=&ptr[vertex];
        int v=vertex;

        while(temp->next)
        {
            temp=temp->next;
            vertex=temp->label;
            if(!marked[vertex])
                dfs(vertex);
        }

        departure[v]=time++;    //cannot use departure[vertex] as value of 'vertex' has changed
    }

    void connectedComponent()
    {


        for(int v=1;v<=V();v++)
        {
            if(!marked[v])
            {
                dfs(v);
                count++;
            }
        }

        for(int v=1;v<=V();v++)
            cout<<id[v]<<" ";
    }

    void topologicalSort()
    {
        int *topSortArray=new int[V()];

        for(int i=1;i<=V();++i)
            topSortArray[i]=departure[i];

        for(int i=1;i<=V();++i)
            cout<<topSortArray[i]<<" ";

        heapsort(topSortArray,V()+1);

        cout<<endl<<V()<<endl;

        int j=V();
        int i=1;
        while(i<j)
            swap(topSortArray[i++],topSortArray[j--]);

        for(int i=1;i<=V();++i)
        {
            for(int j=1;j<=V();++j)
            {
                if(departure[j]==topSortArray[i])
                {
                    topSortArray[i]=j;
                }
            }
        }
        cout<<endl;
        for(int i=1;i<=V();++i)
            cout<<topSortArray[i]<<" ";
    }

};

int main()
{
    graph Graph(2);


    for(int i=1;i<=Graph.V();++i)
    if(!Graph.marked[i])
    Graph.dfs(i);

    //Graph.topologicalSort();

    return 0x0;
}
