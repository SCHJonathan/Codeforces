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
    int numberOfGoodSubsets(vector<int>& nums) {
        
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 2, 3, 4};
    int _ret_ans = 6;
    int _ret = _sol.numberOfGoodSubsets(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {4, 2, 3, 15};
    int _ret_ans = 5;
    int _ret = _sol.numberOfGoodSubsets(nums);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
