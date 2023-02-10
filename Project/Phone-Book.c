/* Phone Book Application Using Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 48

struct Node {
    long long int number;
    char name[NAME_SIZE];
    struct Node *left, *right;
};

typedef struct Node Node;

static void printIndividual(struct Node* node) {
    printf("Name:\t%s\n", node->name);
    printf("Number:\t%lld\n\n", node->number);
}

static void inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printIndividual(node);
    inorder(node->right);
}

static struct Node* newNode(char val[], long long int num) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    strcpy(node->name, val);
    node->number = num;
    node->left = node->right = NULL;
    return node;
}

static struct Node* insert(struct Node* node, char val[], long long int num) {
    if (node == NULL) {
        node = newNode(val, num);
        return node;
    }
    int result = strcmp(val, node->name);
    if (result > 0) {
        node->right = insert(node->right, val, num);
    } else {
        node->left = insert(node->left, val, num);
    }
    return node;
}

static Node* minValue(Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

static Node* deleter(Node* node, char val[]) {
    int result = strcmp(val, node->name);
    if (node == NULL) {
        return NULL;
    } else if (result > 0) {
        node->right = deleter(node->right, val);
    } else if (result < 0) {
        node->left = deleter(node->left, val);
    } else {
        if (node->left == NULL && node->right != NULL) {
            Node* temp = node->right;
            free(node);
            node = NULL;
            return temp;
        } else if (node->left != NULL && node->right == NULL) {
            Node* temp = node->left;
            free(node);
            node = NULL;
            return temp;
        } else if (node->left == NULL && node->right == NULL) {
            return NULL;
        } else {
            char minV[30];
            strcpy(minValue(node->right)->name, minV);
            strcpy(minV, node->name);
            node->right = deleter(node->right, minV);
            return node;
        }
    }
    return node;
}


static void print(struct Node* node) {
    printf("****************************\n\tPhone-Book\n");
    inorder(node);
    printf("****************************\n");
}

static void decoration() {
    printf("Press the respective key for your operation\n");
    printf("1. Show the Phone Book.\n");
    printf("2. Insert into the Phone Book.\n");
    printf("3. Delete a Contact.\n");
    printf("4. Exit\n");
}

int main() {
    struct Node* root = NULL;
    
    char arr[30];
    long long int number = 0;

    while (1) {
        printf("\n");
        decoration();
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                print(root);
                break;

            }
            case 2: {
                char c;
                printf("\nEnter Name [first letter capital]: ");
                scanf("%c", &c);
                scanf("%[^\n]s", arr);
                printf("Enter Phone Number: ");
                scanf("%lld", &number);
                root = insert(root, arr, number);
                printf("\n");
                break;

            }
            case 3: {
                char c;
                printf("Enter the Name of the contact you want to delete:");
                scanf("%c", &c);
                scanf("%[^\n]s", arr);
                root = deleter(root, arr);
                break;
            }
            case 4:
                printf("Bye!!\n");
                return 0;
            default: {
                printf("Invalid Number\n");
            }
        }
    }
}   
