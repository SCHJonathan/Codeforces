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
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        int left = 0, right = k-1;
        sort(nums.begin(), nums.end());
        while (right < n) {
            res = min(res, nums[right]-nums[left]);
            left++; right++;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {90};
    int k = 1;
    int _ret_ans = 0;
    int _ret = _sol.minimumDifference(nums, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {9, 4, 1, 7};
    int k = 2;
    int _ret_ans = 2;
    int _ret = _sol.minimumDifference(nums, k);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
