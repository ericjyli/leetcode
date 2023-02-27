/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "stdbool.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int min = 10001;
    struct ListNode* tmp;
    struct ListNode* sortedList = NULL;
    bool done = false;


    //check not NULL
    
    while (!done){
        for (int i = 0; i < listsSize; ++i){
            if (lists[i] -> val < min){
                tmp = lists[i];
                min = lists[i] -> val;
            }
        }
        //the min node is found
        //pointed by tmp




    }

    
}



int main(void){


}


