
/*
Given head, the head of a linked list, 
determine if the linked list has a cycle in it.
*/

#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, int> node_map;
    ListNode *temp = head;
    int i = 1;
    if (!temp)  return false;


    node_map.insert(make_pair(temp, i));
    ++i;
    if (!temp -> next)  return false;

//    temp = temp -> next;

    while (temp && temp -> next) {
        auto it = node_map.find(temp -> next);
        if (it != node_map.end()) {
            return true;
        }
        node_map.insert(make_pair(temp -> next, i));
        ++i;
        temp = temp -> next;
    }
    
    return false;
}