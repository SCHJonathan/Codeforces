// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
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
    bool isThree(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) res++;
            if (res == 2) return false;
        }
        return res == 1;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int n = 2;
    bool _ret_ans = false;
    bool _ret = _sol.isThree(n);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int n = 4;
    bool _ret_ans = true;
    bool _ret = _sol.isThree(n);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
