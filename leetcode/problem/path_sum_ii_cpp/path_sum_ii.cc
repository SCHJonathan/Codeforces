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
    void dfs(vector<vector<int>>& result, vector<int>& curr, TreeNode* root, int& targetSum, int sum) {
        curr.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == targetSum) result.push_back(curr);
            curr.pop_back();
            return;
        }
        if (root->left) dfs(result, curr, root->left, targetSum, sum);
        if (root->right) dfs(result, curr, root->right, targetSum, sum);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr; 
        vector<vector<int>> result;
        if (!root) return result;
        dfs(result, curr, root, targetSum, 0);
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({5, 4, 8, 11, NONE, 13, 4, 7, 2, NONE, NONE, 5, 1});
    int targetSum = 22;
    vector<vector<int>> _ret_ans = {{5, 4, 11, 2}, {5, 8, 4, 5}};
    vector<vector<int>> _ret = _sol.pathSum(root, targetSum);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 2, 3});
    int targetSum = 5;
    vector<vector<int>> _ret_ans = {};
    vector<vector<int>> _ret = _sol.pathSum(root, targetSum);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 2});
    int targetSum = 0;
    vector<vector<int>> _ret_ans = {};
    vector<vector<int>> _ret = _sol.pathSum(root, targetSum);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
