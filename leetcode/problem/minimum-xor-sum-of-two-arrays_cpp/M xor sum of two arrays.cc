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

class Solution {
public:
    int memo(vector<vector<int>>& xors,
             vector<int>& dp,
             int i, int state) {
        int n = xors.size();
        if (i == n) return 0;
        if (dp[state] != -1) return dp[state];
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            int x = (state>>j)&1;
            if (!x) continue;
            res = min(res, xors[i][j]+memo(xors, dp, i+1, state^(1<<j)));
        }
        return dp[state] = res;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> xors(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                xors[i][j] = nums1[i]^nums2[j];
        int size = pow(2, n)-1;
        vector<int> dp(size+1, -1);
        return memo(xors, dp, 0, size);
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {2, 3};
    int _ret_ans = 2;
    int _ret = _sol.minimumXORSum(nums1, nums2);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums1 = {1, 0, 3};
    vector<int> nums2 = {5, 3, 4};
    int _ret_ans = 8;
    int _ret = _sol.minimumXORSum(nums1, nums2);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
