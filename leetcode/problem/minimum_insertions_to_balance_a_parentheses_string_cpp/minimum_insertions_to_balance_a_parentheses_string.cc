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
    int minInsertions(string s) {
        int curr = 0, n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                curr += 2;
            } else {
                if (curr <= 0) res++, curr += 2;
                if (i+1 < n && s[i+1] == ')') {
                    i++;
                } else {
                    res++;
                }
                curr -= 2;
            }
        }
        return res + curr;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "(()))";
    int _ret_ans = 1;
    int _ret = _sol.minInsertions(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "())";
    int _ret_ans = 0;
    int _ret = _sol.minInsertions(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "))())(";
    int _ret_ans = 3;
    int _ret = _sol.minInsertions(s);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    string s = "((((((";
    int _ret_ans = 12;
    int _ret = _sol.minInsertions(s);
    test("Example - 3", _ret_ans, _ret);
}


void test_example_4(Solution &_sol) {
    string s = ")))))))";
    int _ret_ans = 5;
    int _ret = _sol.minInsertions(s);
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
