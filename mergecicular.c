LIST* mergeCircularLists(LIST *list1, LIST *list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    NODE *temp1 = list1->head;
    NODE *temp2 = list2->head;

    while (temp1->next != list1->head) {
        temp1 = temp1->next;
    }

    while (temp2->next != list2->head) {
        temp2 = temp2->next;
    }

    temp1->next = list2->head;
    temp2->next = list1->head;

    list1->count += list2->count;

    free(list2);

    return list1;
}
