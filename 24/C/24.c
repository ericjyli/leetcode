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


struct ListNode* swapPairs(struct ListNode* head){

    struct ListNode* slow = head;
    struct ListNode* fast;
    struct ListNode* temp;
    if (head == NULL){
        return NULL;
    }
    
    fast = head -> next;
    if (fast == NULL){
        return head;
    }
    
    temp = fast -> next;    //the exit
    head = fast;
    
    fast -> next = slow;
    slow -> next = temp;
    
    struct ListNode* previous = slow;
    slow = previous -> next;
    //previous points to the location prior to the pair waiting to be swapped
    
    while (slow != NULL && slow -> next != NULL){
        fast = slow -> next;
        temp = fast -> next;    //save the exit
        previous -> next = fast;
        fast -> next = slow;
        slow -> next = temp;
        previous = slow;
        slow = slow -> next;
    }
    return head;
    
}