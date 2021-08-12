// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
#else
#define debug(x...)
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
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n][n][k]; memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                
            }
        }

    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {10, 20};
    int k = 0;
    int _ret_ans = 10;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {10, 20, 30};
    int k = 1;
    int _ret_ans = 10;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {10, 20, 15, 30, 20};
    int k = 2;
    int _ret_ans = 15;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
