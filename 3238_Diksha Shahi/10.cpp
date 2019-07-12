//Set operations

#include <bits/stdc++.h>
#define MAX 30

using namespace std;


class Set
{
	int data[MAX];
	int n;
public:
	Set()
{
		n=-1;
}
	bool insert(int);
	bool remove(int);
	bool contains(int);
	int size();
	void display();
	void input(int num);
	Set unionS(Set,Set);
	Set intersection(Set,Set);
	Set difference(Set,Set);
	void subset(Set);
	int isSubset(int* A, Set s1,int m);
};


int Set::isSubset(int* A,Set s1,int m)
{
 int i=0,j=0,flag=0;
 sort(A,A+n);
 
 for(int i=0; i<m; i++)
 {
  for(int j=0; j<s1.n;j++)
  {
   if(A[i]==s1.data[j])
   {
    flag=0;
    break;
   }
   else
    flag=1;
  }
  
  if(flag==1)
   return 0;
 
 }
 return 1;

}


void Set::subset(Set s1)
{
 int val=pow(2,(s1.n+1));
 for(int i=0;i<val;i++)
 {
  cout<<"{";
  for(int j=0;j<s1.n;j++)
  {
   if(i&(1<<j))
  	cout<<s1.data[j]<<" ";
  }
  cout<<"}";
 }

}


void Set::input(int num)
{
	int value;
	for(int i=0;i<num;i++)
	{
		cout<<"\nEnter values: ";
		cin>>value;
		insert(value);
	}
}

void Set::display()
{
	for(int i=0;i<=n;i++)
		cout<<" "<<data[i];
}

Set Set::unionS(Set s1,Set s2)
{
	Set s3;

	int flag=0;
	int i=0;
	for(i=0;i<=s1.n;i++)
	{
		s3.insert(s1.data[i]);
	}
	for(int j=0;j<=s2.n;j++)
	{
		flag=0;
		for(i=0;i<=s1.n;i++)
		{
			if(s1.data[i]==s2.data[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			s3.insert(s2.data[j]);

		}
	}

	return s3;
}


Set Set::difference(Set s1,Set s2)
{
	Set s3;
	int flag=1;
	for(int i=0;i<=s1.n;i++)
	{
		for(int j=0;j<=s2.n;j++)
		{
			if(s1.data[i]==s2.data[j])
			{
				flag=0;
				break;
			}
			else flag=1;
		}
		if(flag==1)
		{
			s3.insert(s1.data[i]);

		}
	}
	return s3;
}


Set Set::intersection(Set s1,Set s2)
{
	Set s3;
	for(int i=0;i<=s1.n;i++)
	{
		for(int j=0;j<=s2.n;j++)
		{
			if(s1.data[i]==s2.data[j])
			{
				s3.insert(s1.data[i]);
				break;
			}
		}
	}
	return s3;
}


bool Set::insert(int value)
{
	if(n>=MAX)
	{
		cout<<"\nOverflow.Set is full.\n";
		return false;
	}
	
	for(int i=0;i<n;i++)
	{
	 if(value==data[i])
	  return false;
	}
	
	data[++n]=value;
return true;
}


bool Set::remove(int value)
{
	if(n==-1)
	{
		cout<<"Set is empty";
		return false;
	}
	for(int i=0;i<=n;i++)
	{
		if(data[i]==value)
		{
			for(int j=i;i<=n;j++)
			{
				data[j]=data[j+1];
			}
			return true;
		}
	}

	return false;
}

bool Set::contains(int value)
{
	for(int i=0;i<=n;i++)
	{
		if(data[i]==value)
			return true;
	}
	return false;
}

int Set::size()
{
	return n+1;
}


int main()
{
 Set s1,s2,s3,s4;
 int ch,a;
 int value;

 cout<<"\nEnter number of values in Set A: ";
 cin>>value;
 s1.input(value);

 cout<<"\nEnter number of values in Set B:";
 cin>>value;
 s2.input(value);
 do
 {
  cout<<"\n1.Insert\n2.Remove\n3.Search\n4.Size of Set\n5.Intersection\n6.Union\n7.Difference\n8.Check if SubSet";
  cout<<"\nEnter Your Choice: ";
  cin>>ch;
  
  switch(ch)
  {
   case 1:
	cout<<"\nEnter value: ";
	cin>>value;
	if(s1.insert(value))
	{
	 cout<<value<<" inserted";
	}
	else
	{
	 cout<<"Insertion Failed";
	}
	break;
	
   case 2:
	cout<<"\nEnter value: ";
	cin>>value;
	if(s1.remove(value))
	{
	 cout<<value<<" deleted";
	}
	else
	{
	 cout<<"Deletion Failed";
	}
	break;
		
   case 3:
	cout<<"\nEnter value: ";
	cin>>value;
	if(s1.contains(value))
	{
	 cout<<value<<" is present";
	}
	else
	{
	 cout<<value<<"is not  Present";
	}
	break;
   
   case 4:
	cout<<"\nSize = "<<s1.size();
	break;
		
   case 5:
	s3=s1.intersection(s1,s2);
	cout<<"\nSet A values: ";
	s1.display();
	cout<<"\nSet B values: ";
	s2.display();
	cout<<"\nIntersection: :";
	s3.display();
	break;

   case 6:
	s3=s1.unionS(s1,s2);
	cout<<"\nSet A values: ";
	s1.display();
	cout<<"\nSet B values: ";
	s2.display();
	cout<<"\nUnion :";
	s3.display();
	break;
		
   case 7:
	s3=s1.difference(s1,s2);
	cout<<"\nSet A values: ";
	s1.display();
	cout<<"\nSet B values: ";
	s2.display();
	cout<<"\nDifference :";
	s3.display();
	break;
  case 8:
       //s2.subset(s1);
       cout<<"nuber of values in array: ";
       cin>>a;
       int arr[a];
       cout<<"\nEnter the array values:\n";
       for(int i=0;i<a;i++)
        cin>>arr[i];
    
       int k=s1.isSubset(arr,s1,a);
       
       if(k==1)
         cout<<"is a subset";
       else
         cout<<"not a subset"; 
       break;

  }
 }while(ch!=0);

return 0;
}
