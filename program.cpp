// Online C++ compiler to run C++ program online
#include <c++/v1/bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *create(int data){
 Node *newnode = new Node;
 newnode->data= data;
 newnode->left=newnode->right=NULL;
 
 return newnode;
}

Node *insert(Node *root,int data){
    if(root==NULL) root = create(data);
    
    else if(data<root->data){
        root->left = insert(root->left,data);
    }
    else if(data>root->data){
        root->right = insert(root->right,data);
    }
    
    return root;
}

void inorder(Node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int height(Node *root){
    if(root==NULL) return -1;
    
    return max(height(root->left),height(root->right))+1;
}
void LOT(Node *root){
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node *current = q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL) q.push(current->right);
        q.pop();
    }
}

void fromLeft(Node *root){
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node *current = q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) q.push(current->left);
        else if(current->right!=NULL) q.push(current->right);
        q.pop();
    }
}

void fromRight(Node *root){
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node *current = q.front();
        cout<<current->data<<" ";
        if(current->right!=NULL) q.push(current->right);
        else if(current->left!=NULL) q.push(current->left);
        q.pop();
    }
}
void fromBorder(Node *root){
    
    fromLeft(root);
    fromRight(root->right);
}

int main() {
   
   int ar[]={40,30,50,25,35,45,60};
   Node *root = NULL;
   for(auto i:ar){
       root=insert(root,i);
   }
   
    cout<<"Inorder \n";inorder(root); cout<<endl;cout<<endl;
    cout<<"Level order \n";LOT(root); cout<<endl;
    cout<<"\nHeight is "<<height(root)<<endl;cout<<endl;
    cout<<"Left view  \n";fromLeft(root); cout<<endl;cout<<endl;
    cout<<"Right view  \n";fromRight(root); cout<<endl;cout<<endl;
    cout<<"Border view  \n";fromBorder(root); cout<<endl;cout<<endl;

    return 0;
}
