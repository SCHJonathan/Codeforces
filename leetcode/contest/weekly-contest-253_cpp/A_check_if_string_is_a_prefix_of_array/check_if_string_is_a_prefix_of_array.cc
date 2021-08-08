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
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size();
        string curr = "";
        for (int i = 0; i < words.size() && curr.size() < s.size(); i++) {
            curr += words[i];
        }
        return curr == s;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "iloveleetcode";
    vector<string> words = {"i", "love", "leetcode", "apples"};
    bool _ret_ans = true;
    bool _ret = _sol.isPrefixString(s, words);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "iloveleetcode";
    vector<string> words = {"apples", "i", "love", "leetcode"};
    bool _ret_ans = false;
    bool _ret = _sol.isPrefixString(s, words);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
