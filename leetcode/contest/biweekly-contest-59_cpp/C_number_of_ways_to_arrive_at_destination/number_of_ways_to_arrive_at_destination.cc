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
    int countPaths(int n, vector<vector<int>>& roads) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int _ret_ans = 4;
    int _ret = _sol.countPaths(n, roads);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int n = 2;
    vector<vector<int>> roads = {{1, 0, 10}};
    int _ret_ans = 1;
    int _ret = _sol.countPaths(n, roads);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
