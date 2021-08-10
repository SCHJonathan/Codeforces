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
    string strWithout3a3b(int a, int b) {
        bool swapped = false;
        if (a < b) {
            swapped = true;
            swap(a, b);
        }
        // a >= b;
        string res = "";
        while (b > 0) {
            if (a > b) {
                res += "aa";
                res += "b";
                a -= 2, b--;
            } else {
                res += "ab";
                a--, b--;
            }
        }
        res = res + string(a, 'a');
        for (auto& c : res) if (swapped) c = 'a' + ((c-'a'+1)%2);
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int a = 1;
    int b = 2;
    string _ret_ans = "abb";
    string _ret = _sol.strWithout3a3b(a, b);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int a = 4;
    int b = 1;
    string _ret_ans = "aabaa";
    string _ret = _sol.strWithout3a3b(a, b);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
