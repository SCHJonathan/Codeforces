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
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;
    int _ret_ans = 6;
    int _ret = _sol.minHeightShelves(books, shelfWidth);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> books = {{1, 3}, {2, 4}, {3, 2}};
    int shelfWidth = 6;
    int _ret_ans = 4;
    int _ret = _sol.minHeightShelves(books, shelfWidth);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
