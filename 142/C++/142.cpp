/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode*, int> node_map;
    ListNode *temp = head;
    int i = 1;
    if (!temp)  return nullptr;

    node_map.insert(make_pair(temp, i));
    ++i;
    if (!temp -> next)  return nullptr;

    //temp = temp -> next;

    while (temp && temp -> next) {
        auto it = node_map.find(temp -> next);
        if (it != node_map.end()) {
            return temp -> next;
        }
        node_map.insert(make_pair(temp -> next, i));
        ++i;
        temp = temp -> next;
    }
    
    return nullptr;
}