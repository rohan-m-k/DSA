LIST* mergeLists(LIST *list1, LIST *list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    NODE *temp = list1->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2->head;

    list1->count += list2->count;

    free(list2);

    return list1;
}
