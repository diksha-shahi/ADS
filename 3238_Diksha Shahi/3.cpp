//TBST operations

#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left;
	node *right;
	bool leftThread;
	bool rightThread;
	node()
	{
		leftThread=true;
		rightThread=true;
	}
	
	friend class tbst;
};

class tbst
{
	public:
	
	node *dummy,*root;
	tbst()
	{
		dummy=new node;
		dummy->left=dummy;
		dummy->right=dummy;
		root=NULL;
	}
	
	void create(int);
	void inorder();
	void preorder();
	void postorder();
	void deletion(int);
	node* lsubc(node*);
	node* rsubc(node*);
	node* lsubp(node *);
	
};

node* tbst::lsubc(node* temp)
{
	while(1)
	{
		if(temp->leftThread==true)
			return temp;
	
		temp=temp->left;
	}
}

node* tbst::rsubc(node* temp)
{
	while(1)
	{
		if(temp->rightThread==true)
			return temp;
	
		temp=temp->right;
	}
}

node* tbst::lsubp(node* temp)
{
	while(1)
	{
		if(temp->left->leftThread==true)
			return temp;
		
		temp=temp->left;
	}
}

void tbst::deletion(int s)
{
   	if(root==NULL)
   		return;
   
	int temp;
	node *p=root;
	node *c=root;
	node *t,*tc,*tp;

	while(1)
	{
		if(c->data==s)
		{
			if(p==c)
			{
				if(c->rightThread==true&&c->leftThread!=true)
				{
					root=c->left;
					dummy->left=root;
					rsubc(root)->right=dummy;
					delete p;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->rightThread!=true&&c->leftThread==true)
				{
					root=c->right;
					dummy->left=root;
					lsubc(root)->left=dummy;
					delete p;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->rightThread==true&&c->leftThread==true)
				{
					root=NULL;
					dummy->left=dummy;
					dummy->leftThread=true;
					delete p;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->right->leftThread==true)
				{
					swap(c->data,c->right->data);
					p=c;
					c=c->right;
				}
				else
				{
					tc=lsubc(c->right);
					tp=lsubp(c->right);
					swap(c->data,tc->data);
					p=tp;
					c=tc;
				}
			}
	else if(p->right==c)
			{	if(c->rightThread==true&&c->leftThread!=true)
				{
					p->right=c->left;
					p=p->right;
					
					while(p->rightThread!=true)
				    	p=p->right;
					
					p->right=c->right;
					delete c;
					
					cout<<"Delete Complete***"<<endl;
					return;
				}
				else if(c->rightThread!=true&&c->leftThread==true)
				{
					p->right=c->right;
					p=p->right;
					
					while(p->leftThread!=true)
				     	p=p->left;
					
					p->left=c->left;
					delete c;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->rightThread==true&&c->leftThread==true)
				{
					p->right=c->right;
					p->rightThread=true;
					delete c;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->right->left==NULL)
				{
					swap(c->data,c->right->data);
					p=c;
					c=c->right;
				}
				else
				{
					tc=lsubc(c->right);
					tp=lsubp(c->right);
					swap(c->data,tc->data);
					p=tp;
					c=tc;
				}
			}
	else if(p->left==c)
			{	if(c->rightThread==true&&c->leftThread!=true)
				{
					p->left=c->left;
					p=p->left;
				   
				   	while(p->rightThread!=true)
				     	p=p->right;
				   
				   	p->right=c->right;
					delete c;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->rightThread!=true&&c->leftThread==true)
				{
					p->left=c->right;
					p=p->left;
					
					while(p->leftThread!=true)
						p=p->left;
					
					p->left=c->left;
					delete c;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->rightThread==true&&c->leftThread==true)
				{
					p->left=c->left;
					p->leftThread=true;
					delete c;
					
					cout<<"Delete Complete"<<endl;
					return;
				}
				else if(c->right->leftThread==true)
				{
					swap(c->data,c->right->data);
					p=c;
					c=c->right;
				}
				else
				{
					tc=lsubc(c->right);
					tp=lsubp(c->right);
					swap(c->data,tc->data);

					p=tp;
					c=tc;
				}
			}

	}
	else if(s<c->data&&c->leftThread!=true)
	{
		if(p==c)
		{
			c=c->left;
		}
		else
		{
			p=c;
			c=c->left;
		}
	}
	else if(s>c->data&&c->rightThread!=true)
	{
		if(p==c)
		{
			c=c->right;
		}
		else
		{
			p=c;
			c=c->right;
		}
	}
	else
	{
		cout<<"Number not found!!"<<endl;
		return;
	}
}
}


