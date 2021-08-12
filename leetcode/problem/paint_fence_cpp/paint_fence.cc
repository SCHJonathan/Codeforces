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
    int numWays(int n, int k) {
        if (k == 1 && n > 2) return 0;
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int n = 3;
    int k = 2;
    int _ret_ans = 6;
    int _ret = _sol.numWays(n, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int n = 1;
    int k = 1;
    int _ret_ans = 1;
    int _ret = _sol.numWays(n, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    int n = 7;
    int k = 2;
    int _ret_ans = 42;
    int _ret = _sol.numWays(n, k);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
