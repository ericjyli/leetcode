/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
Given the head of a singly linked list, 
reverse the list, and return the reversed list.
*/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *first = head;
    struct ListNode *temp;
    
    if (first == NULL)  return first;
    
    struct ListNode *second = head->next;
    if (second == NULL) return first;
    
    if (second -> next == NULL){
        first -> next = NULL;
        second -> next = first;
        return second;
    }
    
    if (second -> next != NULL){
        temp = second -> next;
    }
    
    first -> next = NULL;
    second -> next =first;
    first = second;
    second = temp;
    

    
    while (first != NULL && second != NULL && second -> next != NULL){
        temp = second -> next;
        second -> next = first;
        first = second;
        second = temp;
    }
    
    second -> next = first;
    
    head = second;
    
    return head;
}