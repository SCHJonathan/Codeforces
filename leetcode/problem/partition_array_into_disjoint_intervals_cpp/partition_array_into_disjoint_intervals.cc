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
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int maxval[n], minval[n];
        memset(maxval, 0, sizeof(maxval));
        memset(minval, 0, sizeof(minval));
        
        for (int i = 0; i < n; i++) {
            maxval[i] = i>0 ? max(nums[i], maxval[i-1]) : nums[i];
        }

        for (int i = n-1; i >= 0; i--) {
            minval[i] = i < n-1 ? min(nums[i], minval[i+1]) : nums[i];
        }
        
        for (int i = 0; i < n-1; i++) {
            if (maxval[i] <= minval[i+1]) {
                return i+1;
            }
        }
        return -1;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {5, 0, 3, 8, 6};
    int _ret_ans = 3;
    int _ret = _sol.partitionDisjoint(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {1, 1, 1, 0, 6, 12};
    int _ret_ans = 4;
    int _ret = _sol.partitionDisjoint(nums);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<int> nums = {1,1,1,0,6,12};
    int _ret_ans = 4;
    int _ret = _sol.partitionDisjoint(nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
