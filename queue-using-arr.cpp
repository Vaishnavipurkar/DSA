#include <iostream>

class Queue {
private:
    static const int MAX_SIZE = 1000; // Maximum size of the queue
    int arr[MAX_SIZE];
    int front; // Front of the queue
    int rear;  // Rear of the queue

public:
    // Constructor
    Queue() : front(-1), rear(-1) {}

    // Function to enqueue (add) an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow: Cannot enqueue, the queue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; // Circular increment to wrap around
        }

        arr[rear] = value;
        std::cout << value << " enqueued to the queue.\n";
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow: Cannot dequeue, the queue is empty.\n";
            return;
        }

        int dequeuedValue = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; // Circular increment to wrap around
        }

        std::cout << dequeuedValue << " dequeued from the queue.\n";
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1; // Assuming -1 is not a valid element in the queue
        }
        return arr[front];
    }
};

int main() {
    // Create a queue
    Queue queue;

    // Perform queue operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.peek() << "\n";

    queue.dequeue();
    queue.dequeue();

    std::cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
