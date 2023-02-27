/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
Given the head of a singly linked list, 
sort the list using insertion sort, 
and return the sorted list's head.
*/


#include <stdbool.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* insertionSortList(struct ListNode* head){

    if (!head || !head -> next)   return head;

    bool end = false;
    
    struct ListNode* cur = head;
    struct ListNode* temp;
    struct ListNode* move;
    struct ListNode* Temp;
    
    while (!end){
        if (!cur -> next){
            end = true;
            return head;
        }
        
        //first case is that the head should be changed
        if (cur -> next -> val < head -> val){   //cur -> next should be the new head
            move = cur -> next -> next;
            temp = head;
            head = cur -> next;
            head -> next = temp;
            cur -> next = move;
        }
        //recognize the new head
        
        //when the node should be inserted in the middle
        else if (cur -> next -> val < cur  -> val){
            temp = head;
            while (temp -> next -> val < cur -> next -> val && temp -> next != cur ){
                temp = temp -> next;
            }
            if (cur -> next -> next)    move = cur -> next -> next;
            else move = NULL;
            Temp = temp -> next;
            temp -> next = cur -> next;
            temp -> next -> next = Temp;
            cur -> next = move;
        }
        
        else {
            cur = cur -> next;
        }
      
    }
    return 0;
}