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
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[n-1] = costs[n-1];
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    dp[i][j] = min(dp[i][j], costs[i][j]+dp[i+1][k]);
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < 3; i++)
            res = min(res, dp[0][i]);
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> costs = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    int _ret_ans = 10;
    int _ret = _sol.minCost(costs);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> costs = {{7, 6, 2}};
    int _ret_ans = 2;
    int _ret = _sol.minCost(costs);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
