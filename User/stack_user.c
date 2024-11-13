#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum size of the stack

// Define the stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *s) {
    s->top = -1; // Stack is empty initially
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->arr[++s->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}

// Function to peep at the top element of the stack
int peep(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peep\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Function to change the top element of the stack
void change(struct Stack *s, int value) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot change\n");
    } else {
        s->arr[s->top] = value;
        printf("Top element changed to %d\n", value);
    }
}

// Function to display the stack elements
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    int choice, value;

    // Initialize the stack
    initializeStack(&stack);

    while (1) {
        // Menu to display options
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peep(&stack);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                printf("Enter new value to change top element: ");
                scanf("%d", &value);
                change(&stack, value);
                break;
            case 5:
                display(&stack);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
