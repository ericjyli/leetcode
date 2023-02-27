#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

/*
Companies
Given the head of a sorted linked list, 
delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. 
Return the linked list sorted as well.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if (head == NULL || head -> next == NULL){
        return head;
    }
    //the list only contains 0-1 elements
    
    //change the head first if necessary (when the duplicates occurred on the head)
    bool headFound = false;
    
    if (!head -> next || head -> next -> val != head -> val){
        headFound = true;
    }
    
    while (!headFound){
        while (head -> next && head -> next -> val == head -> val){
            head = head -> next;
        }
        
        if (head -> next != NULL){
            head = head -> next;
            if (!head -> next || head -> next -> val != head -> val){
                headFound = true;
                break;
            }
        }
        if (head -> next == NULL){
            return NULL;
        }
    }

    if (head == NULL || head -> next == NULL){
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head -> next;
    bool end = false;
    

    
    while (!end){
        while (fast -> next && fast -> next -> val != slow -> next -> val){
            fast = fast -> next;
            slow = slow -> next;
        }   //a duplicate is found or fast reaches an end when this loop ends
        
        if (fast -> next == NULL){ 
            end = true;
            break;
        }
        //when the list reaches the end

        while (fast -> next && fast -> next -> val == fast -> val){
            fast = fast -> next;
        }
        //skip all of the duplicates
        
        struct ListNode* exit = fast -> next;
        if (exit == NULL){
            slow -> next = NULL;
            end = true;
            break;
        }
        slow -> next = exit;
        fast = exit;
        
        if (fast -> next == NULL){
            end = true;
            break;
        }
        
    }
    return head;
}