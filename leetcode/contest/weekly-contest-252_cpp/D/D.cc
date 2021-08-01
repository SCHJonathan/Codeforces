// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
#endif

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

const int RANGE = 1e9+7;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {

        int res = 0;
        int n = nums.size();
        int one = 0, zero = 0;
        vector<ll> pow(n, 1);
        for (int i = 1; i < n; i++) pow[i] = (pow[i-1]*2)%RANGE;
        for (int i = 1; i < n; i++) pow[i] = (pow[i]-1+RANGE)%RANGE;
        // vector<vector<ll>> dp(n, vll(3, 0));
        for (int i = 0; i < n; i++) {
            // int zero = i-1 >= 0 ? dp[i-1][0] : 0;
            // int one = i-1 >= 0 ? dp[i-1][1] : 0;
            // int two = i-1 >= 0 ? dp[i-1][2] : 0;

            if (nums[i] == 0) zero++;
            else if (nums[i] == 1) {
                debug(zero, one);
                one = (one + pow[zero])%RANGE;
                debug(one);
            } else {
                res = (res+one)%RANGE;
            }
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {0, 1, 2, 2};
    int _ret_ans = 3;
    int _ret = _sol.countSpecialSubsequences(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {2, 2, 0, 0};
    int _ret_ans = 0;
    int _ret = _sol.countSpecialSubsequences(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {0, 1, 2, 0, 1, 2};
    int _ret_ans = 7;
    int _ret = _sol.countSpecialSubsequences(nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
