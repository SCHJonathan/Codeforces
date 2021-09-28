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
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& s : operations) {
            if (s == "X++" || s == "++X") {
                ++x;
            } else {
                --x;
            }
        }
        return x;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> operations = {"--X", "X++", "X++"};
    int _ret_ans = 1;
    int _ret = _sol.finalValueAfterOperations(operations);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> operations = {"++X", "++X", "X++"};
    int _ret_ans = 3;
    int _ret = _sol.finalValueAfterOperations(operations);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> operations = {"X++", "++X", "--X", "X--"};
    int _ret_ans = 0;
    int _ret = _sol.finalValueAfterOperations(operations);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
