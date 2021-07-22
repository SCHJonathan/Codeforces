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

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vll> dp(m+1, vll(n,0));
        
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + points[i-1][0];
            
            for(int j = 1; j < n; j++)
                dp[i][j] = max(dp[i-1][j] + points[i-1][j], dp[i][j-1]-1);
            
            dp[i][n-1] = max(dp[i][n-1], dp[i-1][n-1] + points[i-1][n-1]);

            for(int j = n-2; j >= 0; j--)
                dp[i][j] = max(dp[i][j], dp[i][j+1]-1);
        }
        
        return *max_element(dp[m].begin(), dp[m].end());
    }
};
// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    long long _ret_ans = 9;
    long long _ret = _sol.maxPoints(points);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> points = {{1, 5}, {2, 3}, {4, 2}};
    long long _ret_ans = 11;
    long long _ret = _sol.maxPoints(points);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
