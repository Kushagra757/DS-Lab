#include<stdio.h>
#define max 5
int queue[max] ;
int front = -1 , rear = -1;
void insert(){
    int item ;
    printf("enter the element to insert");
    scanf("%d" , &item);
    if((front == 0 && rear == (max-1))||(rear +1) % max == front){
        printf("queue overflow");
        return ;
    }
    if(front == -1){
        front = 0 ;
    }
    rear = (rear + 1) % max ;
    queue[rear] = item ;
    printf("%d inserted to queue" , item);
}
void delete(){
    if(front == -1){
        printf("queue underflow");
        return ;
    }
    int item = queue[front];
    printf("%d deleted from the queue" , item);
    if(front == rear){
        front = rear = -1 ;
    }
    else {
        front = (front + 1) % max ;
    }
}
void display(){
    if(front == -1) {
        printf("queue is empty ");
        return ;
    }
    printf("queue elements");
    if(rear >= front){
        for(int i= front ; i<=rear;i++){
            printf("%d",queue[i]);
        }
    }
}
int main(){
    int choice ;
    while (1){
        printf("circular queue");
        printf("choose one 1. insert , 2.delete , 3.display");
        scanf("%d",&choice);
        switch(choice){
            case 1 : insert();
            break ;
            case 2 : delete();
            break ;
            case 3 : display();
            break ;
            case 4 : return ;
            break ;
            default : printf("plese choose a valid option");
        }
    }
}