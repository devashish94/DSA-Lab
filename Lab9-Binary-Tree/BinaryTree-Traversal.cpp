#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;

    Node (int val) {
        data = val; 
    }
} Node;

void preorder(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node -> data << " ";
    preorder(node -> left);
    preorder(node -> right);
}

void inorder(Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node -> left);
    cout << node -> data << " ";
    inorder(node -> right);
}

void postorder(Node* node) {
    if (node == NULL) {
        return;
    }
    postorder(node -> left);
    postorder(node -> right);
    cout << node -> data << " ";
}



int main() {
    Node* root = new Node(1);
    root -> left = new Node(5);
    root -> right = new Node(10);
    root -> left -> left = new Node (13);
    cout << "Pre-Order:  ";
    preorder(root);
    cout << "\n";
    cout << "In-Order:   ";
    inorder(root);
    cout << "\n";
    cout << "Post-Order: ";
    postorder(root);
    cout << "\n";
}
