struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode *front = head;
    ListNode *back;

    while (true) {
        if (front -> val == 0) {
            back = front -> next;
            while (back -> val != 0) {
                back = back -> next;
            }
            if (back -> val != 0) {
                return head;
            }

            while (front -> next != back) {
                front -> val += front -> next -> val;
                front -> next = front -> next -> next;
            }
            if (back -> next)
                front = back;
            else
                front -> next = nullptr;
        }        
        if (!front -> next)     break;
    }

    return head;
}




