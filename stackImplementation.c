#include<stdio.h>
int main(){
    int ele;
    int arr[10] ;
    int top =-1;
    int option;
    char ch = "y" ;
    while (ch == "y"){
        printf("choose one option 1.push 2.pop , 3.display");
        scanf("%d",&option);
        if(option ==1){
            if(top>=9){
                printf("stack overflow");
            }else{
                top ++ ;
                printf("enter the element");
                scanf("%d",&ele);
            }
        }else if(option ==2 ){
            if(top < 0){
                printf("stack underflow");
            }else{
                top-- ;
            }
        }else if(option == 3) {
            for(int i =0 ; i<=top ; i++){
                print(arr[i]);
            }
            printf("top = %d",top);
        }else{
            printf("please choose a valid option");
            continue ;
        }
        printf("if you wish to continue press y else press n to exit");
        scanf("%c" , &ch);
    }
    return 0 ;
}