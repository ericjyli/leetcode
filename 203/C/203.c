/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has 
Node.val == val, and return the new head.
*/

#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    
    while (head != NULL && head->val == val){
        head = head-> next;
    }
    struct ListNode *curr = head;

   
    struct ListNode *temp;
    
    if (head == NULL)   return head;
    
    
    while (curr != NULL && curr -> next != NULL){
        if (curr->next->val == val){
            temp = curr->next;
            curr -> next = temp -> next;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}