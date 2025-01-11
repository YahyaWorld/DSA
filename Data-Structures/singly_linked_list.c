// my_singly_linked_list_module

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int list_size = 0;

int insert(node **, int, int); //(headptr, index, data)
int delete(node *, int);      //(headptr, index)
int access(node *, int);      //(headptr, index)
int get_list_size();          //()

int insert(node **head, int index, int data)
{
    if (index < 0 || index > list_size)
    {
        printf("Error: invalid index!\n");
        return -1;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        list_size++;
        return 0;
    }

    if (index == 0)
    {
        new_node->next = head;
        head = new_node;
        list_size++;
        return 0;
    }

    node *temp = head;
    for (int i = 0; i < (index - 1); i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    list_size++;
    return 0;
}

int delete(node *head, int index)
{
    if (index < 0 || index > list_size)
    {
        printf("Error: invalid index!\n");
        return -1;
    }

    if (head == NULL)
    {
        printf("Error: void deletion!\n");
        return -1;
    }

    
    node *temp1 = head;
    node *temp2 = NULL;
    int store;

    if(head->next==NULL){
        store=head->data;
        free(head);
        list_size--;
        return store;
    }

    for (int i = 0; i < (index - 1); i++)
    {
        temp1=temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    store = temp2->data;
    free(temp2);
    list_size--;
    return store;
}

int access(node *head, int index)
{
    if (index < 0 || index > list_size)
    {
        printf("Error: invalid index!\n");
        return -1;
    }

    if (head == NULL)
    {
        printf("Error: linked_list is empty!\n");
        return -1;
    }

    node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

int get_list_size()
{
    return list_size;
}