/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
*/


#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *currentA = headA;
    struct ListNode *currentB = headB;
    int sizeA=0;
    int sizeB=0;
    
    while (currentA){
        sizeA++;
        currentA = currentA -> next;
    }
    
    while (currentB){
        sizeB++;
        currentB = currentB -> next;
    }
    
    currentA = headA;
    currentB = headB;
    
    int sizeDif=0;  int i=0;
    
    if (sizeA >= sizeB){
        sizeDif = sizeA - sizeB;
        for (i=0; i<sizeDif; i++){
            currentA = currentA -> next;
        }
    }
    
    if (sizeA < sizeB){
        sizeDif = sizeB - sizeA;
        for (i=0; i<sizeDif; i++){
            currentB = currentB -> next;
        }
    }
    
    while (currentA != currentB && currentA && currentB){
        currentA = currentA -> next;
        currentB = currentB -> next;
    }
    
    if (currentA == currentB){
        return currentA;
    }
    
    else{
        return NULL;
    }
    
}