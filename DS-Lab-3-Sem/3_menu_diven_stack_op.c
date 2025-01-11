#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;

void push();
void pop();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid key!\n");
        }
    }
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

void display()
{
    if(top==-1){
        printf("Error: stack is empty!\n");
        return;
    }
    printf("\t\tDISPLAY\t\t\n");
    for (int i = top; i != -1; i--)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    return;
}
