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
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> largest(n,0), smallest(n, 0);
        largest[0] = nums[0];
        smallest[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            largest[i] = max(largest[i-1], nums[i]);
        }
        for (int i = n-2; i >= 0; i--) {
            smallest[i] = min(smallest[i+1], nums[i]);
        }
        debug(nums);
        debug(smallest);
        debug(largest);
        int res = 0;
        for (int i = 1; i < n-1; i++) {
            if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                debug(nums[i-1], nums[i], nums[i+1]);
                debug(largest[i-1], nums[i], smallest[i+1]);
                if (largest[i-1] < nums[i]&& nums[i] < smallest[i+1]) {
                    debug("here");
                    res+=2;
                } else {
                    debug("here2");
                    res++;
                }
            }
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 2, 3};
    int _ret_ans = 2;
    int _ret = _sol.sumOfBeauties(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {2, 4, 6, 4};
    int _ret_ans = 1;
    int _ret = _sol.sumOfBeauties(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {3, 2, 1};
    int _ret_ans = 0;
    int _ret = _sol.sumOfBeauties(nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
