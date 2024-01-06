#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

void removeNthNode(ListNode*& head, int n) {
    if (!head || n <= 0) {
        return;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        if (!fast) {
            delete dummy;
            return; // Invalid n, n is greater than the length of the linked list
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the nth node
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    // Update head if the first node is deleted
    head = dummy->next;

    delete dummy;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    int n = 2;
    removeNthNode(head, n);

    std::cout << "Linked List after removing " << n << "th node: ";
    printLinkedList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
