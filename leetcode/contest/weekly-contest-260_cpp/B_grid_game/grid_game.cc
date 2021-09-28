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
    long long gridGame(vector<vector<int>>& grid) {
        ll res = INT_MAX;
        int n = grid[0].size();
        vector<ll> prefix1(n+1, 0), prefix2(n+1, 0);
        for (int i = 1; i <= n; i++) {
            ll prev1 = i-1 >= 0 ? prefix1[i-1] : 0;
            ll prev2 = i-1 >= 0 ? prefix2[i-1] : 0;
            prefix1[i] = prev1+grid[0][i-1];
            prefix2[i] = prev2+grid[1][i-1];
        }
        for (int i = 1; i <= n; i++) {
            ll currRes = max(prefix1[n]-prefix1[i], prefix2[i-1]);
            debug(prefix1[n]-prefix1[i], prefix2[i-1]);
            res = min(res, currRes);
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};
    long long _ret_ans = 4;
    long long _ret = _sol.gridGame(grid);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> grid = {{3, 3, 1}, {8, 5, 2}};
    long long _ret_ans = 4;
    long long _ret = _sol.gridGame(grid);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> grid = {{1, 3, 1, 15}, {1, 3, 3, 1}};
    long long _ret_ans = 7;
    long long _ret = _sol.gridGame(grid);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
