```c
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

// Inorder traversal (Left-Root-Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root-Left-Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left-Right-Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Search for a value in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Find minimum value node in BST
struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    return findMin(root->left);
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Calculate height of tree
int height(struct Node* root) {
    if (root == NULL)
        return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Example usage
int main() {
    struct Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Height of tree: %d\n", height(root));
    printf("Total nodes: %d\n", countNodes(root));
    
    // Search for a value
    int searchKey = 40;
    struct Node* found = search(root, searchKey);
    if (found)
        printf("Value %d found in the tree\n", searchKey);
    else
        printf("Value %d not found in the tree\n", searchKey);
    
    // Delete a node
    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("After deleting %d, inorder traversal: ", deleteKey);
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}

```

I've created a comprehensive implementation of a Binary Search Tree (BST) in C with all the fundamental operations. Here are the key operations implemented:

1. Creation Operations:
   - `createNode`: Creates a new node with given value
   - `insert`: Inserts a new value into the BST

2. Traversal Operations:
   - `inorderTraversal`: Left-Root-Right
   - `preorderTraversal`: Root-Left-Right
   - `postorderTraversal`: Left-Right-Root

3. Search Operations:
   - `search`: Finds a node with given value
   - `findMin`: Finds the minimum value in the tree

4. Deletion Operation:
   - `deleteNode`: Removes a node with given value

5. Utility Operations:
   - `height`: Calculates the height of the tree
   - `countNodes`: Counts total number of nodes

The code includes a main function with example usage of all operations. Would you like me to explain any specific operation in more detail?```c
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

// Inorder traversal (Left-Root-Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root-Left-Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left-Right-Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Search for a value in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Find minimum value node in BST
struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    return findMin(root->left);
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Calculate height of tree
int height(struct Node* root) {
    if (root == NULL)
        return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Example usage
int main() {
    struct Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Height of tree: %d\n", height(root));
    printf("Total nodes: %d\n", countNodes(root));
    
    // Search for a value
    int searchKey = 40;
    struct Node* found = search(root, searchKey);
    if (found)
        printf("Value %d found in the tree\n", searchKey);
    else
        printf("Value %d not found in the tree\n", searchKey);
    
    // Delete a node
    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("After deleting %d, inorder traversal: ", deleteKey);
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}

```

I've created a comprehensive implementation of a Binary Search Tree (BST) in C with all the fundamental operations. Here are the key operations implemented:

1. Creation Operations:
   - `createNode`: Creates a new node with given value
   - `insert`: Inserts a new value into the BST

2. Traversal Operations:
   - `inorderTraversal`: Left-Root-Right
   - `preorderTraversal`: Root-Left-Right
   - `postorderTraversal`: Left-Right-Root

3. Search Operations:
   - `search`: Finds a node with given value
   - `findMin`: Finds the minimum value in the tree

4. Deletion Operation:
   - `deleteNode`: Removes a node with given value

5. Utility Operations:
   - `height`: Calculates the height of the tree
   - `countNodes`: Counts total number of nodes

The code includes a main function with example usage of all operations. Would you like me to explain any specific operation in more detail?