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
    bool gcdSort(vector<int>& nums) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {7, 21, 3};
    bool _ret_ans = true;
    bool _ret = _sol.gcdSort(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {5, 2, 6, 2};
    bool _ret_ans = false;
    bool _ret = _sol.gcdSort(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {10, 5, 9, 3, 15};
    bool _ret_ans = true;
    bool _ret = _sol.gcdSort(nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
