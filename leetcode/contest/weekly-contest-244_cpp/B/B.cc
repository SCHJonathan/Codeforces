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
    int reductionOperations(vector<int>& nums) {
        map<int, int> count;
        for (int& x : nums) count[x]++;
        vector<pair<int, int>> pairs;
        for (auto& p : count) pairs.push_back(p);
        int res = 0, idx = 0, size = pairs.size();
        for (int i = size-1; i >= 1; i--) {
            res += pairs[i].second;
            pairs[i-1].second += pairs[i].second;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {5, 1, 3};
    int _ret_ans = 3;
    int _ret = _sol.reductionOperations(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {1, 1, 1};
    int _ret_ans = 0;
    int _ret = _sol.reductionOperations(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {1, 1, 2, 2, 3};
    int _ret_ans = 4;
    int _ret = _sol.reductionOperations(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_3(Solution &_sol) {
    vector<int> nums = {7,9,10,8,6,4,1,5,2,3};
    int _ret_ans = 45;
    int _ret = _sol.reductionOperations(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
