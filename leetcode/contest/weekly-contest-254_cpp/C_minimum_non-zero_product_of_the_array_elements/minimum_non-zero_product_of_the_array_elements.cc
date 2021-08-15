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
    int minNonZeroProduct(int p) {
        ull curr = 1, parts = 1;
        vector<int> powArr(p+1, 0); powArr[0] = 1;

        for (int i = 1; i <= p; i++) powArr[i] = (powArr[i-1]*2)%RANGE;
        
        ull res = 0;
        ull base = ((powArr[p-1]-1+RANGE)%RANGE)*2%RANGE;
        parts = (parts << p) - 1;
        ull power = (parts/2)%RANGE;
        // unordered_map<ull, ull> dp; dp[0] = 1; dp[1] = base; 
        // for (int i = 2; i <= power; i++) {
            // dp[i] = dp[i/2]*dp[i-i/2]%RANGE;
        // }
        curr = 1;
        vector<ull> dp(63, 0); dp[0] = base;
        for (int i = 1; i < 63; i++) dp[i] = dp[i-1]*dp[i-1]%RANGE;
        int idx = 0;
        while (power) {
            if (power & 1) {
                curr = curr*dp[idx]%RANGE;
            }
            power >>= 1;
            idx++;
        }
        // curr = dp[power];
        ull largest = (powArr[p]-1+RANGE)%RANGE;
        curr *= largest;
        curr %= RANGE;
        // curr = ((((pow[i]-1+RANGE)%RANGE)*2%RANGE)*(parts/2)%RANGE)*(pow[i]-1+RANGE)%RANGE;
        debug(base, power, largest);
        return curr;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int p = 1;
    int _ret_ans = 1;
    int _ret = _sol.minNonZeroProduct(p);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int p = 2;
    int _ret_ans = 6;
    int _ret = _sol.minNonZeroProduct(p);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    int p = 31;
    int _ret_ans = 1512;
    int _ret = _sol.minNonZeroProduct(p);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
