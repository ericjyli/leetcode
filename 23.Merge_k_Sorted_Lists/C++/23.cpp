#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare {
    bool operator()(struct ListNode *a, struct ListNode *b) {
        if (!a && !b)   return false; 
        if (!a) return false;
        if (!b) return true;
        return (a -> val > b -> val);
    }
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    struct ListNode *head = nullptr;
    struct ListNode *temp = nullptr;

    for (int i = 0; i < lists.size(); ++i) {
        pq.push(lists[i]);
    }

    while(!pq.empty()) {
        ListNode *top = pq.top();

        pq.pop();
        if (!top) {
            continue;
        }
        if (top->next) {
            pq.push(top->next);
        }
        if (!head) {
            head = top;
            temp = head;
        }
        else {
            temp->next = top;
            temp = temp->next;
        }
    }

    return head;

}

