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
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> candiesCount = {7, 4, 5, 3, 8};
    vector<vector<int>> queries = {{0, 2, 2}, {4, 2, 4}, {2, 13, 1000000000}};
    vector<bool> _ret_ans = {true, false, true};
    vector<bool> _ret = _sol.canEat(candiesCount, queries);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> candiesCount = {5, 2, 6, 4, 1};
    vector<vector<int>> queries = {{3, 1, 2}, {4, 10, 3}, {3, 10, 100}, {4, 100, 30}, {1, 3, 1}};
    vector<bool> _ret_ans = {false, true, true, false, false};
    vector<bool> _ret = _sol.canEat(candiesCount, queries);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
