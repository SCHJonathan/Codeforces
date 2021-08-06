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
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st; st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.size() == 1) {
                    st = stack<int>();
                    st.push(i);
                    continue;
                }
                st.pop();
                res = max(res, i-st.top());
            }
        }
        return res;
    }

    int longestValidParenthesesTwoScan(string s) {
        int left = 0, right = 0, res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) res = max(res, left*2);
            else if (right > left) left = right = 0;
        }
        left = right = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) res = max(res, left*2);
            else if (left > right) left = right = 0;   
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "(()";
    int _ret_ans = 2;
    int _ret = _sol.longestValidParentheses(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = ")()())";
    int _ret_ans = 4;
    int _ret = _sol.longestValidParentheses(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "";
    int _ret_ans = 0;
    int _ret = _sol.longestValidParentheses(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
