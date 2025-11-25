
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void displayList(struct Node* head);

void sortList(struct Node** head);
void reverseList(struct Node** head);
void concatenate(struct Node** head1, struct Node* head2);

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at any position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range! Inserting at end.\n");
        insertAtEnd(head, data);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------------- SORTING FUNCTION (Your notebook logic) ---------------- */
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List is already sorted or empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev;

    while (current->next != NULL) {
        prev = current->next;
        while (prev != NULL) {
            if (current->data > prev->data) {
                int temp = current->data;
                current->data = prev->data;
                prev->data = temp;
            }
            prev = prev->next;
        }
        current = current->next;
    }

    printf("List sorted successfully.\n");
}

/* ---------------- REVERSE FUNCTION ---------------- */
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    *head = prev;
    printf("List reversed successfully.\n");
}

/* ---------------- CONCATENATION FUNCTION ---------------- */
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;

    printf("Lists concatenated successfully.\n");
}

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;   // for concatenation second list  

    int choice, data, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Sort the List\n");
        printf("6. Reverse the List\n");
        printf("7. Create Second List & Concatenate\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                sortList(&head);
                break;

            case 6:
                reverseList(&head);
                break;

            case 7:
                printf("Creating second list...\n");
                head2 = NULL;
                int n, x;
                printf("How many nodes for second list? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &x);
                    insertAtEnd(&head2, x);
                }
                concatenate(&head, head2);
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

