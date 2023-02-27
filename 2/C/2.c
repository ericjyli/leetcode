#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));;
    struct ListNode* newList = head;
    struct ListNode* temp;
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    int value = 0;
    int add = 0;
    bool cont = false;
    
    value = temp1 -> val + temp2 -> val + add;
    if (value >= 10){
        add = 1;
        value = value % 10;
    }
    else {
        add = 0;
    }
    newList -> val = value;
   
    temp1 = temp1 -> next;
    temp2 = temp2 -> next;

    if (temp1 == NULL && temp2 == NULL){
        if (add == 1){
            temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
            temp -> val = 1;
            temp -> next = NULL;
            newList -> next = temp;
            return head;
        }
        else{
            newList -> next = NULL;
            return head;
        }
       
    }
    
    while (temp1 != NULL && temp2 != NULL){
        temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
        value = temp1 -> val + temp2 -> val + add;
        if (value >= 10){
            add = 1;
            value = value % 10;
        }
        else {
            add = 0;
        }
        temp -> val = value;
        newList -> next = temp;
        newList = newList -> next;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;

    }

    if (temp1 == NULL && temp2 == NULL){
       if (add == 1){
            temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
            temp -> val = 1;
            temp -> next = NULL;
            newList -> next = temp;
            return head;
        }
        else{
            newList -> next = NULL;
            return head;
        }
    }
    

    if (temp1 && temp2 == NULL){
        value = temp1 -> val + add;
        if (value >= 10){
            value = value % 10;
            add = 1;
        }
        else {
            add =0;
        }
        temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
        temp -> val = value;
        newList -> next = temp;
        newList = newList -> next;
        temp1 = temp1 -> next;
        if (temp1 != NULL)  cont = true;
        while (cont == true && temp1 -> next != NULL){
            
            temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
            value = temp1 -> val + add;
            if (value >= 10){
                value = value % 10;
                add = 1;
            }
            else {
                add =0;
            }
            temp -> val = value;
            newList -> next = temp;
            newList = newList -> next;
            temp1 = temp1 -> next;
        }
        
        if (cont == true){
        temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
        value = temp1 -> val + add;
        if (value >= 10){
            value = value % 10;
            add = 1;
        }
        else {
            add =0;
        }
        temp -> val = value;
        newList -> next = temp;
        newList = newList -> next;
        //temp1 = temp1 -> next;
        }
        
        if (add ==1){   //进位之后还要进位的情况
            
            newList -> next = (struct ListNode*) malloc (sizeof(struct ListNode));
            newList = newList -> next;  // next is NULL at this point
            newList -> val = 1;
        }
        newList -> next = NULL;
        
        return head;
    
    }
    
    if (temp2 && temp1 == NULL){
        value = temp2 -> val + add;
        if (value >= 10){
            value = value % 10;
            add = 1;
        }
        else {
            add =0;
        }
        temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
        temp -> val = value;
        newList -> next = temp;
        newList = newList -> next;
        temp2 = temp2 -> next;
        if (temp2 != NULL)  cont = true;
        
        while (cont == true && temp2 -> next!= NULL ){
            cont = true;
            temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
            value = temp2 -> val + add;
            if (value == 10){
                value = 0;
                add = 1;
            }
            else {
                add =0;
            }
            temp -> val = value;
            newList -> next = temp;
            newList = newList -> next;
            temp2 = temp2 -> next;
        }
        
        if (cont ==true){
        temp = (struct ListNode*) calloc (1,sizeof(struct ListNode));
  
        value = temp2 -> val + add;
        
            if (value == 10){
                value = 0;
                add = 1;
            }
            else {
                add =0;
            }
            temp -> val = value;
            newList -> next = temp;
            newList = newList -> next;
            //temp2 = temp2 -> next;
        }
        
        if (add == 1){
            newList -> next = (struct ListNode*) calloc (1,sizeof(struct ListNode));
            newList = newList -> next;
            newList -> val = 1;
            newList -> next = NULL;
        }
        
        
        return head;
    }
  
    return 0;
}


int main (){

    struct ListNode* l11 =  malloc (sizeof(struct ListNode));
    struct ListNode* l12 = malloc (sizeof(struct ListNode));
    struct ListNode* l13 = malloc (sizeof(struct ListNode));
    
    /*
    l11 -> val = 2;
    l12 -> val = 4;
    l13 -> val = 3;
    l11 -> next =  l12;
    l12 -> next = l13;
    */
    
    l11 -> val = 0;
    l11 -> next = NULL;
    
    struct ListNode* l21 = malloc (sizeof(struct ListNode));
    struct ListNode* l22 = malloc (sizeof(struct ListNode));
    struct ListNode* l23 = malloc (sizeof(struct ListNode));
    
    /*
    l21 -> val = 5;
    l22 -> val = 6;
    l23 -> val = 4;
    l21 -> next = l22;
    l22 -> next = l23;
    */
   
    l21 -> val = 0;
    l21 -> next = NULL;
    
    struct ListNode* result = addTwoNumbers (l11,l21);
    while (result != NULL && result -> next != NULL){
        printf ("%d\n",result -> val);
        result = result -> next;
    }
    printf ("%d", result -> val);

    return 0;
}
