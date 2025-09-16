ListNode* reverseDLL(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr) {
        // Swap next and prev pointers
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        // Move to next node (which is previous before swap)
        curr = curr->prev;
    }
    // After loop, prev points to the old head's prev, which is the new head
    if (prev) head = prev->prev;
    return head;
}