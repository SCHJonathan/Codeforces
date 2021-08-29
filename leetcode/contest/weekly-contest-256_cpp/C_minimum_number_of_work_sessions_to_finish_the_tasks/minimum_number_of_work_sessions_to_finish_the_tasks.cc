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
    int memo(vector<vector<int>>& dp, vector<int>& tasks, int& n, int& sessionTime, int state, int time) {
        debug(state, time, n, sessionTime, dp[state][time]);
        if (dp[state][time] != -1) return dp[state][time];
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = 1 << i;
            if ((state & x)) continue;
            if (time + tasks[i] >= sessionTime) {
                int extraTime = time + tasks[i] == sessionTime ? 0 : tasks[i];
                // debug(state | x, extraTime);
                res = min(res, 1+memo(dp, tasks, n, sessionTime, state | x, extraTime));
            } else {
                res = min(res, memo(dp, tasks, n, sessionTime, state | x, time+tasks[i]));
            }
        }
        return dp[state][time] = res;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());
        int stateSize = (1<<n); int fill = stateSize-1;
        vector<vector<int>> dp(stateSize, vector<int>(sessionTime+1, -1));

        for (int i = 1; i <= sessionTime; i++) {
            dp[fill][i] = 1; 
        }
        dp[fill][0] = 0;
        return memo(dp, tasks, n, sessionTime, 0, 0);
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> tasks = {1, 2, 3};
    int sessionTime = 3;
    int _ret_ans = 2;
    int _ret = _sol.minSessions(tasks, sessionTime);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> tasks = {3, 1, 3, 1, 1};
    int sessionTime = 8;
    int _ret_ans = 2;
    int _ret = _sol.minSessions(tasks, sessionTime);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> tasks = {1, 2, 3, 4, 5};
    int sessionTime = 15;
    int _ret_ans = 1;
    int _ret = _sol.minSessions(tasks, sessionTime);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
