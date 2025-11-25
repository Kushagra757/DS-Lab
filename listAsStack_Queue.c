#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* For queue we maintain head and tail. For stack we only use head. */
Node *head = NULL;
Node *tail = NULL;

/* Utility */
int is_empty() {
    return head == NULL;
}

/* Stack operations (using head)
   push -> insert at head
   pop -> remove from head
*/
void push_stack(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); return; }
    n->data = x;
    n->next = head;
    head = n;
    if (tail == NULL) tail = head; /* first node */
    printf("Pushed %d onto stack.\n", x);
}

void pop_stack() {
    if (is_empty()) {
        printf("Stack underflow — list empty.\n");
        return;
    }
    Node *t = head;
    int val = t->data;
    head = head->next;
    if (head == NULL) tail = NULL;
    free(t);
    printf("Popped %d from stack.\n", val);
}

/* Queue operations
   enqueue -> insert at tail
   dequeue -> remove from head
*/
void enqueue_queue(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); return; }
    n->data = x;
    n->next = NULL;
    if (tail == NULL) { /* empty */
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    printf("Enqueued %d into queue.\n", x);
}

void dequeue_queue() {
    if (is_empty()) {
        printf("Queue underflow — list empty.\n");
        return;
    }
    Node *t = head;
    int val = t->data;
    head = head->next;
    if (head == NULL) tail = NULL;
    free(t);
    printf("Dequeued %d from queue.\n", val);
}

/* Display list */
void display_list() {
    if (is_empty()) {
        printf("[empty]\n");
        return;
    }
    Node *p = head;
    printf("List contents: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* Free all nodes before exit */
void free_all() {
    Node *p = head;
    while (p) {
        Node *nxt = p->next;
        free(p);
        p = nxt;
    }
    head = tail = NULL;
}

int main() {
    int choice, x;
    while (1) {
        printf("\n--- Singly Linked List: Stack & Queue Simulator ---\n");
        printf("1. Push (Stack)\n2. Pop (Stack)\n3. Enqueue (Queue)\n4. Dequeue (Queue)\n5. Display list\n6. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) { /* handle non-int input */ 
            while (getchar() != '\n'); 
            printf("Invalid input.\n"); 
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &x)==1) push_stack(x);
                else { while(getchar()!='\n'); printf("Bad value.\n"); }
                break;
            case 2:
                pop_stack();
                break;
            case 3:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &x)==1) enqueue_queue(x);
                else { while(getchar()!='\n'); printf("Bad value.\n"); }
                break;
            case 4:
                dequeue_queue();
                break;
            case 5:
                display_list();
                break;
            case 6:
                free_all();
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
