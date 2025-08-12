#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->left=newNode->right=nullptr;
    return newNode;
}
Node* insert(Node* root,int data){
    if(root==nullptr){
        root=createNode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
void printleafnodes(Node* root){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        cout<<root->data<<" ";
    }
    printleafnodes(root->left);
    printleafnodes(root->right);
}
int main(){
    Node* root=nullptr;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,40);
    root=insert(root,20);
    root=insert(root,60);
    root=insert(root,80);
    cout<<"Leaf Nodes: ";
    printleafnodes(root);
}