#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int x) {
    int index = x % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = x;
    printf("Inserted %d at index %d\n", x, index);
}

void search(int x) {
    int index = x % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == x) {
            printf("%d found at index %d\n", x, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("%d not found\n", x);
}

void display() {
    int i;

    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int i, choice, x;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    while (1) {
        printf("\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                printf("Enter account number to search: ");
                scanf("%d", &x);
                search(x);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
