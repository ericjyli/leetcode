//Leetcode Question 143
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* recursion(struct ListNode* head){
    struct ListNode* temp = head;
    
    if (!temp -> next|| ! temp -> next -> next){   //less than two nodes left in the list
        return head;
    }

    while (temp -> next -> next){
        temp = temp -> next;
    }


    temp -> next -> next= head -> next;
    //move the back to the front
    head -> next = temp -> next;
    temp -> next = NULL;
    head -> next -> next = recursion(head -> next -> next);
    return head;
    
}

void reorderList(struct ListNode* head){
    
    head = recursion (head);
}


int main(void){
    struct ListNode* head = malloc (sizeof(struct ListNode));
    head -> val = 1;
    struct ListNode* temp = head;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 2;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 3;
    temp -> next = malloc (sizeof(struct ListNode));
    temp = temp -> next;
    temp -> val = 4;
    temp -> next = NULL;

    reorderList (head);



    return 0;
}


