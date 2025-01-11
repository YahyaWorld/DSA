#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Size of the hash table

// Define a structure for the hash table
typedef struct {
    int key;
    int value;
} HashItem;

// Create a hash table as an array of pointers
HashItem* hashTable[TABLE_SIZE];

// Function to calculate hash value
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    
    // Check if the spot is already occupied
    if (hashTable[hashIndex] != NULL) {
        printf("Collision detected. No collision handling implemented.\n");
        return;
    }

    // Create a new HashItem
    HashItem* newItem = (HashItem*)malloc(sizeof(HashItem));
    newItem->key = key;
    newItem->value = value;

    // Insert into the table
    hashTable[hashIndex] = newItem;
}

// Function to search for a value by key
int search(int key) {
    int hashIndex = hashFunction(key);
    
    if (hashTable[hashIndex] != NULL && hashTable[hashIndex]->key == key) {
        return hashTable[hashIndex]->value;
    }

    return -1; // Key not found
}

// Function to delete a key-value pair
void delete(int key) {
    int hashIndex = hashFunction(key);

    if (hashTable[hashIndex] != NULL && hashTable[hashIndex]->key == key) {
        free(hashTable[hashIndex]);
        hashTable[hashIndex] = NULL;
        printf("Key %d deleted.\n", key);
    } else {
        printf("Key %d not found.\n", key);
    }
}

// Function to display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert some key-value pairs
    insert(1, 10);
    insert(11, 20);
    insert(21, 30); // This will collide with key 1 if TABLE_SIZE is 10

    // Display the hash table
    display();

    // Search for a key
    int value = search(1);
    if (value != -1) {
        printf("Key 1 found with value: %d\n", value);
    } else {
        printf("Key 1 not found.\n");
    }

    // Delete a key
    delete(11);
    display();

    return 0;
}
