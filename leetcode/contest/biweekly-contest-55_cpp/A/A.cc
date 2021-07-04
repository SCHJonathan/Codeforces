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

    bool helper(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            debug(nums[i], nums[i-1]);
            if (nums[i] <= nums[i-1]) {
                debug("reach");
                return false;
            }
        }
        return true;
    }

    bool canBeIncreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                vector<int> copy = nums;
                copy.erase(copy.begin()+i);
                debug(copy);
                if (helper(copy)) return true;
                copy = nums;
                copy.erase(copy.begin()+(i-1));
                debug(copy);
                if (helper(copy)) return true;
                return false;
            }
        }
        return true;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 2, 10, 5, 7};
    bool _ret_ans = true;
    bool _ret = _sol.canBeIncreasing(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {2, 3, 1, 2};
    bool _ret_ans = false;
    bool _ret = _sol.canBeIncreasing(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {1, 1, 1};
    bool _ret_ans = false;
    bool _ret = _sol.canBeIncreasing(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_3(Solution &_sol) {
    vector<int> nums = {1, 2, 3};
    bool _ret_ans = true;
    bool _ret = _sol.canBeIncreasing(nums);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
