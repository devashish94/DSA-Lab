/*  C program to Implement the Circular Singly Linked List */
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *next;
} *head;

struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated.\n");
        return NULL;
    }
 
    new_node->data = data;
    new_node->next = NULL;
 
    return new_node;
}
 
void insert_at_begin(int data) {
    struct node *new_node = create(data);
    if (new_node != NULL) {
        struct node *last = head;
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }
        while (last->next != head) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_end(int data) {
    struct node *new_node = create(data);
    if (new_node != NULL) {
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }
 
        struct node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = head;
    }
}

void delete_at_end() {
    if (head == NULL) {
        printf("\n List is Empty! \n");
        return;
    }
    struct node *prev = head;
    struct node *temp = head->next;

    if (prev->next == head) {
        free(prev);
        head = NULL;
        return;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    temp = NULL;
}

void print_list() {
    struct node *temp = head;
    if (head == NULL) {
        printf("\n List is Empty! \n");
        return;
    } 
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int getData() {
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);
    return data;
}

int main() {
    int user_choice;
    int data, position;
 
    while(1) {
        printf("------ Circular Singly Linked List -------\n");
        printf("\n1. Insert a node at beginning");
        printf("\n2. Insert a node at end");
        printf("\n3. Delete a node from end");
        printf("\n4. Print list from beginning");
        printf("\n5. Exit\n");
 
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        printf("\n");
        switch(user_choice) {
            case 1:
                printf("Inserting a node at beginning");
                data = getData();
                insert_at_begin(data);
                break;
 
            case 2:
                printf("Inserting a node at end");
                data = getData();
                insert_at_end(data);
                break;
 
            case 3: 
                printf("Deleting a node from end\n");
                delete_at_end();
                break;
            
            case 4: 
                printf("Printing the list from beginning\n");
                print_list();
                break;
 
            case 5:
                printf("Program was terminated\n\n");
                return 0;
 
            default:
                printf("\n\t Invalid Choice\n");
        }
    }
    return 0;
}

