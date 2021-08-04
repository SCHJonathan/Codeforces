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
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int zero = nums[0] == 0, one = 0, two = 0;
        for (int i = 1; i < n; i++) {
            zero = nums[i] == 0 ? ((zero*2)%RANGE+1) % RANGE : zero;
            one = nums[i] == 1 ? ((one*2)%RANGE + zero)%RANGE : one;
            two = nums[i] == 2 ? ((two*2)%RANGE + one)%RANGE : two;
        }
        return two;
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
