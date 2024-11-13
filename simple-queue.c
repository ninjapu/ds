#include <stdio.h>
#define MAX 5 // Define the maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert an element in the queue (enqueue)
void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) // Initialize front on first insert
            front = 0;
        queue[++rear] = value;
        printf("Inserted %d into queue.\n", value);
    }
}

// Function to delete an element from the queue (dequeue)
int delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow! Cannot delete.\n");
        return -1;
    } else {
        int deletedValue = queue[front++];
        if (front > rear) { // Reset queue when empty
            front = -1;
            rear = -1;
        }
        return deletedValue;
    }
}

// Function to display all elements in the queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display(); // Display queue elements

    printf("Deleted element: %d\n", delete()); // Delete front element
    display(); // Display queue elements after deletion

    printf("Deleted element: %d\n", delete()); // Delete another element
    display(); // Display queue elements

    return 0;
}
