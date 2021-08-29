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
    int numberOfUniqueGoodSubsequences(string binary) {
        int res = 0;
        int n = binary.size();
        bool zero = false; for (char& c : binary) zero = zero || (c == '0');
        vector<int> dp(n, 0);
        int zeroIdx = -1, oneIdx = -1;
        int start = 0; while (start < n && binary[start] == '0') start++;
        int count = 1;
        for (int i = start; i < n; i++) {
            if (i == start) {
                dp[i] = count;
            } else {
                count *= 2; count %= RANGE;
                int idx = binary[i] == '0' ? zeroIdx : oneIdx;
                int val = idx-1 < 0 ? 0 : dp[idx-1];
                debug(zeroIdx, oneIdx, idx, val);
                count = (count-val+RANGE)%RANGE;

                dp[i] = count;
            }
            if (binary[i] == '0') zeroIdx = i;
            if (binary[i] == '1') oneIdx = i;
            debug(i, dp[i]);
        }
        return (dp[n-1]+zero) % RANGE;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string binary = "001";
    int _ret_ans = 2;
    int _ret = _sol.numberOfUniqueGoodSubsequences(binary);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string binary = "11";
    int _ret_ans = 2;
    int _ret = _sol.numberOfUniqueGoodSubsequences(binary);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string binary = "101";
    int _ret_ans = 5;
    int _ret = _sol.numberOfUniqueGoodSubsequences(binary);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    string binary = "00011";
    int _ret_ans = 3;
    int _ret = _sol.numberOfUniqueGoodSubsequences(binary);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
