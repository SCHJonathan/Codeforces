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
    string dfs(TreeNode* node, unordered_map<string, int>& distinct, vector<TreeNode*>& result) {
        if (!node) return "#";
        string curr = to_string(node->val) + "|" + dfs(node->left, distinct, result) + "|" + dfs(node->right, distinct, result);
        distinct[curr]++; if (distinct[curr] == 2) result.push_back(node);
        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> distinct;
        dfs(root, distinct, result);
        return result;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 2, 3, 4, NONE, 2, 4, NONE, NONE, 4});
    vector<TreeNode*> _ret_ans = {_construct_tree({2, 4}), _construct_tree({4})};
    vector<TreeNode*> _ret = _sol.findDuplicateSubtrees(root);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({2, 1, 1});
    vector<TreeNode*> _ret_ans = {_construct_tree({1})};
    vector<TreeNode*> _ret = _sol.findDuplicateSubtrees(root);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({2, 2, 2, 3, NONE, 3, NONE});
    vector<TreeNode*> _ret_ans = {_construct_tree({2, 3}), _construct_tree({3})};
    vector<TreeNode*> _ret = _sol.findDuplicateSubtrees(root);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
