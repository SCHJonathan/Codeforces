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
    string minWindow(string s, string t) {
        int charInS = 0, charInT = 0;
        int countS[26]; memset(countS, 0, sizeof(countS));
        int countT[26]; memset(countS, 0, sizeof(countS));
        for (char& c : s) {
            countS[c-'a']++;
            if (countS[c-'a'] == 1) charInS++;
        }
        for (char& c : t) {
            countT[c-'a']++;
            if (countT[c-'a'] == 1) charInT++;
        }


        int left = 0, right = 0, result = 0;
        while

    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string _ret_ans = "BANC";
    string _ret = _sol.minWindow(s, t);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "a";
    string t = "a";
    string _ret_ans = "a";
    string _ret = _sol.minWindow(s, t);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "a";
    string t = "aa";
    string _ret_ans = "";
    string _ret = _sol.minWindow(s, t);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
