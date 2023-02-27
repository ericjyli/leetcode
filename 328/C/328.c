/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the head of a singly linked list, 
group all the nodes with odd indices together
followed by the nodes with even indices, 
and return the reordered list.
*/


#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* oddEvenList(struct ListNode* head){

    struct ListNode* temp = head;
    if (head == NULL || head -> next == NULL){
        return head;
    }
    //case that there are only two or less elements in the linked list
    
    struct ListNode* odd = temp;
    struct ListNode* even = temp -> next;
    struct ListNode* evenHead = even;

    
    while (even && even -> next){
        temp = even -> next -> next;    //next even
        odd -> next = even -> next;
        odd = odd -> next;
        if (temp && temp -> next){

            even -> next = temp;
            even = even -> next;
            temp = temp -> next;
        }
        else if (temp && !temp -> next){
            even -> next = temp;
            break;
        }
        
        else if (!temp){
            even -> next = NULL;
            break;
        }
    }
    
    odd -> next = evenHead;
    return head;
}