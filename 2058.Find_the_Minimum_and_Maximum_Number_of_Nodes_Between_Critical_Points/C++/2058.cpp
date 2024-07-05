#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> res(2, -1);
    int first = -1, last = -1;

    ListNode *temp = head;
    int i = 0, prev = -1, min_diff = -1;
    if (!temp -> next || !temp -> next -> next) {
        res[0] = -1;
        res[1] = -1;
        return res;
    }

    while (temp -> next && temp -> next -> next) {
        if ((temp -> next -> val > temp -> val && temp -> next -> val > temp -> next -> next -> val) ||
            (temp -> next -> val < temp -> val && temp -> next -> val < temp -> next -> next -> val)
        ) 
        {
            // temp -> next -> val is a critical point
            cout << "Critical point: " << (i + 1) << endl;
            if (first == -1)    first = i + 1;
            if ((i + 1) > last)     last = i + 1;

            if (prev != -1) {
                if (res[0] != 0)
                    res[0] = min((i + 1 - prev), res[0]);
                else
                    res[0] = (i + 1 - prev);
            }

            prev = i + 1;

            ++i;
            temp = temp -> next;
        }
        else {
            temp = temp -> next;
            ++i;
        }
    }

    if (last != -1 && first != last)
        res[1] = last - first;

    return res;
}