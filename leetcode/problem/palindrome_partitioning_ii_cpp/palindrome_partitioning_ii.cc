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
    int minCut(string s) {
        int n = s.size();
        // 1. precompute pali[n][n] pali[i][j] = true
        vector<vector<int>> pali(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                pali[i][j] = (s[i] == s[j]) && (i+1 > j-1 || pali[i+1][j-1]);
            }
        }

        // 2. word break index i dp[i] dp[n]
        // vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            int res = INT_MAX;
            for (int j = 0; j <= i; j++) {
                if (!pali[j][i]) continue;
                int val = j > 0 ? 1+pali[0][j-1] : 1;
                res = min(res, val);
            }
            pali[0][i] = res == INT_MAX ? INT_MAX : res;
        }
        return pali[0][n-1] - 1;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "aab";
    int _ret_ans = 1;
    int _ret = _sol.minCut(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "a";
    int _ret_ans = 0;
    int _ret = _sol.minCut(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "ab";
    int _ret_ans = 1;
    int _ret = _sol.minCut(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
