NODE* reverseList(LIST *p) {
    if (p == NULL || p->head == NULL || p->head->next == NULL) {
        // If the list is empty or has only one node, no need to reverse
        return p->head;
    }

    NODE *prevNode = NULL;
    NODE *currNode = p->head;
    NODE *nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next; // Store the next node temporarily
        currNode->next = prevNode; // Reverse the link
        prevNode = currNode;       // Move pointers forward
        currNode = nextNode;
    }

    // Update the head to the last node (prevNode)
    p->head = prevNode;

    // Return the head of the reversed list
    return p->head;
}
