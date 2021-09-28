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
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {
                        if (nums[i]+nums[j]+nums[k] == nums[l]) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 2, 3, 6};
    int _ret_ans = 1;
    int _ret = _sol.countQuadruplets(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {3, 3, 6, 4, 5};
    int _ret_ans = 0;
    int _ret = _sol.countQuadruplets(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {1, 1, 1, 3, 5};
    int _ret_ans = 4;
    int _ret = _sol.countQuadruplets(nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
