// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
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
    int digit(string& s, int& pos) {
        int res = 0;
        bool negative = s[pos] == '-';
        if (negative) pos++;

        while (pos < s.size() && isdigit(s[pos])) {
            res = res*10+s[pos]-'0';
            pos++;
        }
        return negative ? -1*res : res;
    }

    TreeNode* dfs(string& s, int& pos) {
        if (pos >= s.size()) return nullptr;
        int val = digit(s, pos);
        TreeNode* node = new TreeNode(val);
        if (pos >= s.size() || s[pos] == ')') {
            pos++;
            return node;
        }
        if (pos < s.size() && s[pos] == '(') node->left = dfs(s,++pos);
        if (pos < s.size() && s[pos] == '(') node->right = dfs(s, ++pos);
        if (pos < s.size() && s[pos] == ')') pos++;
        return node;
    }

    TreeNode* str2tree(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "4(2(3)(1))(6(5))";
    TreeNode* _ret_ans = _construct_tree({4, 2, 6, 3, 1, 5});
    TreeNode* _ret = _sol.str2tree(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "4(2(3)(1))(6(5)(7))";
    TreeNode* _ret_ans = _construct_tree({4, 2, 6, 3, 1, 5, 7});
    TreeNode* _ret = _sol.str2tree(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "-4(2(3)(1))(6(5)(7))";
    TreeNode* _ret_ans = _construct_tree({-4, 2, 6, 3, 1, 5, 7});
    TreeNode* _ret = _sol.str2tree(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
