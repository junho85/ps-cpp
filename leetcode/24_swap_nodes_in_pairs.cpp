// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto *result_ln = new ListNode(0); // head node

        ListNode *tmp = head;

        int i = 0;
        int before;
        while (tmp) {
            if (i % 2 == 0) {
                before = tmp->val;
            } else {
                append(result_ln, tmp->val);
                append(result_ln, before);
            }
            tmp = tmp->next;
            i++;
        }

        if (i % 2 == 1) {
            append(result_ln, before);
        }

        return result_ln->next;
    }

    void print(ListNode *ln) {
        ListNode *tmp = ln;

        while (tmp) {
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
    }

    void append(ListNode *ln, int val) {
        ListNode *tmp = ln;

        // get last node
        while (tmp->next) {
            tmp = tmp->next;
        }

        tmp->next = new ListNode(val);
    }

};

int main() {
    Solution solution = Solution();

    auto *ln1 = new ListNode(1);
    solution.append(ln1, 2);
    solution.append(ln1, 3);
    solution.append(ln1, 4);

    auto result = solution.swapPairs(ln1);
    solution.print(result);

    auto *ln2 = new ListNode(1);

    result = solution.swapPairs(ln2);
    solution.print(result);


    return 0;
}