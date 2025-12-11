#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head) {
            res = (res <<  1) + head->val;
            cout << res << " " << endl;
            head = head->next;
        }
        return res;
    }
};


int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution sol;

    int ans = sol.getDecimalValue(head);
    cout << endl << ans << " " << endl;
    return 0;
}
