//Dijkstra's

#include<bits/stdc++.h>
using namespace std;

#define MAX 10

class Graph
{
	int v;
	int mat[MAX][MAX];
	
	public:
	Graph(int x)
	{
		v=x;
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<MAX;j++)
				mat[i][j]=0;
		}
	}
	
	void get_matrix();
	void call_func(int);
	void dijkstra(int mat[][MAX],int x);
	int min_index(int distance[],bool visited[]);
};

void Graph::call_func(int source)
{
	dijkstra(mat,source);
}

int Graph::min_index(int distance[],bool visited[])
{
	int minn=INT_MAX,min_index;
	
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false && distance[i]<=minn)
		{
			minn=distance[i];
			min_index=i;
		}
	}
	
	return min_index;
}

void Graph::dijkstra(int mat[][MAX],int source)
{
	int distance[v];
	bool visited[v];
	
	for(int i=0;i<v;i++)
	{
		distance[i]=INT_MAX;
		visited[i]=false;
	}
	
	distance[source]=0;
	
	for(int i=0;i<v-1;i++)
	{
		int minn=min_index(distance,visited);
		visited[minn]=true;
		
		for(int j=0;j<v;j++)
		{
			if(visited[j]==false  && mat[minn][j] && ((distance[minn]+mat[minn][j])<distance[j]))
			{
				distance[j]=distance[minn]+mat[minn][j];
			}
		}
	}
	
	cout<<"\nDistance of each vertex from city "<<source<<"\n";
	for(int i=0;i<v;i++)
	{
		cout<<source<<" to "<<i<<" : ";
		cout<<distance[i]<<"\n";
	}
	
}

void Graph::get_matrix()
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cin>>mat[i][j];
		}
	}
}

int main()
{
	int v,source;
	cout<<"\nEnter the number of vertex: ";
	cin>>v;
	
	Graph G(v);
	cout<<"\nEnter the adjacency matrix\n";
	G.get_matrix();
	cout<<"\nEnter the source city: ";
	cin>>source;
	G.call_func(source);	
	return 0;
}
