/* Implement Binary Search Tree */
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* insert(Node* node, int val) {
    if (node == NULL) {
        node = new Node(val);
        return node;
    }
    if (val > node->data) {
        node->right = insert(node->right, val); 
    } else {
        node->left = insert(node->left, val);
    }
    return node;
}

int main() {
    Node* root = NULL;
    vector<int> arr = {50, 15, 62, 5, 20, 58, 91, 3, 8, 37, 60, 24};
    for (int i : arr) {
        root = insert(root, i);
    }
    inorder(root); cout << "\n";
    root = deleteNode(root, 8);
    inorder(root); cout << "\n";
}