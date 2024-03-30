NODE* findSmallestNode(LIST *p) {
    if (p == NULL || p->head == NULL) {
        // If the list is empty, return NULL
        return NULL;
    }

    NODE *smallestNode = p->head;
    NODE *currentNode = p->head->next;

    while (currentNode != NULL) {
        // Compare the data of the current node with the smallest node found so far
        // If the current node's data is smaller, update the smallestNode pointer
        if (*((int *)currentNode->dp) < *((int *)smallestNode->dp)) {
            smallestNode = currentNode;
        }
        currentNode = currentNode->next; // Move to the next node
    }

    return smallestNode;
}
