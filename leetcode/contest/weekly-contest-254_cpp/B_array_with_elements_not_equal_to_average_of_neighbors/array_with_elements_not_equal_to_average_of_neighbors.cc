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
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; i += 2) {
            swap(nums[i], nums[i+1]);
        }
        return nums;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> _ret_ans = {1, 2, 4, 5, 3};
    vector<int> _ret = _sol.rearrangeArray(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {6, 2, 0, 9, 7};
    vector<int> _ret_ans = {9, 7, 6, 2, 0};
    vector<int> _ret = _sol.rearrangeArray(nums);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
