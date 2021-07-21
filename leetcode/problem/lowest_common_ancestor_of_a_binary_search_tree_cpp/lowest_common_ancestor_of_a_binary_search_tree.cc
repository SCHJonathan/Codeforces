// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#ifdef JONATHAN
#include "_testing.h"
#endif

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<int>
#define vull vector<int> 

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef JONATHAN_DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode*& result, TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int left = dfs(result, root->left, p, q);
        int right = dfs(result, root->right, p, q);
        int curr = left + right + (root == p || root == q);
        if (curr == 2 && !result) result = root;
        return curr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        dfs(result, root, p, q);
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({6, 2, 8, 0, 4, 7, 9, NONE, NONE, 3, 5});
    TreeNode* p = _construct_tree({2});
    TreeNode* q = _construct_tree({8});
    TreeNode* _ret_ans = _construct_tree({6});
    TreeNode* _ret = _sol.lowestCommonAncestor(root, p, q);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({6, 2, 8, 0, 4, 7, 9, NONE, NONE, 3, 5});
    TreeNode* p = _construct_tree({2});
    TreeNode* q = _construct_tree({4});
    TreeNode* _ret_ans = _construct_tree({2});
    TreeNode* _ret = _sol.lowestCommonAncestor(root, p, q);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({2, 1});
    TreeNode* p = _construct_tree({2});
    TreeNode* q = _construct_tree({1});
    TreeNode* _ret_ans = _construct_tree({2});
    TreeNode* _ret = _sol.lowestCommonAncestor(root, p, q);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
