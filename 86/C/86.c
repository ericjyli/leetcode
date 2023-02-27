/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the head of a linked list and a value x, 
partition it such that all nodes less than x 
come before nodes greater than or equal to x.

You should preserve the original relative order of 
the nodes in each of the two partitions.
*/


#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* partition(struct ListNode* head, int x){
    
    if (head == NULL)   return NULL;
    if (head -> next == NULL)   return head;
    


    struct ListNode* small = head;
    struct ListNode* large = head;
    

    
    //First, find the head for the smaller partition
    while (small -> val >=x && small -> next){
        small = small -> next;
    }
    
    if (small -> val >= x) {
        return head;
    }        
    //Second, find the head for the large partition
    while (large -> val < x && large -> next){
        large = large -> next;
    }
    
    if (large -> val < x){
        return head;
    }
    
    //Run through the entire list to update the small and large lists
    //small:
    struct ListNode* temp = head; 
    struct ListNode* smallHead = malloc (sizeof(struct ListNode));
    struct ListNode* largeHead = malloc (sizeof(struct ListNode));

    smallHead -> val = small -> val;
    largeHead -> val = large -> val;
    struct ListNode* smallMove = smallHead;
    struct ListNode* largeMove = largeHead;
    
    while (temp && temp -> next){
        if (temp -> val < x){
            if (temp == small){
                temp = temp -> next;
            }
            else {
                smallMove -> next = malloc (sizeof(struct ListNode));
                smallMove = smallMove -> next;
                smallMove -> val = temp -> val;
                temp = temp -> next;
            }
        }
        
        else {
            if (temp == large){
                temp = temp -> next;
            }
            else {
                largeMove -> next = malloc (sizeof(struct ListNode));
                largeMove = largeMove -> next;
                largeMove -> val = temp -> val;
                temp = temp -> next;
            }
        }
    }
    //temp now points to the last node
    if (temp == small){ 
        smallHead = small;
        small -> next = largeHead;
        largeMove -> next = NULL;
        return smallHead;
    }
        
    if (temp == large){
        return head;
        
    }
    if (temp -> val < x){
        smallMove -> next = malloc (sizeof(struct ListNode));
        smallMove = smallMove -> next;
        smallMove -> val = temp -> val;
        
    }
        
    else {
        largeMove -> next = malloc (sizeof(struct ListNode));
        largeMove = largeMove -> next;
        largeMove -> val = temp -> val;
        
    }
    
    largeMove -> next = NULL;
    smallMove -> next = largeHead;
    return smallHead;
}
   