//leetcode 148
//Sort list (linkedList)

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};
 


struct ListNode* sortList(struct ListNode* head){
    if (!head || !head -> next)  return head;
    
    struct ListNode* p = head;
    struct ListNode* smallHead = head;
    struct ListNode* move;
    struct ListNode* temp;
    struct ListNode* Temp;
    
    while (p){
        
        if (!p -> next){
            break;
        }
        if (p -> next -> val >= p -> val){
            p = p -> next;
        }
        else if (p -> next -> val < smallHead -> val){  
            //p -> next should be the head
            //p -> next -> next should be connected after p
            if (p -> next -> next){
                move = p -> next -> next;
            }
            else {
                move = NULL;
            }
            
            head = p -> next;
            head -> next = smallHead;
            smallHead = head;
            p -> next = move;
            
        }
        
        else if (p -> next -> val < p -> val){
            Temp = head;
            while (Temp -> next -> val < p -> next -> val){
                Temp = Temp -> next;
            }
            
            if (p -> next -> next){
                move = p -> next -> next;
            }
            else {
                move = NULL;
            }  
            
            temp = Temp -> next;
            Temp -> next = p -> next;
            Temp -> next -> next = temp;
            p -> next = move;
        }
    }
    
    return head;
}

int main (void){
    struct ListNode* head = malloc (sizeof(struct ListNode));
    head -> val = 2;
    struct ListNode* temp = head;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 4;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 1;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 5;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 3;
    temp -> next = NULL;

    head = sortList (head);



    return 0;
}
