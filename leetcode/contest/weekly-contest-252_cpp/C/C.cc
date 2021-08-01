// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
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
    long long minimumPerimeter(long long neededApples) {
        ll idx = 0;
        ll curr = 0;
        while (curr < neededApples) {
            idx++;
            curr += 12*idx*idx;
        }
        return idx*8;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    long long neededApples = 1;
    long long _ret_ans = 8;
    long long _ret = _sol.minimumPerimeter(neededApples);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    long long neededApples = 13;
    long long _ret_ans = 16;
    long long _ret = _sol.minimumPerimeter(neededApples);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    long long neededApples = 1000000000;
    long long _ret_ans = 5040;
    long long _ret = _sol.minimumPerimeter(neededApples);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
