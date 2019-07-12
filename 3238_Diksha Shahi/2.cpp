//BST operations

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    string word,meaning;
    node *left,*right;

public:
    node()
    {
        left=right=NULL;
    }
    
    
};

class dictionary
{
    node *root;

public:
    dictionary()
    {
        root=NULL;
    }
    void create();
    void inorder_rec(node *root);
    void postorder_rec(node *root);
    void postorder()
    {
        postorder_rec(root);
    }

    void inorder()
    {
        inorder_rec(root);
    }
    bool insert(string w,string m);
    int search(string w);
    node* minn(node *);
    void update(string s1,string s2,string s3);
    node* deletion(node *n,string s);
    node* search_node(string old_val);
};

node* dictionary::minn(node *n)
{
    node *temp=n;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

node* dictionary::deletion(node *root,string w)
{
    node *temp=root;
    if(temp==NULL)
        return NULL;
    if(temp->word>w)
    {
        temp->left=deletion(temp->left,w);
    }
    else if(temp->word<w)
    {
        temp->right=deletion(temp->right,w);
    }
    else
    {
        if(temp->left==NULL)
        {
            node *t=temp->right;
            delete(temp);
            return t;
        }
        else if(temp->right==NULL)
        {
            node *t=temp->left;
            delete(temp);
            return t;
        }

        node *t=minn(temp->right);
        temp->word=t->word;
        temp->right=deletion(temp->right,t->word);
    }

    return temp;
}

node* dictionary::search_node(string w)
{
    node *temp=root;

    if(temp==NULL)
        return NULL;
    else if(temp->word==w)
        return temp;

    while(temp!=NULL)
    {
        if(temp->word==w)
        {
            return temp;
        }
        else if(temp->word>w)
        {
            temp=temp->left;
        }
        else if(temp->word<w)
        {
            temp=temp->right;
        }
    }
    return NULL;
}


void dictionary::update(string old_val,string new_val,string m)
{

    //node* n=search_node(old_val);
    node *temp=deletion(root,old_val);
    insert(new_val,m);
    //return temp;
}

int dictionary::search(string w)
{
    node *temp=root;
    int cnt=0;

    if(temp==NULL)
        return -1;
    else if(temp->word==w)
        return 1;

    while(temp!=NULL)
    {
        if(temp->word==w)
        {
            cnt++;
            return cnt;
        }
        else if(temp->word>w)
        {
            temp=temp->left;
            cnt++;
        }
        else if(temp->word<w)
        {
            temp=temp->right;
            cnt++;
        }
    }
    return -1;
}

void dictionary::postorder_rec(node *root)
{
    if(root)
    {
        postorder_rec(root->right);
        cout<<root->word<<":"<<root->meaning<<"\n";
        postorder_rec(root->left);
    }
}

void dictionary::inorder_rec(node *root)
{
    if(root)
    {
        inorder_rec(root->left);
        cout<<root->word<<":"<<root->meaning<<"\n";
        inorder_rec(root->right);
    }
}

void dictionary::create()
{
    int n;
    cout<<"\nHow many words do you want to insert? ";
    cin>>n;

    string w,m;

    for(int i=0;i<n;i++)
    {
        cout<<"\nWord: ";
        cin>>w;
        cout<<"\nMeaning: ";
        cin>>m;
        insert(w,m);
    }
}

bool dictionary::insert(string w,string m)
{
    node *new_node=new node;

    //Initializing the node
    new_node->word=w;
    new_node->meaning=m;
    new_node->left=NULL;
    new_node->right=NULL;

    if(root==NULL)
    {
        root=new_node;
        return true;
    }

    node *current=root;
    node *parent=root;

    while(current!=NULL)
    {
        if(w>current->word)
        {
            parent=current;
            current=current->right;
        }
        else if(w<current->word)
        {
            parent=current;
            current=current->left;
        }
        else
        {
            cout<<"\nThis word already exist! ";
            return false;
        }
    }

    if(w>parent->word)
    {
        parent->right=new_node;
        return true;
    }
    else
    {
        parent->left=new_node;
        return true;
    }
    
}

int main()
{
    dictionary D;
    D.create();

    cout<<"\nAscending order\n";
    D.inorder();

    cout<<"\nDescending order\n";
    D.postorder();

    string word;
    cout<<"\nEnter the word to be searched: ";
    cin>>word;

    int a;
    a=D.search(word);
    if(a==-1)
        cout<<"\nWord not found in dictionary";
    else
        cout<<"\nWord found at "<<a+1;

    cout<<"\nEnter the word to be updated: ";
    cin>>word;

    a=D.search(word);
    if(a==-1)
    {
        cout<<"\nUpdate unsuccessful";
        return 0;
    }

    string n_word,n_mean;
    cout<<"\nNew word: ";
    cin>>n_word;
    cout<<"\nNew meaning: ";
    cin>>n_mean;

    
    D.update(word,n_word,n_mean);

    cout<<"\nAscending order\n";
    D.inorder();

    cout<<"\nDescending order\n";
    D.postorder();

    return 0;
}
