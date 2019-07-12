//Prim,Kruskal

#include<bits/stdc++.h>
using namespace std;

class EdgeList;

class phone
{
	public:
	int data[10][10];
	int n;
	phone(int v);
	void read_graph();
	void prim();
	void kruskal(EdgeList &obj);
	int min_cost(int[],bool[]);
	int find(int A[], int v);
	void Union(int B[], int p,int q);
};

class Edge
{
	public:
	int x,y,w;
	Edge()
	{
		;
	}
	Edge(int a,int b,int weight)
	{
		x=a;
		y=b;
		w=weight;
	}
	friend class phone;
	friend class EdgeList;
};

class EdgeList
{	
	public:
	int n;
	Edge data[10];
	EdgeList()
	{
		n=0;
	}
	
	void sort();
	void print();
};

void EdgeList::print()
{
	int cost=0;
	
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<data[i].x+1<<"-"<<data[i].y+1<<" = "<<data[i].w;
		cost=cost+data[i].w;
	}
	
	cout<<"\nMINIMUM COST: "<<cost<<"\n";
}

void EdgeList::sort()
{
	Edge temp;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(data[j].w>data[j+1].w)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}	
	}
}

int phone::min_cost(int cost[],bool visited[])
{
	int minn=INT_MAX,min_index;
	
	for(int i=0;i<n;i++)
	{
		if(cost[i]<minn && visited[i]==false)
		{
			minn=cost[i];
			//visited[i]=true;
			min_index=i;
		}
	}
	
	return min_index;
}

void phone::prim()
{
	bool visited[n];
	int parent[n];
	int cost[n];
	
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
		cost[i]=INT_MAX;
	}
	
	parent[0]=-1;
	cost[0]=0;
	
	for(int i=0;i<n-1;i++)
	{
		int k=min_cost(cost,visited);
		visited[k]=true;
		
		for(int j=0;j<n;j++)
		{
			if(data[k][j] && visited[j]==false & data[k][j]<cost[j])
			{
				parent[j]=k;
				cost[j]=data[k][j];
			}
		}
	}
	
	cout<<"\nMinimum cost TELEphone map: \n";
	int min_cost=0;
	for(int i=1;i<n;i++)
	{
		cout<<i+1<<"-"<<parent[i]+1<<","<<cost[i];
		min_cost+=cost[i];
		cout<<"\n";
	}
	
	cout<<"\nMINIMUN COST: "<<min_cost;
}

void phone::kruskal(EdgeList &obj)
{
	EdgeList E;
	int A[10],p,q;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(data[i][j]!=0)
			{
				E.data[E.n]=Edge(i,j,data[i][j]);
				E.n++;
			}			
		}
	}
	
	E.sort();
	
	for(int i=0;i<n;i++)
		A[i]=i;
		
	for(int i=0;i<E.n;i++)
	{
		p=find(A,E.data[i].x);
		q=find(A,E.data[i].y);
		
		if(p!=q)
		{
			obj.data[obj.n]=E.data[i];
			obj.n++;
			Union(A,p,q);
		}
	}	
}

void phone::Union(int A[],int p,int q)
{
	for(int i=0;i<n;i++)
	{
		if(A[i]==q)
			A[i]=p;
	}
}
int phone::find(int A[],int v)
{
	return A[v];
}

phone::phone(int num)
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			data[i][j]=0;
	}
	n=num;
}

void phone::read_graph()
{
	cout<<"Enter adjacency matrix: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cin>>data[i][j];
	}
}


int main()
{
	int v,choice;
	cout<<"Enter number of cities: ";
	cin>>v;
	
	phone P(v);
	EdgeList obj;
	
	do
	{
		cout<<"\n1. Input graph ";
		cout<<"\n2. Minimum cost (Prim's algorithm) ";
		cout<<"\n3. Minimum cost (Kruskal's algorithm )";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				P.read_graph();
				break;
			case 2:
				P.prim();
				break;
			case 3:
				P.kruskal(obj);
				obj.print();
				break;
			default:
				cout<<"Wrong choice";			
		}
		
	}while(choice<5 && choice>0);
	
	return 0;
}
