#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int arr[MAX_SIZE];
int size = 0; //0 means 0 items in array

void create();
void display();
void insert();
void delete();

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.create\n2.display\n3.insert\n4.delete\n5.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid key!\n");
            break;
        }
    }
}

void create()
{
    printf("enter length of the creating array: ");
    scanf("%d", &size);
    if (size < 0||size > MAX_SIZE)
    {
        printf("Error: size exceed maximum allowed limit!\n");
        size = 0;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("enter value for index %d: ", i);
        scanf("%d", &arr[i]);
    }
    return;
}

void display()
{
    printf("\t\tDISPLAY\t\t\n");
    if (size == 0)
    {
        printf("Error: array is empty!\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("element at index %d is %d\n", i, arr[i]);
    }
    printf("\n");
    return;
}

void insert()
{
    if (size == MAX_SIZE)
    {
        printf("Error: Array overflow! can't insert new element.\n");
        return;
    }
    int index, elem;
    printf("enter the index for inserting element: ");
    scanf("%d", &index);
    
    if (index < 0 || index > size)
    {
        printf("Error: invalid index!\n");
        return;
    }

    printf("enter the inserting element: ");
    scanf("%d", &elem);
    for (int i = (size - 1); i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = elem;
    size++;
    printf("insertion of %d is successful!\n",elem);
    return;
}

void delete()
{
    if(size==0){
        printf("Error: Array is empty! nothing to delete.\n");
        return;
    }
    int index;
    printf("enter the index of deleting element: ");
    scanf("%d", &index);
    if (index<0||index>=size)
    {
        printf("Error: invalid index!\n");
        return;
    }
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size --;
    printf("deletion of %d at index %d is successful!\n",arr[index],index);
    return;
}