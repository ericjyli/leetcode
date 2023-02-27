/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
Given the head of a linked list, 
rotate the list to the right by k places.
*/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* rotateRight(struct ListNode* head, int k){

    struct ListNode* temp = head;
    int size = 0;
    while (temp != NULL && temp -> next != NULL){
        size++;
        temp = temp -> next;
    }
    size++;
    
    int K = k % size;   //the number of elements from the end that should be put to the head
    
    if (K == 0){
        return head;
    }
    
    K = size - K - 1;   //the number of elements that should be skipped
    //2
    
    temp = head;
    int i = 0;
    
    while (K>0){
        temp = temp -> next;
        K--;
    }
    //temp now points to the node before the entire thing that has to be moved to the front
    
    struct ListNode* movedList = temp -> next;
    struct ListNode* movedHead = movedList;
    
    temp -> next = NULL;
    
    while (movedList != NULL && movedList -> next != NULL){
        movedList = movedList -> next;
    }
    //movedList = movedList -> next;
    //movedList now points to the last node
    movedList -> next = head;
    
    return movedHead;
    
}