#include <stdio.h>
#define max 5

int queue[max];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == max - 1) {
        printf("\nQueue overflow");
    } else {
        printf("\nEnter an element to insert: ");
        scanf("%d", &item);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("\n%d inserted into queue", item);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue underflow");
    } else {
        printf("\nDeleted element: %d", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int choice;
    printf("Queue implementation using array\n");
    while (1) {
        printf("\n\nChoose your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("\nPlease choose a valid option");
        }
    }
}
