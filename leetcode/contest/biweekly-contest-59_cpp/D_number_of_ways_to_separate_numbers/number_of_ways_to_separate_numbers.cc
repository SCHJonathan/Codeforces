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
    int numberOfCombinations(string num) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string num = "327";
    int _ret_ans = 2;
    int _ret = _sol.numberOfCombinations(num);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string num = "094";
    int _ret_ans = 0;
    int _ret = _sol.numberOfCombinations(num);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string num = "0";
    int _ret_ans = 0;
    int _ret = _sol.numberOfCombinations(num);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    string num = "9999999999999";
    int _ret_ans = 101;
    int _ret = _sol.numberOfCombinations(num);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
