// 100. Same Tree
// https://leetcode.com/problems/same-tree/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr) {
            return true;
        }

        if (p == nullptr and q != nullptr) {
            return false;
        }

        if (p != nullptr and q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        if (p->left == nullptr and q->left != nullptr) {
            return false;
        }

        if (p->left != nullptr and q->left == nullptr) {
            return false;
        }

        if (isSameTree(p->left, q->left) == false) {
            return false;
        }

        if (p->right == nullptr and q->right != nullptr) {
            return false;
        }

        if (p->right != nullptr and q->right == nullptr) {
            return false;
        }

        if (isSameTree(p->right, q->right) == false) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solution = Solution();

    TreeNode *tn1 = new TreeNode(1);
    tn1->left = new TreeNode(2);
    tn1->right = new TreeNode(3);

    TreeNode *tn2 = new TreeNode(1);
    tn2->left = new TreeNode(2);
    tn2->right = new TreeNode(3);

    assert(solution.isSameTree(tn1, tn2) == true);

    TreeNode *tn3 = new TreeNode(1);
    tn3->left = new TreeNode(2);

    TreeNode *tn4 = new TreeNode(1);
    tn4->right = new TreeNode(2);

    assert(solution.isSameTree(tn3, tn4) == false);

    TreeNode *tn6 = new TreeNode(0);

    assert(solution.isSameTree(nullptr, tn6) == false);

    return 0;
}

