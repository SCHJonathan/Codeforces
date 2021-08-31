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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        bool done = false;
        while (!done) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < )
            }
        }
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> matrix = {{1, -1}, {-1, 1}};
    long long _ret_ans = 4;
    long long _ret = _sol.maxMatrixSum(matrix);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    long long _ret_ans = 16;
    long long _ret = _sol.maxMatrixSum(matrix);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
