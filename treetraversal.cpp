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
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<(root->data)<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root=NULL;
    root=insert(root,50);
    root=insert(root,70);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,20);
    root=insert(root,60);
    root=insert(root,80);
      cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}