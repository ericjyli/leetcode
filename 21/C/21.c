/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/


#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if (list1 == NULL && list2 == NULL)
        return NULL;
    
    struct ListNode head;
    struct ListNode *mergedList = &head;
    

    
    while (list1 != NULL && list2 != NULL){
        
        if (list1 -> val >= list2 -> val ){
            mergedList -> next = list2;
            mergedList = mergedList -> next;
            list2 = list2->next;
        }
        else if (list1 -> val < list2 -> val){
            mergedList -> next = list1;
            mergedList = mergedList -> next;
            list1 = list1 -> next;
        }
    }
    
    if (list1 != NULL)
        mergedList -> next = list1;
    
    if (list2 != NULL)
        mergedList -> next = list2;
    
    
    return head.next;
    
}