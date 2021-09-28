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
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 1, 0}};
    vector<vector<int>> hits = {{1, 0}};
    vector<int> _ret_ans = {2};
    vector<int> _ret = _sol.hitBricks(grid, hits);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 0, 0}};
    vector<vector<int>> hits = {{1, 1}, {1, 0}};
    vector<int> _ret_ans = {0, 0};
    vector<int> _ret = _sol.hitBricks(grid, hits);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
