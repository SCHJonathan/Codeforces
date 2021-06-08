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
    int memo(vector<int>& dp, vector<vector<int>>& dist, int i, int state) {
        int n = dist.size(), m = dist[0].size();
        if (i == n) return 0;
        if (dp[state] != -1) return dp[state];
        int res = INT_MAX;
        for (int j = 0; j < m; j++) {
            int x = (state>>j)&1;
            if (!x) continue;
            res = min(res, dist[i][j]+memo(dp, dist, i+1, state^(1<<j)));
        }
        return dp[state] = res;
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<vector<int>> dist(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dist[i][j] = abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
        int size = pow(2, m);
        vector<int> dp(size, -1);
        return memo(dp, dist, 0, size-1);
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> workers = {{0, 0}, {2, 1}};
    vector<vector<int>> bikes = {{1, 2}, {3, 3}};
    int _ret_ans = 6;
    int _ret = _sol.assignBikes(workers, bikes);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> workers = {{0, 0}, {1, 1}, {2, 0}};
    vector<vector<int>> bikes = {{1, 0}, {2, 2}, {2, 1}};
    int _ret_ans = 4;
    int _ret = _sol.assignBikes(workers, bikes);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> workers = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}};
    vector<vector<int>> bikes = {{0, 999}, {1, 999}, {2, 999}, {3, 999}, {4, 999}};
    int _ret_ans = 4995;
    int _ret = _sol.assignBikes(workers, bikes);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
