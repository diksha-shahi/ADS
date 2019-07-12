//Topological sort

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;
 public:
	Graph(int x)
	{
		v=x;
		adj=new list<int>[v];
	}
	void addEdges(int a,int b);
	void top_sort();
	void sort_until(int i,bool visited[],stack<int>&S);	
};

void Graph::sort_until(int i,bool visited[],stack<int>&S)
{
	visited[i]=true;
	
	list<int>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++)
	{
		if(visited[*it]==false)
		{
			sort_until(*it,visited,S);
		}
	}
	
	S.push(i);
}

void Graph::top_sort()
{
	stack<int> S;
	bool visited[v];
	
	for(int i=0;i<v;i++)
		visited[i]=false;
		
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			sort_until(i,visited,S);		
		}
	}
	
	while(S.empty()==0)
	{
		int x=S.top();
		cout<<x<<" ";
		S.pop();
	}		
}

void Graph::addEdges(int a,int b)
{
	adj[a].push_back(b);
}

int main()
{
	int v,e,a,b;
	cout<<"\nEnter the number of vertices:";
	cin>>v;
	Graph G(v);	
	
	cout<<"\nEnter the number of edges: ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		G.addEdges(a,b);
	}

	cout<<"\nTopological sorted order is: ";
	G.top_sort();
	cout<<"\n";
	
	return 0;
}
