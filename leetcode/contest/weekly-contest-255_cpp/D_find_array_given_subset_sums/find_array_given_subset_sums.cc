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
    vector<int> recoverArray(int n, vector<int>& sums) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int n = 3;
    vector<int> sums = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<int> _ret_ans = {1, 2, -3};
    vector<int> _ret = _sol.recoverArray(n, sums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int n = 2;
    vector<int> sums = {0, 0, 0, 0};
    vector<int> _ret_ans = {0, 0};
    vector<int> _ret = _sol.recoverArray(n, sums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    int n = 4;
    vector<int> sums = {0, 0, 5, 5, 4, -1, 4, 9, 9, -1, 4, 3, 4, 8, 3, 8};
    vector<int> _ret_ans = {0, -1, 4, 5};
    vector<int> _ret = _sol.recoverArray(n, sums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
