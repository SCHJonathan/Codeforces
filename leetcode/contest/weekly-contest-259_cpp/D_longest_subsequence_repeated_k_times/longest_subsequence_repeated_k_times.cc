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
    string longestSubsequenceRepeatedK(string s, int k) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "letsleetcode";
    int k = 2;
    string _ret_ans = "let";
    string _ret = _sol.longestSubsequenceRepeatedK(s, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "bb";
    int k = 2;
    string _ret_ans = "b";
    string _ret = _sol.longestSubsequenceRepeatedK(s, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "ab";
    int k = 2;
    string _ret_ans = "";
    string _ret = _sol.longestSubsequenceRepeatedK(s, k);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    string s = "bbabbabbbbabaababab";
    int k = 3;
    string _ret_ans = "bbbb";
    string _ret = _sol.longestSubsequenceRepeatedK(s, k);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