void tbst::postorder()
{
   	node *t=root;
	
	if(t==NULL)
	{
		return;
	}
	else
	{
		while(1)
		{
			if(t==dummy)
				return;
			
			while(t->leftThread!=true)
			{
				t=t->left;
			}
	
			if(t->rightThread==false)
			{
				t=t->right;
			}
			else
			{
			 while(t!=dummy&&t->rightThread!=false)
		      	 {
		      		node *n=t;
		      		node *m=t;
		         
		         	cout<<t->data<<" ";
		         
		         	if(lsubc(n)->left->right==t)
		           	{
		           		 cout<<lsubc(n)->left->data<<" ";
		           		 n=n->left;
		           	 	m=m->left;
		           	 
		           	 	while(n->left!=dummy&&lsubc(n)->left->right==m)
		           	 	{
		           			cout<<lsubc(n)->left->data<<" ";
		           		 	n=n->left;
		           	 		m=m->left;
		           	 	}
		           	}
		          
		          	t=t->right;
		      	}
		      
		      	if(t==dummy)   
		      		return;
		      
		      	t=t->right;
		   }
   		}
   }
}

void tbst::inorder()
{
	node *current=root;
	
	if(current==NULL)
		return;
	else
	{
		while(1)
		{
			if(current==dummy)
				return;
			
			while(current->leftThread==false)
			{
				current=current->left;
			}	
			
			cout<<current->data<<" ";
			
			if(current->rightThread==false)
			{
				current=current->right;
			}
			else
			{
				if(current->right==dummy)
					return;
				
				while(current->rightThread==true && current->right!=dummy)
				{
					cout<<current->right->data<<" ";
					current=current->right;
				}	
				
				current=current->right;
			}
		}
	}	
}

void tbst::preorder()
{
	node *current=root;
	
	if(current==NULL)
		return;
	else
	{
	while(1)
	{
		if(current==dummy)
			return;
		
		while(current->leftThread==false)
		{
			cout<<current->data<<" ";
			current=current->left;
		}	
		
		cout<<current->data<<" ";
		
		if(current->rightThread==false)
		{
			current=current->right;
		}
		else
		{
			if(current->right==dummy)
				return;
			while(current->rightThread==true && current->right!=dummy)
			{
				current=current->right;
			}	
			current=current->right;
		}
	}	
	}	
}

void tbst::create(int val)
{
	node *new_node=new node;
	new_node->data=val;
	
	if(root==NULL)
	{
		root=new_node;
		dummy->left=root;
		dummy->leftThread=false;
		new_node->left=dummy;
		new_node->right=dummy;
	}
	else
	{
		node *current=root;
		
		while(1)
		{
			if(current->data > new_node->data)
			{
				if(current->leftThread==true)
				{
					new_node->left=current->left;
					current->left=new_node;
					new_node->right=current;
					current->leftThread=false;
					break;
				}
				else
					current=current->left;
			}
			else
			{
				
				if(current->rightThread==true)
				{
					new_node->right=current->right;
					current->right=new_node;
					new_node->left=current;
					current->rightThread=false;
					break;
				}	
				else
					current=current->right;
			}
		}
	}
}



int main()
{
	tbst obj;
	int choice;
	
	while(1)
	{
		cout<<"\nMENU\n";
		cout<<"1. Insertion\n";
		cout<<"2. Inorder traversal\n";
		cout<<"3. Preorder traversal\n";
		cout<<"4. Postorder traversal\n";
		cout<<"5. Deletion\n";
		cout<<" Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				int x;
				cout<<"\nValue: ";
				cin>>x;
				obj.create(x);
				break;
			case 2:
				obj.inorder();
				cout<<"\n";
				break;
			case 3:
				obj.preorder();
				cout<<"\n";
				break;
			case 4:
				obj.postorder();
				cout<<"\n";;
				break;
			case 5:
				cout<<"Enter number to be deleted: ";
				cin>>x;
				obj.deletion(x);
				cout<<"\n";
				break;		
			default:
				exit(0);			
		}
	}		
	return 0;
}
