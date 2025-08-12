#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

};
Node* CreateNode(int data){
Node* newnode=new Node();
newnode->data=data;
newnode->left=newnode->right=nullptr;
return newnode;
}
Node* insert(Node* root,int data ){
if(root==nullptr){
    root=CreateNode(data);

}
else if(data<=root->data){
    root->left=insert(root->left, data);
}
else{
    root->right=insert(root->right, data);
}
return root;
}
void printSiblings(Node* root){
    if(root==nullptr){
        return;
    }
    if (root->left != nullptr && root->right != nullptr) {
        cout << "Siblings: " << root->left->data << " & " << root->right->data << " Parent: "<<root->data<<endl;
       
    }

    // Recursively check left and right subtrees
    printSiblings(root->left);
    printSiblings(root->right);

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
    printSiblings(root);
}