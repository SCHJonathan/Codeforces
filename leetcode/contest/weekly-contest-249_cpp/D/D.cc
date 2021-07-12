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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<TreeNode*> trees = {{2, 1}, {3, 2, 5}, {5, 4}};
    TreeNode* _ret_ans = _construct_tree({3, 2, 5, 1, NONE, 4});
    TreeNode* _ret = _sol.canMerge(trees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    vector<TreeNode*> trees = {{5, 3, 8}, {3, 2, 6}};
    TreeNode* _ret_ans = _construct_tree({});
    TreeNode* _ret = _sol.canMerge(trees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    vector<TreeNode*> trees = {{5, 4}, {3}};
    TreeNode* _ret_ans = _construct_tree({});
    TreeNode* _ret = _sol.canMerge(trees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_3(Solution &_sol) {
    vector<TreeNode*> trees = {{2, 1, 3}};
    TreeNode* _ret_ans = _construct_tree({2, 1, 3});
    TreeNode* _ret = _sol.canMerge(trees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
