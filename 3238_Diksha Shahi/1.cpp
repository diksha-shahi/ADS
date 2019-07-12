//Tree operations

#include<bits/stdc++.h>
using namespace std;

class node
{
public:

    int data;
    node *left,*right;

public:
    node()
    {
        left=right=NULL;
    }
};

class tree
{
    node *root;

public:
    tree()
    {
        root=NULL;
    }

    void mir(node *n);
    void mirror()
    {
        mir(root);
    }
    void create(int c);
    void dis(node *n);
    void display()
    {
        dis(root);
    }
    void inorder_rec(node *n);
    void postorder_rec(node *n);
    void preorder_rec(node *n);
    void inorder_nr(node *n);
    void preorder_nr(node *n);
    void postorder_nr(node *n);
    void inorder()
    {
        inorder_rec(root);
    }
    void postorder()
    {
        postorder_rec(root);
    }
    void preorder()
    {
        preorder_rec(root);
    }
    void inorder_()
    {
        inorder_nr(root);
    }
    void preorder_()
    {
        preorder_nr(root);
    }
    void postorder_()
    {
        postorder_nr(root);
    }

    void level_order(node *root);

    void print()
    {
        int h=get_height(root);
        level_order(root);
    }
    int get_height(node *root);
    int height()
    {
        int h= get_height(root);
        cout<<"\nHeight of the tree: "<<h<<"\n";
    }
};

int tree::get_height(node *root)
{
    if(root==NULL)
       return 0;
    int lh=get_height(root->left);
    int rh=get_height(root->right);

    return 1+max(lh,rh);
}

void print_level(node *root,int height)
{
    if(root==NULL)
        return;
    if(height==1)
    {
        cout<<root->data<<" ";
    }
    else if(height>1)
    {
        print_level(root->left,height-1);
        print_level(root->right,height-1);
    }
}

void tree::level_order(node *root)
{
    int h=get_height(root);
    for(int i=1;i<=h;i++)
    {
        print_level(root,i);
    }
}


void tree::mir(node *root)
{
    if(root)
    {
        mir(root->left);
        mir(root->right);

        node *temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return ;
}

void tree::postorder_nr(node *root)
{
    stack<node *>S;
    node *previous=NULL;

    do
    {
        while(root!=NULL)
        {
            S.push(root);
            root=root->left;
        }

        while(root==NULL && !S.empty())
        {
            root=S.top();

            if(root->right==NULL || root->right==previous)
            {
                cout<<root->data<<" ";
                S.pop();
                previous=root;
                root=NULL;
            }
            else
                root=root->right;
        }
    }while(!S.empty());
}

void tree::inorder_nr(node *root)
{
    if(root==NULL)
        return;
    
    stack<node*> S;

    while(1)
    {
        if(root!=NULL)
        {
            S.push(root);
            root=root->left;
        }
        else
        {
            if(S.empty())
                break;

            root=S.top();
            S.pop();
            cout<<root->data<<" ";
            root=root->right;
        }
    }
}

void tree::preorder_nr(node *root)
{
    if(root==NULL)
        return;
    stack<node*>S;
    S.push(root);

    while(!S.empty())
    {
        root=S.top();
        S.pop();
        cout<<root->data<<" ";

        if(root->right!=NULL)
        {
            S.push(root->right);
        }
        if(root->left!=NULL)
        {
            S.push(root->left);
        }
    }
}

void tree::create(int x)
{
    node *ptr=new node;
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;

    if(root==NULL)
        root=ptr;
    else
    {
        node *temp=root;
        char c;

        while(1)
        {
            cout<<"Adding to  left or right of "<<temp->data<<" : ";
            cin>>c;

            if(c=='l')
            {
                if(temp->left==NULL)
                {
                    temp->left=ptr;
                    return;
                }
                else
                {
                    temp=temp->left;
                }
            }
            if(c=='r')
            {
                if(temp->right==NULL)
                {
                    temp->right=ptr;
                    return;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
}

void tree::inorder_rec(node *root)
{
    if(root==NULL)
        return;
    inorder_rec(root->left);
    cout<<root->data<<" ";
    inorder_rec(root->right);
}

void tree::postorder_rec(node *root)
{
    if(root==NULL)
        return;
    postorder_rec(root->left);
    postorder_rec(root->right);
    cout<<root->data<<" ";
}

void tree::preorder_rec(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder_rec(root->left);
    preorder_rec(root->right);
}

int main()
{
    tree t;
    int ch;
    char choice;

    do
    {
        cout<<"\nMenu: ";
        cout<<"\n1. Insertion ";
        cout<<"\nRecursive approach...";
        cout<<"\n2. Inorder";
        cout<<"\n3. Preorder";
        cout<<"\n4. Postorder";
        cout<<"\nIterative approach...";
        cout<<"\n5. Inorder";
        cout<<"\n6. Preorder";
        cout<<"\n7. Postorder";
        cout<<"\n8. Mirror";
        cout<<"\n9. Height";
        cout<<"\n10. Print";
        cout<<"\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            int x;
            cout<<"\nEnter the value: ";
            cin>>x;
            t.create(x);
            break;
        case 2:
            t.inorder();
            break;
        case 3:
            t.preorder();
            break;
        case 4:
            t.postorder();
            break;
        case 5:
            t.inorder_();
            break;
        case 6:
            t.preorder_();
            break;
        case 7:
            t.postorder_();
            break;
        case 8:
            t.mirror();
            t.inorder_();
            break;
        case 9:
            t.height();
            break;
        case 10:
            t.print();
            break;
        }

        cout<<"\nDo you want to enter again? (y/n): ";
        cin>>choice;

    }while(choice=='y' || choice=='Y');

    return 0;
}
