#include <stdio.h>
#define MAX 5 // Define maximum size of the stack

int stackArray[MAX];
int top = -1; // Stack is initially empty

// Push function to add an element to the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stackArray[++top] = value;
        printf("Pushed %d to stack.\n", value);
    }
}

// Pop function to remove an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop.\n");
        return -1; // Indicating stack is empty
    } else {
        return stackArray[top--];
    }
}

// Peek function to view the top element without removing it
int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stackArray[top];
    }
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stackArray[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display(); // Display stack elements

    printf("Peeked element: %d\n", peek()); // Peek at top element

    pop(); // Remove top element
    display(); // Display stack elements after pop

    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is the stack full? %s\n", isFull() ? "Yes" : "No");

    return 0;
}
