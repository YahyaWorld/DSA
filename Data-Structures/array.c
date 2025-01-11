// my array module

#include <stdio.h>
#define MAX_ARR_SIZE 100

int arr[MAX_ARR_SIZE];
int curr_arr_size = 0;

int insert(int, int); //(index, element)
int delete(int);      //(index)
int access(int);      //(index)
int get_curr_arr_size(void);

int insert(int index, int data)
{
    if (curr_arr_size == MAX_ARR_SIZE)
    {
        printf("Error: array size exceeded max limit!\n");
        return -1;
    }
    if (index < 0 || index > curr_arr_size)
    {
        printf("Error: invalid index!\n");
        return -1;
    }
    for (int i = (curr_arr_size - 1); i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = data;
    curr_arr_size++;
    return 0;
}

int delete(int index)
{

    if (index < 0 || index >= curr_arr_size)
    {
        printf("Error: invalid index!\n");
        return -1;
    }
    int store = arr[index];
    for (int i = index; i < (curr_arr_size - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
    curr_arr_size--;
    return store;
}

int access(int index)
{
    if (index < 0 || index >= curr_arr_size)
    {
        printf("Error: invalid index!\n");
        return -1;
    }
    return arr[index];
}

int get_curr_arr_size(){
    return curr_arr_size;
}