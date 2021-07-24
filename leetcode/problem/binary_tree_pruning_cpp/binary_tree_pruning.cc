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
#define vll vector<ll>
#define vull vector<ull> 

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool dfs(TreeNode* root) {
        if (!root) return false;
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if (!left) root->left = nullptr;
        if (!right) root->right = nullptr;
        return root->val == 1 || left || right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) ? root : nullptr;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({1, NONE, 0, 0, 1});
    TreeNode* _ret_ans = _construct_tree({1, NONE, 0, NONE, 1});
    TreeNode* _ret = _sol.pruneTree(root);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 0, 1, 0, 0, 0, 1});
    TreeNode* _ret_ans = _construct_tree({1, NONE, 1, NONE, 1});
    TreeNode* _ret = _sol.pruneTree(root);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 1, 0, 1, 1, 0, 1, 0});
    TreeNode* _ret_ans = _construct_tree({1, 1, 0, 1, 1, NONE, 1});
    TreeNode* _ret = _sol.pruneTree(root);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
