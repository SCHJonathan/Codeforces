// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
#else
#define debug(x...)
#endif

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

const int RANGE = 1e9+7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int start = 0, end = 0;
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front(); q.pop();
                if (i == 0) start = index;
                if (i == size-1) end = index;
                if (node->left) {
                    q.push({node->left, index*2-start});
                }
                if (node->right) {
                    q.push({node->right, index*2+1-start});
                }
            }
            res = max(res, end-start+1);
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 3, 2, 5, 3, NONE, 9});
    int _ret_ans = 4;
    int _ret = _sol.widthOfBinaryTree(root);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 3, NONE, 5, 3});
    int _ret_ans = 2;
    int _ret = _sol.widthOfBinaryTree(root);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 3, 2, 5});
    int _ret_ans = 2;
    int _ret = _sol.widthOfBinaryTree(root);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 3, 2, 5, NONE, NONE, 9, 6, NONE, NONE, 7});
    int _ret_ans = 8;
    int _ret = _sol.widthOfBinaryTree(root);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
