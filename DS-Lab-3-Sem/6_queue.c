#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 3

char queue[QUEUE_SIZE];
int front, rear;

void insert();
void display();
void delete();

int main()
{
    front = 0;
    rear = -1;

    int choice;
    printf("\n1.insert\n2.display\n3.delete\n4.exit\n");
    printf("Enter your choice :");
    scanf("%d", &choice);

    while (1)
    {
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete ();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
}

void insert()
{
    if (rear == QUEUE_SIZE - 1)
    {
        printf("Error: queue overflow!\n");
        return;
    }

    printf("Enter item to insert :");
    scanf("%c", &queue[++rear]);
    printf("Insertion of %c is successful!\n");
}

void delete(){
    if(front>rear){
        printf("Error: queue is empty!\n");
        return;
    }
    printf()
}