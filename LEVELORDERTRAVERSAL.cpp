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
int height(Node* root){
    if(root==nullptr){
        return 0;
}
int leftheight=height(root->left);
int rightheight=height(root->right);
return max(leftheight,rightheight)+1;

}
void printlevel(Node* root,int level){
    if(root==nullptr)
    return;
    if(level==1){
        cout<<root->data<<" ";
    }
    else if(level>1){
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);
    }
}
void levelorder(Node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printlevel(root,i);
        cout<<endl;
    }
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
    cout<<"level order traversal: ";
    levelorder(root);

}