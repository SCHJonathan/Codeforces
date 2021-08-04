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
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vint> dp(m, vint(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) continue;
                int up = i-1 >= 0 ? dp[i-1][j] : 0;
                int left = j-1 >= 0 ? dp[i][j-1] : 0;
                int down = i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : 0;
                dp[i][j] = min(up, min(left, down)) + 1;
                res += dp[i][j];
            }
        }
        return res;
    }

    int countSquaresExceptOneEntry(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vint> dp(m+1, vint(n+1, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1] = matrix[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int width = 1; width <= min(m, n); width++) {
                    int sum = dp[i+1][j+1]-dp[i+1][j+1-width]-dp[i+1-width][j+1]+dp[i+1-width][j+1-width];
                    if (sum == width*width-1) res++;
                }
            }
        }

        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    int _ret_ans = 15;
    int _ret = _sol.countSquares(matrix);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    int _ret_ans = 7;
    int _ret = _sol.countSquares(matrix);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
