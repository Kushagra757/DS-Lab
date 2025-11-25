#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode *headD = NULL;

/* Create (append at end) */
void append(int x) {
    DNode *n = malloc(sizeof(DNode));
    if (!n) { perror("malloc"); return; }
    n->data = x;
    n->next = n->prev = NULL;
    if (!headD) {
        headD = n;
    } else {
        DNode *p = headD;
        while (p->next) p = p->next;
        p->next = n;
        n->prev = p;
    }
    printf("Appended %d\n", x);
}

/* Insert new node to the left of the node having value 'target'
   If target is at head, insertion becomes new head (left of head).
   If target not found, do nothing (notify).
*/
void insert_left_of(int target, int newval) {
    if (!headD) { printf("List empty — can't insert.\n"); return; }
    DNode *p = headD;
    while (p && p->data != target) p = p->next;
    if (!p) { printf("Value %d not found. No insertion.\n", target); return; }

    DNode *n = malloc(sizeof(DNode));
    if (!n) { perror("malloc"); return; }
    n->data = newval;

    /* Insert before p */
    n->next = p;
    n->prev = p->prev;
    p->prev = n;
    if (n->prev) n->prev->next = n;
    else headD = n; /* inserted at head */
    printf("Inserted %d to the left of %d\n", newval, target);
}

/* Delete the first node whose value == val */
void delete_by_value(int val) {
    if (!headD) { printf("List empty — nothing to delete.\n"); return; }
    DNode *p = headD;
    while (p && p->data != val) p = p->next;
    if (!p) { printf("Value %d not found. No deletion.\n", val); return; }

    if (p->prev) p->prev->next = p->next;
    else headD = p->next; /* deleting head */

    if (p->next) p->next->prev = p->prev;
    free(p);
    printf("Deleted first occurrence of %d\n", val);
}

/* Display forward */
void display_forward() {
    if (!headD) { printf("[empty]\n"); return; }
    printf("Doubly list (forward): ");
    DNode *p = headD;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* Free all nodes */
void free_all_d() {
    DNode *p = headD;
    while (p) {
        DNode *nxt = p->next;
        free(p);
        p = nxt;
    }
    headD = NULL;
}

int main() {
    int choice, x, target;
    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Create/Append node\n2. Insert new node to LEFT of a node (by value)\n3. Delete node by value\n4. Display list\n5. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) { while(getchar()!='\n'); printf("Invalid input.\n"); continue; }
        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                if (scanf("%d",&x)==1) append(x);
                else { while(getchar()!='\n'); printf("Bad value.\n"); }
                break;
            case 2:
                printf("Enter target value (insert left of): ");
                if (scanf("%d",&target)!=1) { while(getchar()!='\n'); printf("Bad value.\n"); break; }
                printf("Enter new node value: ");
                if (scanf("%d",&x)!=1) { while(getchar()!='\n'); printf("Bad value.\n"); break; }
                insert_left_of(target, x);
                break;
            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d",&x)==1) delete_by_value(x);
                else { while(getchar()!='\n'); printf("Bad value.\n"); }
                break;
            case 4:
                display_forward();
                break;
            case 5:
                free_all_d();
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
