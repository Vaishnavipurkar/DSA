#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to merge two unsorted linked lists
Node* mergeUnsortedLists(Node* list1, Node* list2) {
    // If either list is empty, return the other list
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    // Find the end of the first list
    Node* current = list1;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Append the second list to the end of the first list
    current->next = list2;

    return list1;
}

// Function to print a linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    // Create two unsorted linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    std::cout << "List 1: ";
    printLinkedList(list1);

    std::cout << "List 2: ";
    printLinkedList(list2);

    // Merge the two unsorted linked lists
    Node* mergedList = mergeUnsortedLists(list1, list2);

    std::cout << "Merged List: ";
    printLinkedList(mergedList);

    // Clean up memory
    delete mergedList; // Note: This deletes the merged list since it's now a single linked list.

    return 0;
}
