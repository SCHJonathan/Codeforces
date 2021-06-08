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
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        ll res = 0, n = nums1.size();
        vector<ll> difference(n, 0);
        for (int i = 0; i < n; i++)
            difference[i] = nums2[i]-nums1[i];
        for (int i = 0; i < n; i++) {
            
            res += 
        }
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums1 = {2, 1, 2, 1};
    vector<int> nums2 = {1, 2, 1, 2};
    long long _ret_ans = 1;
    long long _ret = _sol.countPairs(nums1, nums2);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums1 = {1, 10, 6, 2};
    vector<int> nums2 = {1, 4, 1, 5};
    long long _ret_ans = 5;
    long long _ret = _sol.countPairs(nums1, nums2);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
