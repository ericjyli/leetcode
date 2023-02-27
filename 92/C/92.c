/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
Given the head of a singly linked list 
and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, 
and return the reversed list.
*/


#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){

    if (left == right){
        return head;
    }
    
    struct ListNode* start = head;
    int move = left;
    while (move > 2){
        start = start -> next;
        move--;
    }
    //start -> next is the head that has to be reversed
    struct ListNode* tail;
    if (left == 1){
        tail = head;
    }
    else { 
        tail = start -> next;
    }
    
    struct ListNode* end = head;
    move = right;
    while (move > 1){
        end = end -> next;
        move --;
    }
    struct ListNode* exit = end;
    //end -> next could be NULL
    if (end -> next){
        end = end -> next;
    }
    else {
        end = NULL;
    }
    
    
    struct ListNode* temp1 = tail;
    struct ListNode* temp2 = tail -> next;
    
    if (temp1 == NULL || temp2 == NULL) return head;
    //when there are less than two nodes to be reversed
    //nothing to do
    
    struct ListNode* temp3 = tail -> next -> next;
    
    //when there are only two nodes to be reversed
    if (temp3 == NULL || (right - left) < 2){ 
        if (temp1 == start){
            temp2 -> next = temp1;
            temp1 -> next = end;
            return temp2;
        }
        else {
            start -> next = temp2;
            temp2 -> next = temp1;
            temp1 -> next = end;
            return head;
        }
    }
    
    //when there are more than two nodes to be reversed
    while (temp3 != end){
        if (temp2 -> next == NULL)  
            temp3 = end;
        else {
            temp3 = temp2 -> next;  //temp3 is the exit of the previous list
        }
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    //temp1 points to the head

    tail -> next = end;
    
    if (left == 1){
        head = temp1;
    }
    
    else {
        start -> next = temp1;
    }
    return head;
    
    
}