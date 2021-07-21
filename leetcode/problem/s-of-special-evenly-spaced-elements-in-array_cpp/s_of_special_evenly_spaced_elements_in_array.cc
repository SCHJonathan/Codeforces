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

class Solution {
public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

        vector<int> answer(m, -1);
        auto comparator = [&](auto& x, auto& y) {return x[0] > y[0];};
        priority_queue<array<int,4>, vector<array<int,4>>, decltype(comparator)>pq(comparator);

        for (int i = 0; i < m; i++) pq.push({queries[i][0], queries[i][1], i, 0});

        while (!pq.empty()) {
            auto {queries[i]}
        }
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> queries = {{0, 3}, {5, 1}, {4, 2}};
    vector<int> _ret_ans = {9, 18, 10};
    vector<int> _ret = _sol.solve(nums, queries);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {100, 200, 101, 201, 102, 202, 103, 203};
    vector<vector<int>> queries = {{0, 7}};
    vector<int> _ret_ans = {303};
    vector<int> _ret = _sol.solve(nums, queries);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
