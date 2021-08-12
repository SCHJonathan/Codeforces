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
    int minTransfers(vector<vector<int>>& transactions) {
        vint persons(21, 0);
        for (auto& t : transactions) {
            persons[t[0]] -= t[2];
            persons[t[1]] += t[2];
        }
        
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> transactions = {{0, 1, 10}, {2, 0, 5}};
    int _ret_ans = 2;
    int _ret = _sol.minTransfers(transactions);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> transactions = {{0, 1, 10}, {1, 0, 1}, {1, 2, 5}, {2, 0, 5}};
    int _ret_ans = 1;
    int _ret = _sol.minTransfers(transactions);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<vector<int>> transactions = {{0,1,2},{1,2,1},{1,3,1}};
    int _ret_ans = 2;
    int _ret = _sol.minTransfers(transactions);
    test("Example - 2", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
