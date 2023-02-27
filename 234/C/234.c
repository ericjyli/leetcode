/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.
*/

#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverse(struct ListNode* head){
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

bool isPalindrome(struct ListNode* head) {

    if(head==NULL)  return true;
    
    struct ListNode* previous;
    struct ListNode* previousHead;
    struct ListNode* current = head;
    
    previousHead =  malloc (sizeof (struct ListNode));
    previousHead -> val = current -> val;
    
    previous = previousHead;
    current = current -> next;
    
    while (current != NULL){
        previous -> next = malloc (sizeof (struct ListNode));
        previous = previous -> next;
        previous -> val = current -> val;
        current = current -> next;
    }
    
    previous -> next =  malloc (sizeof (struct ListNode));
    previous = previous -> next;
    previous = NULL;
    // duplicate the original list into previous
    
    current = reverse (head);
    previous = previousHead;
    
    
    while (current != NULL){
        if (current -> val != previous -> val){
            return false;
        }
        else {
            current = current -> next;
            previous = previous -> next;
        }
        
    }
    return true;

    
}