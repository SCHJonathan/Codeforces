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
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int prevZero = 0, prevOne = 0;
        for (int i = 0; i < n; i++) {
            prevOne = (s[i] == '0') + min(prevZero, prevOne);
            prevZero = (s[i] == '1') + prevZero;
        }
        return min(prevZero, prevOne);
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "00110";
    int _ret_ans = 1;
    int _ret = _sol.minFlipsMonoIncr(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "010110";
    int _ret_ans = 2;
    int _ret = _sol.minFlipsMonoIncr(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "00011000";
    int _ret_ans = 2;
    int _ret = _sol.minFlipsMonoIncr(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
