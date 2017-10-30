Lnode *removeDuplicates (Lnode *head) {
    Lnode *curr = head;
    Lnode *curr2;
    Lnode *prev;
    Lnode *temp;
    int val;
    while (curr != NULL) {
        val = curr->data;
        prev = curr;
        curr2 = prev->next; //same as curr->next;
        while (curr2 != NULL) {//loop through rest of list after curr
            if (curr2->data == curr->data) {//found a match
                //remove match
                temp = curr2;
                prev->next = curr2->next;
                curr2 = prev;//make curr2 go back to the one before the next one we want to check
                free(temp);
            }
            prev = curr2;
            curr2 = curr2->next;
        }
        curr = curr->next;
    }
}

