/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/


#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int getDecimalValue(struct ListNode* head){
    
    struct ListNode* temp = head;
    int count = 0;
    while (temp != NULL && temp -> next != NULL){
        count++;
        temp = temp -> next;
    }
    count++;
    
    temp = head;
    int *binaryNum = malloc (count * sizeof(int));
    count--;
    
    int i=0;
    while (temp != NULL && temp -> next != NULL){
        binaryNum[i] = temp -> val;
        i++;
        temp = temp -> next;
    }
    binaryNum[i] = temp -> val;

    
    int decimalNum = 0;
    i=0;
    while (count >= 0){
        decimalNum = decimalNum + (binaryNum[i] * (pow(2,count)));
        count --;
        i++;
    }
    
    free (binaryNum);
    
    return decimalNum;
    
    
}