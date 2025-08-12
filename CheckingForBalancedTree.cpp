#include <iostream>
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



// Function that returns height if balanced, else -1
int checkHeight(Node* root) {
    if (!root)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1; // Left not balanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1; // Right not balanced

    if (abs(leftHeight - rightHeight) > 1)
        return -1; // Not balanced

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
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
    if (isBalanced(root))
        cout << "The tree is balanced.\n";
    else
        cout << "The tree is NOT balanced.\n";

    }