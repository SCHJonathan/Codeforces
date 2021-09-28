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
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0]+s1[i-1];
        }
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i-1]+s2[i-1];
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min((s1[i-1]+s2[j-1])*(s1[i-1]!=s2[j-1])+dp[i-1][j-1], 
                               min(s1[i-1]+dp[i-1][j], s2[j-1]+dp[i][j-1]));
                debug(i, j, int(s1[i-1]), int(s2[j-1]), (s1[i-1]+s2[j-1])*(s1[i-1]!=s2[i-1])+dp[i-1][j-1], s1[i-1]+dp[i-1][j], s2[j-1]+dp[i][j-1]);
            }
        }
        
        debug(dp);
        return dp[m][n];
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s1 = "sea";
    string s2 = "eat";
    int _ret_ans = 231;
    int _ret = _sol.minimumDeleteSum(s1, s2);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s1 = "delete";
    string s2 = "leet";
    int _ret_ans = 403;
    int _ret = _sol.minimumDeleteSum(s1, s2);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
