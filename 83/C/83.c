/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.
*/


#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    
    struct ListNode *current = head;

    while (current != NULL && current -> next != NULL){
        if (current -> next -> val == current -> val){
            current -> next  = current -> next -> next;
        }
        else {
            current = current -> next;
        }
    }
    return head;
}