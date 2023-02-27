/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values 
of the kth node from the beginning and the kth node 
from the end (the list is 1-indexed).
*/
//

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k){
    
    if (!head || !head -> next) return head;
    

    struct ListNode* temp = head;
    int l = 0;
    
    while (temp && temp -> next){
        l++;
        temp = temp -> next;
    }
    l++;
    
    if (k == l/2 + 1 && l%2 == 1){
        return head;
    }
    
    if (k > l/2){
        k = l - k + 1;
    }
    
    temp = head;
    struct ListNode* front, *back;
    front = head;
    back = head;
    
    if (k == 1){
        while (back && back -> next && back -> next -> next){
            back = back -> next;
        }
        if (front == back){
            back = front -> next;
            head = back;
            back -> next = front;
            front -> next = NULL;
            return head;
        }
        temp = front -> next;
        head = back -> next;
        back -> next = front;
        front -> next = NULL;
        
        head -> next = temp;
        return head;
    }
    
    int count = 2;
    while (count < k){
        front = front -> next;
        count++;
    }
    int move = l - k - 1;
    
    while (move > 0){
        back = back -> next;
        move--;
    }
    
    if (front -> next == back){
        temp = back -> next -> next;
        front -> next = back -> next;
        front -> next -> next = back;
        back -> next = temp;
        return head;
    }
    
    else {
        temp = front -> next -> next;
        struct ListNode* temp1 = back -> next -> next;
        struct ListNode* temp2 = front -> next;
    
        front -> next = back -> next;
        back -> next = temp2;
        front -> next -> next = temp;
        back -> next -> next = temp1;
        return head;
    }
}