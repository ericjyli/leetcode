/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    int forward = n;
    if (head -> next == NULL && n == 1){
        head = NULL;
        return head;
    }   //special case when there is only one number in the list to be deleted
    
    while (forward > 0 && fast -> next != NULL){
        fast = fast -> next;
        forward--;
    }
    
    while (fast != NULL && fast -> next != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }
    
    //slow = slow -> next;
    //now fast points to the last node of the list
    //slow -> next points to the node that needed to be deleted
    
    if (forward == 0){  
        slow -> next = slow -> next -> next;
        return head;
    }
    
    else {
        slow = head;
        head = head -> next;
        slow = NULL;
        return head;
    }
    return NULL;
}