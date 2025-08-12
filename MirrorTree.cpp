#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert nodes (simple insert for demonstration)
Node* insert(Node* root, int data) {
    if (!root)
        return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Mirror function
void mirror(Node* root) {
    if (root == nullptr)
        return;

    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively call for subtrees
    mirror(root->left);
    mirror(root->right);
}

int main() {
    Node* root = nullptr;

    // Creating a sample tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Original Tree (Inorder Traversal): ";
    inorder(root);


    cout << "\nMirror Tree (Inorder Traversal): ";
    mirror(root);
    inorder(root);

    return 0;
}
