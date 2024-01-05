#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

void removeDuplicates(ListNode* head) {
    if (!head) {
        return;
    }

    ListNode* current = head;

    while (current) {
        ListNode* runner = current;

        while (runner->next) {
            if (runner->next->val == current->val) {
                ListNode* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
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
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    removeDuplicates(head);

    std::cout << "Linked List after removing duplicates: ";
    printLinkedList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
