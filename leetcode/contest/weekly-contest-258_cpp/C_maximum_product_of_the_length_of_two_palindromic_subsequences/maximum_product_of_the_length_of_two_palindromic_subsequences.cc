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
    int lps(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                int a = i+1 < n ? dp[i+1][j] : 0;
                int b = j-1 >= 0 ? dp[i][j-1] : 0;
                int c = i+1 < n && j-1 >= 0 ? dp[i+1][j-1] : 0;
                if (s[i]==s[j]) {
                    if (i == j) c++;
                    else c += 2;
                }
                dp[i][j] = max(c, max(a, b));
            }
        }
        // debug(s, dp[0][n-1]);
        return dp[0][n-1];
    }

    int maxProduct(string s) {
        int result = 0;
        int n = s.size();
        debug(n);
        int mask = (1 << n)-1;
        unordered_map<int, int> dp;

        for (int i = 1; i < mask; i++) {
            int x = i, y = (~i)&mask;
            if (dp.find(i) != dp.end()) {
                continue;
            }
            string a = "", b = "";
            for (int j = 0; j < n; j++) {
                int x = 1 << j;
                if (i & x) {
                    a += s[j];
                } else {
                    b += s[j];
                }
            }
            // debug(a, b);

            int lenX = lps(a), lenY = lps(b);
            // debug(lenX, lenY);
            if (lenX*lenY > result) {
                debug(lenX, lenY);
            }
            result = max(result, lenX*lenY);
            dp[x] = lenX, dp[y] = lenY;
        }
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "leetcodecom";
    int _ret_ans = 9;
    int _ret = _sol.maxProduct(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "bb";
    int _ret_ans = 1;
    int _ret = _sol.maxProduct(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "accbcaxxcxx";
    int _ret_ans = 25;
    int _ret = _sol.maxProduct(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
