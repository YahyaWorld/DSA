#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define NAME_LENGTH 15

// Employee structure definition
struct employee {
    int id;
    char name[NAME_LENGTH];
};
typedef struct employee EMP;

// Global variables
EMP emp[MAX];
int a[MAX];

// Creates a hash key from the input number
int create(int num) {
    return num % MAX;  // Changed to use MAX instead of 100 for better distribution
}

// Gets employee details and stores them at the given key
int getemp(EMP emp[], int key) {
    char temp[NAME_LENGTH];
    
    printf("\nEnter emp id: ");
    if(scanf("%d", &emp[key].id) != 1) {
        while(getchar() != '\n');  // Clear input buffer
        printf("Invalid input for ID\n");
        return -1;
    }
    
    printf("\nEnter emp name: ");
    while(getchar() != '\n');  // Clear input buffer
    if(fgets(temp, NAME_LENGTH, stdin) != NULL) {
        // Remove trailing newline if present
        size_t len = strlen(temp);
        if(len > 0 && temp[len-1] == '\n') {
            temp[len-1] = '\0';
        }
        strncpy(emp[key].name, temp, NAME_LENGTH - 1);
        emp[key].name[NAME_LENGTH - 1] = '\0';  // Ensure null termination
    }
    
    return key;
}

// Display function with proper formatting
void display() {
    int i, ch;
    
    printf("\n1.Display ALL\n2.Filtered Display");
    printf("\nEnter the choice: ");
    if(scanf("%d", &ch) != 1) {
        printf("Invalid input\n");
        while(getchar() != '\n');
        return;
    }
    
    printf("\nThe hash table is:\n");
    printf("\nHTKey\tEmpID\tEmpName");
    
    if(ch == 1) {
        for(i = 0; i < MAX; i++) {
            printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
        }
    } else if(ch == 2) {
        for(i = 0; i < MAX; i++) {
            if(a[i] != -1) {
                printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
            }
        }
    } else {
        printf("\nInvalid choice!");
    }
}

// Linear probing with improved collision handling
void linear_prob(int key, int num) {
    int flag = 0;
    int i;
    int count = 0;
    
    if(a[key] == -1) {
        if(getemp(emp, key) != -1) {
            a[key] = num;
        }
    } else {
        printf("\nCollision Detected...!!!\n");
        
        // Count filled slots
        for(i = 0; i < MAX; i++) {
            if(a[i] != -1) count++;
        }
        
        if(count == MAX) {
            printf("\nHash table is full\n");
            display();
            return;
        }
        
        printf("\nAttempting collision resolution using LINEAR PROBING\n");
        
        // Try to find empty slot starting from collision point
        for(i = (key + 1) % MAX; i != key; i = (i + 1) % MAX) {
            if(a[i] == -1) {
                if(getemp(emp, i) != -1) {
                    a[i] = num;
                    printf("Collision avoided successfully\n");
                    return;
                }
                break;
            }
        }
    }
}

int main() {
    int num, key;
    char continue_input;
    
    printf("\nCollision handling by linear probing: ");
    
    // Initialize hash table
    for(int i = 0; i < MAX; i++) {
        a[i] = -1;
        emp[i].id = 0;
        emp[i].name[0] = '\0';
    }
    
    do {
        printf("\nEnter the data: ");
        if(scanf("%d", &num) != 1) {
            printf("Invalid input\n");
            while(getchar() != '\n');
            continue;
        }
        
        key = create(num);
        linear_prob(key, num);
        
        printf("\nDo you wish to continue? (y/n): ");
        while(getchar() != '\n');
        continue_input = getchar();
        
    } while(continue_input == 'y' || continue_input == 'Y');
    
    display();
    return 0;
}