/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the head of a singly linked list, 
return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/


#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    int size = 1;
    struct ListNode* temp = head;
    while (temp != NULL && temp -> next != NULL){
        size++;
        temp = temp -> next;
    }
    
    
    temp = head;
    
    if (size % 2 == 1){
        for (int i=0; i<size/2; i++){
            temp = temp -> next;
        }
        return temp;
    }
    
    if (size % 2 == 0){
        for (int i=0; i<size/2; i++){
            temp = temp -> next;
        }
        return temp;
    }
    
    return temp;
}