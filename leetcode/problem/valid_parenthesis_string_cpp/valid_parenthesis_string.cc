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
    bool checkValidString(string s) {
        int stars = 0, n = s.size(), res = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') stars++;
            else if (s[i] == '(') {
                curr++;
                curr -= min(stars, curr);
                stars = 0;
            } else {
                curr--;
                if (curr < 0) {
                    if (stars >= abs(curr)) {
                        stars += curr;
                        curr = 0;
                    }
                    else return false;
                }
            }
        }
        return curr == 0;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "()";
    bool _ret_ans = true;
    bool _ret = _sol.checkValidString(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "(*)";
    bool _ret_ans = true;
    bool _ret = _sol.checkValidString(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "(*))";
    bool _ret_ans = true;
    bool _ret = _sol.checkValidString(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
