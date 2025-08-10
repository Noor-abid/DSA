Node* insert(Node* node,int key){
    if(node==nullptr)
    return newnode(key);
    if(key<node->key)
    node->left=insert(node->left,key);
    else if(key>node->key)
    node->right=insert(node->right,key);
    else 
    return node;
    node->height=1+max(height(node->left),height(node->right));
    int balance =getbalance(node);
    if(balance>1 && key<node->left->key)
    return rightRotate(node);
if(balance<-1 && key>node->Right->key)
    return leftRotate(node);
    if(balance<-1 && key<node->Right->key){
        node->Right=rightRotate(node->Right);
    return leftRotate(node);
    }
    return node;
}

Node* newnode(int key){
    Node* node=new Node();
    node->key=key;
    node->height=1;
    node->left=node->Right=nullptr;
    return node;
}

int height(Node* node){
    if(node==nullptr)
    return 0;
    return node->height;
}

int max(int a,int b ){
    return a>b?a:b;
}

int getbalance(Node *node){
    if(node==nullptr)
    return 0;
    return height(node->left)-height(node->Right);
}
int main(){
    Node* root=NULL;
    int values[]={8,9,10};
    for(int val: values)
    root=insert(root, key);
}