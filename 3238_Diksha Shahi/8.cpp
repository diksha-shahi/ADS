//OBST operations

#include<bits/stdc++.h>
using namespace std;

#define MAX 10
int keys[MAX],p[MAX],q[MAX];

struct node
{
    int key;
    node *left,*right;
};

class obst
{
    int n;
    int R[MAX][MAX],C[MAX][MAX],W[MAX][MAX];
    public:
    obst(int m)
    {
        n=m;
        for(int i=0;i<=n;i++)
        {
            for(int  j=0;j<=n;j++)
            {
            R[i][j]=0;
            C[i][j]=0;
            W[i][j]=0;
            }
        }        
    }
    node* construct(int,int);
    void display(node* root);
    int cost(int*,int*,int);
};

void obst::display(node* root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        display(root->left);
        display(root->right);
    }
}

node* obst::construct(int i,int j)
{
    node* p;
    
    if(i==j)
        p=NULL;
    else
    {
        p=new node;
        p->key=keys[R[i][j]];
        p->left=construct(i,R[i][j]-1);
        p->right=construct(R[i][j],j);
    }
    
    return p;    
}

int obst::cost(int* p,int* q,int n)
{
    //Constructing the weight matrix
    for(int i=0;i<=n;i++)
    {
        W[i][i]=q[i];
        
        for(int j=i+1;j<=n;j++)
        {
            W[i][j]=W[i][j-1]+p[j]+q[j];
        }
    }    
    
    //Constructing the cost matrix
    for(int i=0;i<=n;i++)
    {
        
        C[i][i]=W[i][i];
    }
    
    for(int i=0;i<=n-1;i++)
    {
        int j=i+1;
        C[i][j]=C[i][i]+C[j][j]+W[i][j];
        R[i][j]=j;
    }
    
    for(int h=2;h<=n;h++)
    {
        for(int i=0;i<=n-h;i++)
        {
            int j=i+h;
            int m=R[i][j-1];
            int min=C[i][m-1]+C[m][j];
            for(int k=m+1;k<=R[i+1][j];k++)
            {
                int x=C[i][k-1] + C[k][j];
                if(x<min)
                {
                    m=k;
                    min=x;
                }
            }
            C[i][j]=W[i][j]+min;
            R[i][j]=m;
        }
    }
 
    cout<<"\nThe weight matrix: ";   
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<W[i][j]<<" ";
        
        cout<<"\n";
    }
    
    cout<<"\nThe cost matrix: ";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<C[i][j]<<" ";
        
        cout<<"\n";
    }
    
    cout<<"The root matrix: ";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<W[i][j]<<" ";
        
        cout<<"\n";
    }
    return C[0][n];
}

int main()
{
    int n;
    cout<<"\nEnter the number of keys: ";
    cin>>n;
    obst obj(n);
    
    for(int i=1;i<=n;i++)
    {
        cout<<"Keys["<<i<<"]:";
        cin>>keys[i];
        cout<<"p["<<i<<"]:";
        cin>>p[i];    
    }
    
    for(int i=0;i<=n;i++)
    {
       cout<<"q["<<i<<"]:";
        cin>>q[i];   
    }
    
    int c=obj.cost(p,q,n);
    cout<<"\nMinimum cost: "<<c;
    node* root=obj.construct(0,n);
    cout<<"\nInorder traversal";
    obj.display(root);
    cout<<"\n";
    return 0;
}
