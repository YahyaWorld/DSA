#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

void push();
void pop();
int priority(char);

int main()
{
    char expr[100];
    char *exprptr = expr;
    char x;
    printf("enter the expression: ");
    scanf("%s", expr);
    while (*exprptr!='\0'){
        if(isalnum(*exprptr)){
            printf("%c",*exprptr)
        }else if(*exprptr=='('){
            push('c')
        }
    }
    {
        /* code */
    }
    
    return 0;
}

void push()
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow!\n");
        return;
    }
    int element;
    printf("enter integer element to push: ");
    scanf("%d", &element);
    arr[++top] = element;
    return;
}

void pop()
{
    if (top == -1)
    {
        printf("Error: stack underflow!\n");
        return;
    }
    printf("popped element is: %d\n", arr[top--]);
    return;
}

int priority(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == "/")
    {
        return 2;
    }
    else if (ch == '%' || ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}