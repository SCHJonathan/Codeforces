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
    int minTimeToType(string word) {
        char start = 'a'; int res = 0;
        for (char& c : word) {
            res += min((c-start+26)%26, (start-c+26)%26)+1;
            start = c;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string word = "abc";
    int _ret_ans = 5;
    int _ret = _sol.minTimeToType(word);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string word = "bza";
    int _ret_ans = 7;
    int _ret = _sol.minTimeToType(word);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string word = "zjpc";
    int _ret_ans = 34;
    int _ret = _sol.minTimeToType(word);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
