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
    string longestPalindrome(string s) {
        int n = s.size(), maxlen = 0; string res = "";
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) && (i+1 >= j-1 || dp[i+1][j-1]);
                if (dp[i][j] && j-i+1 > maxlen) {
                    res = s.substr(i, j-i+1);
                    maxlen = j-i+1;
                }
            }
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "babad";
    string _ret_ans = "bab";
    string _ret = _sol.longestPalindrome(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "cbbd";
    string _ret_ans = "bb";
    string _ret = _sol.longestPalindrome(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "a";
    string _ret_ans = "a";
    string _ret = _sol.longestPalindrome(s);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    string s = "ac";
    string _ret_ans = "a";
    string _ret = _sol.longestPalindrome(s);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
