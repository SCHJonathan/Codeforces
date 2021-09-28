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
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            int base = sqrt(c-i*i);
            if (base*base == c-i*i) {
                return true;
            }
        }
        return false;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int c = 5;
    bool _ret_ans = true;
    bool _ret = _sol.judgeSquareSum(c);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int c = 3;
    bool _ret_ans = false;
    bool _ret = _sol.judgeSquareSum(c);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    int c = 4;
    bool _ret_ans = true;
    bool _ret = _sol.judgeSquareSum(c);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    int c = 2;
    bool _ret_ans = true;
    bool _ret = _sol.judgeSquareSum(c);
    test("Example - 3", _ret_ans, _ret);
}


void test_example_4(Solution &_sol) {
    int c = 1;
    bool _ret_ans = true;
    bool _ret = _sol.judgeSquareSum(c);
    test("Example - 4", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
    test_example_4(_sol);
}
