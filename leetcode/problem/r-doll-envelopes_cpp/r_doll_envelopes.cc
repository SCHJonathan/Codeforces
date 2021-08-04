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
    int maxEnvelopes(vector<vector<int>>& arr) {
        vector<int> dp;
        sort(arr.begin(), arr.end(), [](auto& x, auto& y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
        });
        for (auto& e : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if (it == dp.end()) {
                dp.push_back(e[1]);
            } else if (e[1] < *it) {
                *it = e[1];
            }
        }
        return dp.size();
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    int _ret_ans = 3;
    int _ret = _sol.maxEnvelopes(envelopes);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> envelopes = {{1, 1}, {1, 1}, {1, 1}};
    int _ret_ans = 1;
    int _ret = _sol.maxEnvelopes(envelopes);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
