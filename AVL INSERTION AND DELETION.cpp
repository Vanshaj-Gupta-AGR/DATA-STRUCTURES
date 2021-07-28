#include <bits/stdc++.h>
using namespace std;

#define int  long long
#define mod  1000000007
#define inf  1e18
#define nline "\n"

void c_p_c() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


}


class tree{
    
    
    public:
    int value;
    tree* left;
    tree *right;
    int height;
    
    
    tree(int value){
        this->value=value;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
        
    }
    
    
};



int height1(tree * root){
    if(root==NULL){
        return 0;
    }
    
    return root->height;
}


int bf(tree *root){
    
    if(root==NULL){
        return 0;
    }
    
    return height1(root->left)-height1(root->right);
    
}



tree * lfr(tree *root){
    
    tree *t1=root->right;
    tree* t2=t1->left;
    
    
    t1->left=root;
    root->right=t2;
    
    
    t1->height=1+max(height1(t1->left),height1(t1->right));
    root->height=1+max(height1(root->left),height1(root->right));
    
    
    return t1;
    
    
    
    
}


tree *rr(tree * root){
    
    tree *t1=root->left;
    
    tree *t2=t1->right;
    
    
    t1->right=root;
    root->left=t2;
    
     t1->height=1+max(height1(t1->left),height1(t1->right));
    root->height=1+max(height1(root->left),height1(root->right));
    
    
    return t1;
    
    
    
    
    
}



tree *insert(tree *root,int val){
    
    
    if(root==NULL){
        return new tree(val);
    }
    
    
    if(root->value>val){
        root->left=insert(root->left,val);
    }
    
    else if(root->value<val){
        root->right=insert(root->right,val);
    }
    
    else{
        return root;
    }
    
    
    
    
    
    root->height=1+max(height1(root->left),height1(root->right));
    
    
    
    
    int balance=bf(root);
    
    
    
    
    if(balance>1 && val<root->left->value){
        return rr(root);
        
    }
    
    if(balance<-1 && val>root->right->value){
        return lfr(root);
        
    }
    
    if(balance>1 && val>root->left->value){
        root->left=lfr(root->left);
        return rr(root);
        
        
    }
    
    if(balance<-1 && val<root->right->value){
        
        root->right=rr(root->right);
        
        return lfr(root);
        
    }
    
    return root;
    
    
    
}

tree * minvalue(tree* node)
{
    tree* current = node;
 
    
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

tree *deleted(tree *root,int val){
    
    if(root==NULL){
        return root;
    }
    
    if(val<root->value){
        root->left=deleted(root->left,val);
    }
    
    else if(val>root->value){
        root->right=deleted(root->right,val);
    }
    
    
    
    else{
        
        
        if(root->left==NULL || root->right==NULL){
            
            tree *temp=root->right ? root->right : root->left;
            
            
        
        
        
        if(!temp){
            temp=root;
            root=NULL;
           
            
        }
        else{
            
            *root=*temp;
            
            
        }
        
        free(temp);
        
    }
    
    
    else{
        tree *temp=minvalue(root->right);
        
        root->value=temp->value;
        
        root->right=deleted(root->right,temp->value);
        
    }
    
    
    
}




if(root==NULL){
    return root;
}

 
    
    root->height=1+max(height1(root->left),height1(root->right));
    
    
    
    
    int balance=bf(root);
    
    
    
    
    if(balance>1 && bf(root->left)>=0){
        return rr(root);
        
    }
    
    if(balance<-1 && bf(root->right)<=0){
        return lfr(root);
        
    }
    
    if(balance>1 && bf(root->left)<0){
        root->left=lfr(root->left);
        return rr(root);
        
        
    }
    
    if(balance<-1 && bf(root->right)>0){
        
        root->right=rr(root->right);
        
        return lfr(root);
        
    }
    
    return root;
}



void Preorder(tree *root){
    
    if(root==NULL){
        return ;
    }
    
    cout<<root->value<<" ";
    Preorder(root->left);
    Preorder(root->right);
    
    
}




int32_t main() {
    c_p_c();
    
    
    
    tree *root=NULL;
    
     root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    Preorder(root);
 
    root = deleted(root, 10);
 
   
 
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    Preorder(root);
 
    
     
    return 0;
    
    
    
    
    
    
    
}