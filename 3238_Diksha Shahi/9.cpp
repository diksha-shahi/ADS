//AVL operations

#include <iostream>

using namespace std;

class node
{
 int height;;
 string meaning,key;
 node *left,*right;

public:
 	node()
	{
  	 left=right=NULL;
   	 height=1;
  	 meaning="";
  	 key=-1;
	}
 	
 	node(string key,string meaning)
 	{
  	 this->key=key;
  	 this->meaning=meaning;
  	 left=right=NULL;
 	 height=1;
 	}
 
 
 void print()
 {
  cout<<"\n"<<"\t"<<key<<"\t"<<meaning;
 }
 
 friend class Dictionary;
};


class Dictionary
{
 node *root;

public:
	 Dictionary()
	{
	  root=NULL;
	}

 int max(int,int);
 int getheight(node*);
 node *insert(node *rnode,string key,string meaning);
 void Avl(string key,string meaning);
 node *rightRotate(node *);
 node *leftRotate(node *);
 int getbalance(node*);
 void preorder();
 void preorderRec(node*);
 void postorder();
 void postorderRec(node *);
 void inorder();
 void inorderRec(node *);
 void fUpdate(node*);
 void update()
 {
  fUpdate(root);
 }
 node* minValue(node* t)
 {
 	node *current = t;
 	while(current->left!=NULL)
 	   current = current->left;
  return current;	
 }
 void deletenode(string dkey){
	delete_node(root,dkey); 
 }
 node* delete_node(node*, string);
};


int Dictionary::max(int a,int b)
{
 return (a>b)?a:b;
}


int Dictionary::getheight(node *nnode)
{
 if(nnode==NULL)
  return 0;
 else
  return nnode->height;
}


int Dictionary::getbalance(node *n)
{
 if(n==NULL)
  return 0;
 else
  return (getheight(n->left)-getheight(n->right));
}


node* Dictionary::rightRotate(node *y)
{
 node *x=y->left;
 node *xr=x->right;

 
 x->right=y;
 y->left=xr;

 y->height=max(getheight(y->left),getheight(y->right))+1;
 x->height=max(getheight(x->left),getheight(x->right))+1;
 
 return x;
}


node* Dictionary::leftRotate(node *y)
{
 node *x=y->right;
 node *yl=x->left;

 x->left=y;
 y->right=yl;

 y->height=max(getheight(y->left),getheight(y->right))+1;
 x->height=max(getheight(x->left),getheight(x->right))+1;

 return x;
}


node* Dictionary::insert(node *rnode,string key,string meaning)
{
 
 if(rnode==NULL) 
  return new node(key,meaning);

 if(key<rnode->key)
  rnode->left=insert(rnode->left,key,meaning);

 else if(key>rnode->key)
  rnode->right=insert(rnode->right,key,meaning);

 else 
  return rnode;

 
 rnode->height=1+max(getheight(rnode->left),getheight(rnode->right));

 int balance=getbalance(rnode);

 //LL Case
 if(balance>1 && key<rnode->left->key)
 {
  cout<<"\nll rotate:"<<rnode->key;
  return rightRotate(rnode);
 }
 //RR Case
 if(balance<-1 && key>rnode->right->key)
 {
  cout<<"\nrr rotate:"<<rnode->key;
  return leftRotate(rnode);
 }
 //LR Case
 if(balance>1 && key>rnode->left->key)
 {
  rnode->left=leftRotate(rnode->left);
  cout<<"\nlr rotate:"<<rnode->key;
  return rightRotate(rnode);
 }

 //RL Case
 if(balance<-1 && key<rnode->right->key)
 {
  rnode->right=rightRotate(rnode->right);
  cout<<"\nrl rotate:"<<rnode->key;
  return leftRotate(rnode);
 }

 return rnode; //no change in root

}


void Dictionary::preorder()
{
 preorderRec(root);
}


void Dictionary::postorder()
{
 postorderRec(root);
}


void Dictionary::inorder()
{
 inorderRec(root);
}


void Dictionary::preorderRec(node *n)
{
 if(n)
 {
  n->print();
  preorderRec(n->left);
  preorderRec(n->right);
 }
}


void Dictionary::inorderRec(node *n)
{
 if(n)
 {
  inorderRec(n->left);
  n->print();
  inorderRec(n->right);
 }
}


void Dictionary::postorderRec(node *n)
{
 if(n)
 {
  postorderRec(n->left);
  postorderRec(n->right);
  n->print();
 }
}


void Dictionary::Avl(string key,string meaning)
{
 root=insert(root,key,meaning);
}


void Dictionary::fUpdate(node* pRoot)
{
    node *pCn;
    string sW;
    cout<<"Enter key to Update : ";
    cin>>sW;
    pCn=pRoot;
    while(pCn)
    {
        if(pCn->key==sW)
        {
            cout<<"Enter New Meaning : ";
            cin>>pCn->meaning;
            cout<<"Meaning Updated succesfully\n";
            return;

        }
        else
        {
        if(pCn->key<sW)
        pCn=pCn->right;
        else
        pCn=pCn->left;
        }

    }
cout<<"Word not found!\n";
}


node* Dictionary::delete_node(node* root,string dkey)
{
 if(root==NULL)
   return root;
	
 if(dkey< root->key)
   root->left = delete_node(root->left,dkey);
 else if(dkey > root->key)
   root->right = delete_node(root->right,dkey);

 else
 {
    if((root->left == NULL) || (root->right == NULL))
    {
      node *temp = root->left ? root->left:root->right;
        if(temp == NULL)
        {
          temp=root;
          root=NULL;
        }
    	
    	else
    	  *root = *temp;
    	  
    free(temp);
    cout<<"deleted successfully";	  
    }
 
   else
   {
     node *temp = minValue(root->right);
     root->key = temp->key;
     root->right = delete_node(root->right,temp->key);
   }   
 }

 if(root==NULL)
   return root;
  
 root->height = 1+max(getheight(root->left),getheight(root->right));

int balance = getbalance(root);

//left left case
if(balance >1 && getbalance(root->left)>=0)
	return rightRotate(root);

//left right case
if(balance>1 && getbalance(root->left)<0)
{
  root->left = leftRotate(root->left);
  return rightRotate(root);
}

//right right case
if(balance<-1 && getbalance(root->right)<=0)
  return leftRotate(root);
  
//right left case
if(balance<-1 && getbalance(root->right)>0)
{
  root->right = rightRotate(root->right);
  return leftRotate(root);
}

return root;

}




int main() {

 //ofstream fout;
 Dictionary d;
 char n;
 string m,l1,l2,k,dkey;
 int choice;

do{

cout<<"\n1.Enter data\n2.Ascending order\n3.preorder\n4.postorder\n5.Delete\n6.Update";
cout<<"\nEnter your choice: ";
cin>>choice;

switch(choice){

  case 1:
  	cout<<"key: ";
  	cin>>k;
  	cout<<"meaning: ";
	cin>>m;
	
	d.Avl(k,m);
   break;
   
  case 2:
        cout<<"\nAscending order: ";
 	d.inorder();
   break;
   
  case 3:
  	cout<<"\nPreorder: ";
	d.preorder();
   break;
   
  case 4:
  	cout<<"\nPostorder: ";
 	d.postorder();
   break; 
   
  case 5:
  	cout<<"Enter the key you want to delete: ";
  	cin>>dkey;
  	d.deletenode(dkey);
   break;

  case 6:
        d.update();
        break;  
}
 
 cout<<"\nDo you want to enter again(y/n): ";
 cin>>n;
}while(n=='y' || n=='Y');
 
 
 return 0;
}

