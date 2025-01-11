//it is also called hash_maps
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 10

typedef struct Node{
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct HashTable{
    Node *buckets[TABLE_SIZE];
} HashTable;

HashTable *createHashTable(){
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    
    for(int i=0; i<TABLE_SIZE; i++){
        table->buckets[i]=NULL;
    }

    return table;
}

unsigned int hashFunction(const char *key){
    unsigned int hash=0;
    while(*key){
        hash+=*key;
        key++;
    }
    return hash%TABLE_SIZE;
}