Node* findMiddleCountingNodes(Node* head) {
    if (!head) {
        return nullptr; // Empty list
    }

    int count = 0;
    Node* middle = head;
    Node* current = head;

    while (current) {
        if (count % 2 == 1) {
            middle = middle->next;
        }
        count++;
        current = current->next;
    }

    return middle; // Middle node
}
