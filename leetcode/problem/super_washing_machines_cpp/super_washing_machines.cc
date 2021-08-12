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
    int findMinMoves(vector<int>& machines) {
        
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> machines = {1, 0, 5};
    int _ret_ans = 3;
    int _ret = _sol.findMinMoves(machines);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> machines = {0, 3, 0};
    int _ret_ans = 2;
    int _ret = _sol.findMinMoves(machines);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> machines = {0, 2, 0};
    int _ret_ans = -1;
    int _ret = _sol.findMinMoves(machines);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
