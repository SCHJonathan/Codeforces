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
    int memo(vector<vint>& dp, vector<int>& piles, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        int res = dp[i][j] = max(piles[i]-memo(dp, piles, i+1, j), piles[j]-memo(dp, piles, i, j-1));
        return res;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // {start, end, person}
        vector<vint> dp(n, vint(n, INT_MIN));
        int res = memo(dp, piles, 0, n-1) > 0;
        return res > 0;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> piles = {5, 3, 4, 5};
    bool _ret_ans = true;
    bool _ret = _sol.stoneGame(piles);
    test("Example - 0", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
}
