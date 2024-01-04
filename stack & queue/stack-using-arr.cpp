#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 1000; // Maximum size of the stack
    int arr[MAX_SIZE];
    int top; // Index of the top element

public:
    // Constructor
    Stack() {
        top = -1; // Initialize the stack with an empty state
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow: Cannot push element, the stack is full.\n";
            return;
        }

        arr[++top] = value;
        std::cout << value << " pushed to the stack.\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            std::cout << "Stack Underflow: Cannot pop element, the stack is empty.\n";
            return;
        }

        std::cout << arr[top] << " popped from the stack.\n";
        top--;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Function to get the top element of the stack
    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty.\n";
            return -1; // Assuming -1 is not a valid element in the stack
        }
        return arr[top];
    }
};

int main() {
    // Create a stack
    Stack stack;

    // Perform stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << "\n";

    stack.pop();
    stack.pop();

    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
