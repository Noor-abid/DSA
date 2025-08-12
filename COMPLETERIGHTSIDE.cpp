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
void printSubtree(Node* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    printSubtree(root->left);
    printSubtree(root->right);
}

void printCompleteLeftSide(Node* root){
    if(root == nullptr) 
    return;

   
    cout << root->data << " ";

    
    printSubtree(root->right);
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
    cout<<"Right side of tree is:";
    printCompleteLeftSide(root);
}