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

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll result = 0;
        int n = nums.size(); if (n == 1) return nums[0];
        int i = 1, left = 0;
        while (i < n) {
            // first find strict decrease
            while (i < n && nums[i] >= nums[i-1]) {
                i++;
            }
            result += nums[max(i-1, left)];
            // then find strict increase
            while (i < n && nums[i] <= nums[i-1]) {
                i++;
            }
            if (i < n) result -= nums[i-1];
        }
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {4, 2, 5, 3};
    long long _ret_ans = 7;
    long long _ret = _sol.maxAlternatingSum(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {5, 6, 7, 8};
    long long _ret_ans = 8;
    long long _ret = _sol.maxAlternatingSum(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {6, 2, 1, 2, 4, 5};
    long long _ret_ans = 10;
    long long _ret = _sol.maxAlternatingSum(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
