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
    string makeFancyString(string s) {
        int left = 0, right = 0, n = s.size();
        string res = ""; int count = 1;
        for (int i = 0; i < n; i++) {
            if (res.size() && res[res.size()-1] == s[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count == 3) {
                count--;
                continue;
            }
            res += s[i];
        }
        return res;
        // while (right < n) {
        //     while (right < n && right > 0 && s[right] == s[right-1]) {
        //         right++;
        //     }
        //     if (right-left > 3) return s.substr(0, left) + s.substr(left+1);
        //     if (right == left) right++;
        //     left = right;
        // }
        // return s;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "leeetcode";
    string _ret_ans = "leetcode";
    string _ret = _sol.makeFancyString(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "aaabaaaa";
    string _ret_ans = "aabaa";
    string _ret = _sol.makeFancyString(s);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "aab";
    string _ret_ans = "aab";
    string _ret = _sol.makeFancyString(s);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
