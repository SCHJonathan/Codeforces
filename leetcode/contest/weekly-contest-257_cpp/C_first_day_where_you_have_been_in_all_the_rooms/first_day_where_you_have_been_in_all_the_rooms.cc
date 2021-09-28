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
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nextVisit = {0, 0};
    int _ret_ans = 2;
    int _ret = _sol.firstDayBeenInAllRooms(nextVisit);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nextVisit = {0, 0, 2};
    int _ret_ans = 6;
    int _ret = _sol.firstDayBeenInAllRooms(nextVisit);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nextVisit = {0, 1, 2, 0};
    int _ret_ans = 6;
    int _ret = _sol.firstDayBeenInAllRooms(nextVisit);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
