#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* sortList(ListNode* head) {
    if (!head)  return nullptr;
    if (!head -> next)  return head;
    ListNode *temp = head;
    vector<int> arr;

    while(temp) {
        arr.push_back(temp -> val);
        if (temp -> next) {
            temp = temp -> next;
        }
        else {
            break;
        }
    }
    sort(arr.begin(), arr.end());

    ListNode *newHead = new ListNode;
    newHead -> val = arr[0];
    temp = newHead;
    for (int i = 1; i < arr.size(); ++i) {
        temp -> next = new ListNode;
        temp -> next -> val = arr[i];
        if (i != arr.size() - 1)
            temp = temp -> next;
    }
    return newHead;

}