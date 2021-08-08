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
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // int n = obstacles.size();
        // deque<int> st;
        // vector<int> res(n, 0);
        // for (int i = 0; i < n; i++) {
        //     int x = obstacles[i];
        //     while (st.size() && st.back() > x) {
        //         st.pop_back();
        //     }
        //     st.push_back(x);
        //     res[i] = st.size();
        // }
        int n = obstacles.size();
        debug(obstacles);
        vector<int> dp;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int x = obstacles[i];
            auto it = upper_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) {
                dp.push_back(x);
                res[i] = dp.size();
            } else if (x <= *it) {
                debug(*it);
                *it = x;
                res[i] = distance(dp.begin(), it)+1;
            }
            debug(dp, x);
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> obstacles = {1, 2, 3, 2};
    vector<int> _ret_ans = {1, 2, 3, 3};
    vector<int> _ret = _sol.longestObstacleCourseAtEachPosition(obstacles);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> obstacles = {2, 2, 1};
    vector<int> _ret_ans = {1, 2, 1};
    vector<int> _ret = _sol.longestObstacleCourseAtEachPosition(obstacles);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> obstacles = {3, 1, 5, 6, 4, 2};
    vector<int> _ret_ans = {1, 1, 2, 3, 2, 2};
    vector<int> _ret = _sol.longestObstacleCourseAtEachPosition(obstacles);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
