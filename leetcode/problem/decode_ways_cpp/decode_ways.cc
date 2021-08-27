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
    bool isValidTwo(string& s, int idx) {
        if (idx == 0 || s[idx-1] == '0') return false;
        return (s[idx-1]-'0')*10+s[idx]-'0' <= 26;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i-1] != '0') dp[i] += dp[i-1];
            if (isValidTwo(s, i-1)) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "12";
    int _ret_ans = 2;
    int _ret = _sol.numDecodings(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "226";
    int _ret_ans = 3;
    int _ret = _sol.numDecodings(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "0";
    int _ret_ans = 0;
    int _ret = _sol.numDecodings(s);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    string s = "06";
    int _ret_ans = 0;
    int _ret = _sol.numDecodings(s);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
