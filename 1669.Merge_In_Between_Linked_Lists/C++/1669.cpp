struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    int num = 1;
    ListNode *temp = list1;

    while (temp && temp -> next) {
        if (num == a) {
            break;
        }        
        temp = temp -> next;
        num++;

    }    
    ListNode *removed_list = temp -> next;
    temp -> next = list2;

    while (removed_list && removed_list -> next) {
        if (num == b) {
            break;
        }
        removed_list = removed_list -> next;
        num++;

    }

    while (list2 && list2 -> next) {
        list2 = list2 -> next;
    }
    list2 -> next = removed_list -> next;

    return list1;
}


