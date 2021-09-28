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
    int scoreOfStudents(string s, vector<int>& answers) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "7+3*1*2";
    vector<int> answers = {20, 13, 42};
    int _ret_ans = 7;
    int _ret = _sol.scoreOfStudents(s, answers);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "3+5*2";
    vector<int> answers = {13, 0, 10, 13, 13, 16, 16};
    int _ret_ans = 19;
    int _ret = _sol.scoreOfStudents(s, answers);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "6+0*1";
    vector<int> answers = {12, 9, 6, 4, 8, 6};
    int _ret_ans = 10;
    int _ret = _sol.scoreOfStudents(s, answers);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
