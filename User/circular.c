#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Define the Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

// Function to insert an element into the circular queue
void insert(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full! Cannot insert %d\n", value);
    } else {
        if (q->front == -1) { // If the queue is empty
            q->front = 0;  // Set the front to 0
        }
        q->rear = (q->rear + 1) % MAX; // Move rear to the next position in a circular manner
        q->arr[q->rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

// Function to delete an element from the circular queue
int delete(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Cannot delete\n");
        return -1;
    } else {
        int deletedValue = q->arr[q->front];
        if (q->front == q->rear) { // If there's only one element in the queue
            q->front = q->rear = -1; // Reset the queue
        } else {
            q->front = (q->front + 1) % MAX; // Move front to the next position in a circular manner
        }
        return deletedValue;
    }
}

// Function to display the elements of the circular queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[q->rear]); // Print the last element
    }
}

int main() {
    struct Queue queue;
    int choice, value;

    // Initialize the queue
    initializeQueue(&queue);

    while (1) {
        // Menu to display options
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&queue, value);
                break;
            case 2:
                value = delete(&queue);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
