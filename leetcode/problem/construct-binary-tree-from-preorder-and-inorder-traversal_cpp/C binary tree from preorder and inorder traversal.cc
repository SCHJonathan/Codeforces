// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int> 

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * 
 */
class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& idxmap, int& idx, int left, int right) {
        if (left > right) return nullptr;
        int val = preorder[idx++];
        TreeNode* curr = new TreeNode(val);
        int inorderIdx = idxmap[val];
        curr->left = dfs(preorder, inorder, idxmap, idx, left, inorderIdx-1);
        curr->right = dfs(preorder, inorder, idxmap, idx, inorderIdx+1, right);
        return curr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        unordered_map<int, int> idxmap;
        for (int i = 0; i < inorder.size(); i++) idxmap[inorder[i]] = i;
        return dfs(preorder, inorder, idxmap, idx, 0, inorder.size()-1);
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* _ret_ans = _construct_tree({3, 9, 20, NONE, NONE, 15, 7});
    TreeNode* _ret = _sol.buildTree(preorder, inorder);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> preorder = {-1};
    vector<int> inorder = {-1};
    TreeNode* _ret_ans = _construct_tree({-1});
    TreeNode* _ret = _sol.buildTree(preorder, inorder);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
