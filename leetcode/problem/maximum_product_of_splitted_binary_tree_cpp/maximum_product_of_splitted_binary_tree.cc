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
    ull getSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }

    ull dfs(TreeNode* root, ull& sum, ull& res) {
        if (!root) return 0;
        ull left = dfs(root->left, sum, res);
        ull right = dfs(root->right, sum, res);
        ull ret = root->val+left+right;
        res = max(res, (sum-ret)*ret);
        return ret;
    }

    int maxProduct(TreeNode* root) {
        ull res = 0;
        ull sum = getSum(root);
        dfs(root, sum, res);
        return res % RANGE;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 2, 3, 4, 5, 6});
    int _ret_ans = 110;
    int _ret = _sol.maxProduct(root);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({1, NONE, 2, 3, 4, NONE, NONE, 5, 6});
    int _ret_ans = 90;
    int _ret = _sol.maxProduct(root);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({2, 3, 9, 10, 7, 8, 6, 5, 4, 11, 1});
    int _ret_ans = 1025;
    int _ret = _sol.maxProduct(root);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 1});
    int _ret_ans = 1;
    int _ret = _sol.maxProduct(root);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
