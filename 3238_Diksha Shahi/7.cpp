//Hashing

#include<bits/stdc++.h>
#define MAX 10
using namespace std;

class hashing
{
    int n,data[MAX],flag[MAX],chain[MAX];
    
    public:
    hashing(int size)
    {
        n=size;
        
        for(int i=0;i<n;i++)
        {
            flag[i]=0;
            chain[i]=-1;
        }    
    }
    void insertion_r(int);
    void insertion_wr(int);
    void deletion(int);
    void display();
    void searching(int);
};

void hashing::searching(int x)
{
    int pos=x%n,f=0;
    
    if(data[pos]==x)
    {
        cout<<"\nElement found at position: "<<pos;
        return;
    }
    else
    {
        int j;
        while(data[pos]%n==pos || chain[pos]!=-1)
        {
            pos=chain[pos];
            if(data[pos]==x)
            {
                cout<<"\nElement found at: "<<pos;
                f=1;
            }
        } 
        
        while(f==0 && flag[pos]==1)
        {
            pos=(pos+1)%n;
            if(data[pos]==x)
            {
             f=1;
             cout<<"\nElement found at position: "<<pos;
            } 
        }   
        
        if(f==0)
        cout<<"\nElement not found!";
    }
}

void hashing::deletion(int x)
{
    int pos=x%n;
    if(flag[pos]==0)
        cout<<"\nBlock is empty! ";
    else
    {
  
        int j=data[pos]%n;
        while(chain[pos]!=-1 &&data[pos]!=x )
        {
            pos=chain[pos];
            j=pos-1;
        }
        int k=pos;
       
        flag[k]=0;
        chain[j]=chain[k];
        chain[k]=-1;
    }
}

void hashing::display()
{
    for(int i=0;i<n;i++)
    {
        if(flag[i]==1)
        {
            cout<<"\t"<<i<<"\t"<<data[i]<<"\t"<<chain[i];
        }
        else
        {
            cout<<"\t"<<i<<"\t"<<"----"<<"\t"<<chain[i];
        }
        cout<<"\n";
    }
}

void hashing::insertion_r(int x)
{
    int pos,cnt=0; 
    pos=x%n;
    
    //Element is not present at pos
    if(flag[pos]==0)
    {
        data[pos]=x;
        flag[pos]=1;
    } 
    //Element present both have same hash value  
    else if(data[pos]%n == pos)
    {
        int i=pos; 
        while(flag[i]==1 && cnt<n)
        {
            i=(i+1)%n;
            cnt++;
        }
        
        if(cnt==n)
        {
            cout<<"\nHash table is full! ";
            return;
        }
            
        while(chain[pos]!=-1)
        {
            pos=chain[pos];
        }
        data[i]=x;
        flag[i]=1; 
        chain[pos]=i; 
    } 
    //Element present both have different hash value
    else
    {
        int i=pos; 
        while(flag[i]==1 && cnt<n)
        {
            i=(i+1)%n;
            cnt++;
        } 
        if(cnt==n)
        {
            cout<<"\nHash table is full! ";
            return;
        }
        int j=data[pos]%n;
        while(chain[j]!=pos)   
        {
            j=chain[j];
        }
        chain[j]=chain[pos];
        
        while(chain[j]!=-1)
        {
            j=chain[j];
        }
        data[i]=data[pos];
        flag[i]=1;
        chain[j]=i;
        data[pos]=x;
        chain[pos]=-1;
    }
}

void hashing::insertion_wr(int x)
{
    int pos,cnt=0; 
    pos=x%n;
    int i=pos;
    if(flag[pos]==0)
    {
        data[pos]=x;
        flag[pos]=1;
        return;
    } 
    while(flag[i]==1 && cnt<n)
    {
        i=(i+1)%n;
        cnt++;
    } 
    if(cnt==n)
    {
        cout<<"\nHash table is full! ";
        return;
    }
    
    {
        
        for(int k=pos;k<=9;k++)
        {
            if(data[k]%n==pos && chain[k]==-1)
            {
                chain[k]=(k+1)%n;
                break;
            }      
        }
    }    
    
    data[i]=x;
    flag[i]=1;
    
}

int main()
{
    int size,choice;
    cout<<"\nEnter the size of the hash table: ";
    cin>>size; 
    hashing obj(size);
       
    do
    {
        
        cout<<"\n1.Insert (Replacement)";
        cout<<"\n2.Insert (Without Replacement)";
        cout<<"\n3.Deletion";
        cout<<"\n4.Searching";
        cout<<"\n5.Display ";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            {
                int x;
                cout<<"\nEnter the element: ";
                cin>>x;
                obj.insertion_r(x);      
                break;
            }
            case 2:
            {
                int x;
                cout<<"\nEnter the element: ";
                cin>>x;
                obj.insertion_wr(x);      
                break;
            }
            case 3:
            {
                int x;
                cout<<"\nEnter the elements:  ";
                cin>>x;
                obj.deletion(x);
                break;
            }
            case 4:
            {
                int x;
                cout<<"\nEnter the elements:  ";
                cin>>x;
                obj.searching(x);
                break;
            }
            case 5:
            {
                obj.display();
                break;
            }
           
        }
    }while(choice<=5);
    return 0;
}
