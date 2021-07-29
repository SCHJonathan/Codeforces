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
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vll> result;
        int n = segments.size();
        sort(segments.begin(), segments.end());
        priority_queue<vint, vector<vint>, greater<vint>> pq;
        for (auto& v : segments) {
            int start = v[0], end = v[1], color = v[2];
        }
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> segments = {{1, 4, 5}, {4, 7, 7}, {1, 7, 9}};
    vector<vector<long long>> _ret_ans = {{1, 4, 14}, {4, 7, 16}};
    vector<vector<long long>> _ret = _sol.splitPainting(segments);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> segments = {{1, 7, 9}, {6, 8, 15}, {8, 10, 7}};
    vector<vector<long long>> _ret_ans = {{1, 6, 9}, {6, 7, 24}, {7, 8, 15}, {8, 10, 7}};
    vector<vector<long long>> _ret = _sol.splitPainting(segments);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> segments = {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}};
    vector<vector<long long>> _ret_ans = {{1, 4, 12}, {4, 7, 12}};
    vector<vector<long long>> _ret = _sol.splitPainting(segments);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
