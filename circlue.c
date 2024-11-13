#include <stdio.h>
#define MAX 5 // Define the maximum size of the circular queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert an element in the circular queue (enqueue)
void insert(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) { // Insert first element
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("Inserted %d into queue.\n", value);
    }
}

// Function to delete an element from the circular queue (dequeue)
int delete() {
    if (front == -1) {
        printf("Queue underflow! Cannot delete.\n");
        return -1;
    }

    int deletedValue = queue[front];
    if (front == rear) { // Queue becomes empty after deletion
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    return deletedValue;
}

// Function to display all elements in the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50); // Queue is now full
    display();  // Display queue elements

    printf("Deleted element: %d\n", delete()); // Delete front element
    printf("Deleted element: %d\n", delete());
    display(); // Display queue elements after deletion

    insert(60); // Inserting again after deletion to show circular nature
    display();

    return 0;
}
