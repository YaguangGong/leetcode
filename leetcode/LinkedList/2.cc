#include "leetcode/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *addTwoNumbers(ListNode<int> *l1, ListNode<int> *l2) {
        if (!l1 && !l2)
            return nullptr;
        int inc = 0;
        auto head = new ListNode<int>(-1);
        auto l = head;
        while (l1 && l2) {
            int res = l1->val + l2->val + inc;
            inc = res / 10;
            res = res % 10;
            l->next = new ListNode<int>(res);
            l = l->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
            while (l1) {
                int res = l1->val + inc;
                inc = res / 10;
                res = res % 10;
                l->next = new ListNode<int>(res);
                l = l->next;
                l1 = l1->next;
            }
        if (l2)
            while (l2) {
                int res = l2->val + inc;
                inc = res / 10;
                res = res % 10;
                l->next = new ListNode<int>(res);
                l = l->next;
                l2 = l2->next;
            }
        if (inc) {
            l->next = new ListNode<int>(inc);
            l = l->next;
        }
        return head->next;
    }
};

int main() {
    Solution sl;
    auto l1 = new ListNode<int>(1);
    auto l2 = new ListNode<int>(2);
    auto res = sl.addTwoNumbers(l1, l2);
    printLinkedList(res, false);
    return 0;
}
