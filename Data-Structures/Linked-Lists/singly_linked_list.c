// we often use the pointers to the structure variable, rather than that variable directly

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAfter(struct Node* prevNode, int data);
void insertAtEnd(struct Node* head, int data);
void traverse(struct Node* head);
int deleteFromBeginning(struct Node** head);
int deleteFromEnd(struct Node* head);
int deleteNode(struct Node** head, struct Node* target);
struct Node* search(struct Node* head, int key);

int main()
{
    struct Node* head=NULL;
    insertAtBeginning(&head, 1);
    traverse(head);

    return 0;
}

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct Node* head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Error: previous Node cannot be NULL!\n");
    }
    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int deleteFromBeginning(struct Node** head)
{
    if (head == NULL)
    {
        printf("Error: head cannot be NULL!\n");
        return -1;
    }
    int tempStore = (*head)->data;
    struct Node *temp = *head;
    *head = (*head)->next;
    free(*head);
    return tempStore;
}

int deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("Error: head cannot be NULL!\n");
        return -1;
    }
    if (head->next == NULL)
    {
        int tempStore = head->data;
        free(head);
        return tempStore;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int tempStore = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return tempStore;
}

int deleteNode(struct Node **head, struct Node *target)
{
    if (*head == NULL || target == NULL)
    {
        printf("Error: head or target cannot be empty!\n");
        return -1;
    }
    int tempStore = target->data;
    if (*head == target)
    {
        *head = (*head)->next;
        free(target);
        return tempStore;
    }
    struct Node *temp = *head;
    while (temp->next != target)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(target);
    return tempStore;
}
struct Node* search(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("Error: head cannot be empty!\n");
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
