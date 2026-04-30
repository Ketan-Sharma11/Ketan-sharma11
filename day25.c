struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    
    if (fast == NULL || fast->next == NULL) return NULL;

    
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }

    return head; 
}
