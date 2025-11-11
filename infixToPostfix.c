#include <stdio.h>
#include<ctype.h>

char stack[100];
int top = -1 ;
void push(char c){
    top ++ ;
    stack[top] = c;
}
char pop(){
    char ch = stack[top];
    top-- ;
    return ch;
}
int precedence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }else if(c =="*"||c == "/"){
        return 2;
    }
    return 0;
}
int main(){
    char infix[100] , postfix[100];
    int i,j =0;
    char ch ;
    printf("enter infix expresion");
    scanf("%s",infix);
    for(i =0 ; infix[i]!= '\0' ; i++){
        ch = infix[i];
        if(isalnum(ch)){
            postfix [j++] = ch;
        }else if(ch == '(')
            push(ch);
        else if(ch == ')'){
            while(stack[top]!= '('){
                postfix[j++] = pop();
            }
            pop();
        }else{
            while(top!= -1 && precedence(stack[top])>=precendece(ch)){
                postfix[j++] = pop();
                push(ch);
            }
        }
    }
    while(top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0' ;
    printf("postfix : %s \n" ,postfix);
    return 0;
}