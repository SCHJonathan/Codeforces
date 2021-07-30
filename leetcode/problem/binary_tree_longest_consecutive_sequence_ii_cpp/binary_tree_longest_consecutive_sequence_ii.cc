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
    unordered_map<int, int> postorder(TreeNode* root, int& result) {
        if (!root) return {};
        // {length, direction 1 (incr), -1 (decr), 0}
        auto left = postorder(root->left, result);
        auto right = postorder(root->right, result);
        vector<unordered_map<int, int>> children = {left, right};

        unordered_map<int, int> leftCurr, rightCurr;
        for (int i = 0; i < 2; i++) {
            auto& v = children[i];
            for (auto& p : v) {
                int childrenVal = i == 0 ? root->left->val : root->right->val;
                // debug(v, p, childrenVal, root->val);
                int difference = childrenVal-root->val;
                if (abs(difference) == 1) {
                    int length = root->val+p.first == childrenVal ? p.second+1 : 2;
                    debug(p, root->val, childrenVal, length);
                    if (i == 0) leftCurr[difference] = max(length, leftCurr[difference]);
                    if (i == 1) rightCurr[difference] = max(length, rightCurr[difference]);
                    result = max(result, leftCurr[difference]);
                    result = max(result, rightCurr[difference]);
                }
            }
        }
        unordered_map<int, int> currMap;
        currMap[1] = max(max(leftCurr[1], rightCurr[1]), 1);
        currMap[-1] = max(max(leftCurr[-1], rightCurr[-1]), 1);

        // debug(leftCurr, rightCurr);
        debug("===>", root->val, currMap);
        result = max(currMap[1]+currMap[-1]-1, result);
        return currMap;
    }



    int longestConsecutive(TreeNode* root) {
        int result = 0;
        postorder(root, result);
        return result;   
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    TreeNode* root = _construct_tree({1, 2, 3});
    int _ret_ans = 2;
    int _ret = _sol.longestConsecutive(root);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    TreeNode* root = _construct_tree({2, 1, 3});
    int _ret_ans = 3;
    int _ret = _sol.longestConsecutive(root);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    TreeNode* root = _construct_tree({1,2,3,4,2});
    int _ret_ans = 2;
    int _ret = _sol.longestConsecutive(root);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    TreeNode* root = _construct_tree({2,1,3,INT_MIN,5,INT_MIN,4});
    int _ret_ans = 4;
    int _ret = _sol.longestConsecutive(root);
    test("Example - 3", _ret_ans, _ret);
}

void test_example_4(Solution &_sol) {
    TreeNode* root = _construct_tree({24,25,25,26,24,26,24,25,27,23,23,25,25,23,23,26,24,26,28,24,22,22,24,26,26,26,26,22,24,22,22,INT_MIN,27,INT_MIN,25,INT_MIN,25,INT_MIN,27,INT_MIN,25,INT_MIN,21,INT_MIN,23,23,23,INT_MIN,25,INT_MIN,25,INT_MIN,27,27,25,INT_MIN,23,INT_MIN,23,INT_MIN,21,21,21});
    int _ret_ans = 8;
    int _ret = _sol.longestConsecutive(root);
    test("Example - 4", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
    test_example_4(_sol);
}
