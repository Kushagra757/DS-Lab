#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory not allocated.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory not allocated.\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    printf("Linked list created successfully.\n");
}


void displayList() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void deleteFirst() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    head = head->next;
    free(temp);
    printf("First node deleted.\n");
}


void deleteLast() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) { 
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}


void deleteSpecific(int key) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }


    if (head->data == key) {
        head = head->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }


    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}


int main() {
    int n, choice, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Display List\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Specific Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList();
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteSpecific(key);
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
