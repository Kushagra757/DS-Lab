#include<stdio.h>
#define max 5
int queue[max];
int front = -1 , rear = -1 ;
void insert(){
    int item ;
    if(rear == (max -1)){
        printf("\n queue overflow");
    }else{
        printf("enter an element to insert");
        scanf("%d" , &item);
        if(front == -1){
            front =0;
        }
        rear ++ ;
        queue[rear] = item ;
        preintf("\n %d inserted into queue", item);
    }
}
void delete(){
    if(front == -1 || front == rear){
        printf("queue underflow");
    }else{
        printf("deleted element %d" , queue[front]);
        front ++ ;
    }
}
void display(){
    if(front == -1 || front == rear){
        printf("queue is empty");
    }
    else{
        printf("queue elements are : ");
        for(int i =front ;i<(rear +1);i++ ){
            printf("%d",queue[i]);
        }
    }
}
int main(){
    int choice ;
    print("queue implementation");
    while(1){
        printf("choose your choice , 1.insert , 2.delete , 3.display , 4.exit");
        scanf("%d", &choice);
        switch(choice){
            case 1 : insert();
            break; 
            case 2 : delete();
            break ;
            case 3 : display();
            break ;
            case 4 : return ;
            break ;
            default : printf("please choose a valid option");
        }
    }
}