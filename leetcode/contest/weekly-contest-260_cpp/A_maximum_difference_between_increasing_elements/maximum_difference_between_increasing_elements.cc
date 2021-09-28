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
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[j] <= nums[i]) continue;
                res = max(res, nums[j]-nums[i]);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {7, 1, 5, 4};
    int _ret_ans = 4;
    int _ret = _sol.maximumDifference(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {9, 4, 3, 2};
    int _ret_ans = -1;
    int _ret = _sol.maximumDifference(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {1, 5, 2, 10};
    int _ret_ans = 9;
    int _ret = _sol.maximumDifference(nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
