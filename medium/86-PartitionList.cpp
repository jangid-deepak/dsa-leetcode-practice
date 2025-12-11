#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
       ListNode* partition(ListNode* head, int x) {
        // heads with zero value
        ListNode before(0), after(0);
        ListNode* beforeCurr =  &before;
        ListNode* afterCurr = &after;

        while(head) {
            if (head->val < x) {
                beforeCurr->next = head;
                beforeCurr = beforeCurr->next;
            } else {
                afterCurr->next = head;
                afterCurr = afterCurr->next;
            }
            head = head->next;
        }

        afterCurr->next = nullptr;
        beforeCurr->next = after.next;
        return before.next;

    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 4, 3, 2, 5, 2};

    ListNode*  head = new ListNode(nums[0]);
    ListNode* curr = head;
    for(int i=1; i<nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    
    head = sol.partition(head, 3);
    // print list
    curr = head;
    bool first = true;
    while(curr) {
        if (!first) cout << " -> ";
        cout << curr->val;
        first = false;
        curr = curr->next;
    }


    cout << endl;
    return 0;
}