/*
You are given the head of a linked list, 
and an integer k.

Return the head of the linked list after 
swapping the values of the kth node from 
the beginning and the kth node from the end (the list is 1-indexed).
*/

#include <iostream>
using namespace std;

/*
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* swapNodes(ListNode* head, int k) {
    
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
    ListNode *front, *back;
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
        ListNode *temp1 = back -> next -> next;
        ListNode *temp2 = front -> next;
    
        front -> next = back -> next;
        back -> next = temp2;
        front -> next -> next = temp;
        back -> next -> next = temp1;
        return head;
    }

}


int main() {
    ListNode *head = new ListNode;
    head -> val = 1;

    ListNode *next1 = new ListNode;
    next1 -> val = 2;

    ListNode *next2 = new ListNode;
    next2 -> val = 3;

    ListNode *next3 = new ListNode;
    next3 -> val = 4;

    ListNode *next4 = new ListNode;
    next4 -> val = 5;

    head -> next = next1;
    next1 -> next = next2;
    next2 -> next = next3;
    next3 -> next = next4;
    next4 -> next = nullptr;

    cout << "Initial list: " << endl;

    ListNode *temp = head;
    while (temp) {
        cout << temp -> val << endl;
        if (temp -> next)
            temp = temp -> next;
        else 
            break;
    }


    ListNode *res = swapNodes(head, 4);

    cout << endl << "New list:  " << endl;
    while (res) {
        cout << res -> val << endl;
        if (res -> next) {
            res = res -> next;
        }
        else {
            break;
        }
    }


    return 0;
}
