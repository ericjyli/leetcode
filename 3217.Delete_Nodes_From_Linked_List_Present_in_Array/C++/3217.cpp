#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_map<int, int> mm;
    for (int i = 0; i < nums.size(); ++i) {
        mm.insert({nums[i], 1});
    }

    while (head) {
        if (mm.find(head -> val) != mm.end()) {
            head = head -> next;
        }
        else {
            break;
        }
    }

    ListNode *temp = head;

    while (temp && temp -> next) {
        if (mm.find(temp -> next -> val) != mm.end()) {
            temp -> next = temp -> next -> next;
        }
        else
            temp = temp -> next;
    }

    return head;
}


