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
    bool exist(unordered_map<int, unordered_map<int, int>>& dp, int x, int y) {
        return dp.find(x) != dp.end() && dp[x].find(y) != dp[x].end();
    }

    int memo(unordered_map<int, unordered_map<int, int>>& dp, 
             vector<vector<int>>& mat, 
             int target,
             int row,
             vector<int>& rowSum) {
        int m = mat.size(), n = mat[0].size();
        if (row == m) return abs(target);
        if (target <= 0) return abs(target)+rowSum[row];
        if (exist(dp, target, row)) {
            return dp[target][row];
        }
        auto& arr = mat[row];
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i-1]) continue;
            int ret = abs(memo(dp, mat, target-arr[i], row+1, rowSum));
            res = min(res, ret);
            if (ret == 0) return 0;
            if (target <= arr[i]) break; 
        }
        return dp[target][row] = res;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        for (auto& v : mat) {
            sort(v.begin(), v.end());
        }
        unordered_map<int, unordered_map<int, int>> dp;
        vector<int> rowSum(m+1, 0);
        for (int i = m-1; i >= 0; i--) {
            rowSum[i] = rowSum[i+1]+mat[i][0];
        }
        return memo(dp, mat, target, 0, rowSum);
        // int size = m*70+1;
        // vector<vector<int>> dp(size, vector<int>(m+1, 0));
        // for (int i = m-1; i >= 0; i--) {
            // for (int j = )
        // }
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target = 13;
    int _ret_ans = 0;
    int _ret = _sol.minimizeTheDifference(mat, target);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> mat = {{1}, {2}, {3}};
    int target = 100;
    int _ret_ans = 94;
    int _ret = _sol.minimizeTheDifference(mat, target);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> mat = {{1, 2, 9, 8, 7}};
    int target = 6;
    int _ret_ans = 1;
    int _ret = _sol.minimizeTheDifference(mat, target);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
