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
    bool isSubstr(string p, string& word) {
        if (p.size() > word.size()) return false;
        if (p.size() == word.size()) return p == word;
        int n = word.size();
        for (int i = 0; i < n-p.size()+1; i++) {
            string curr = word.substr(i, p.size());
            if (curr == p) return true;
        }
        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (auto& p : patterns) {
            if (isSubstr(p, word)) res++;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";
    int _ret_ans = 3;
    int _ret = _sol.numOfStrings(patterns, word);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> patterns = {"a", "b", "c"};
    string word = "aaaaabbbbb";
    int _ret_ans = 2;
    int _ret = _sol.numOfStrings(patterns, word);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> patterns = {"a", "a", "a"};
    string word = "ab";
    int _ret_ans = 3;
    int _ret = _sol.numOfStrings(patterns, word);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
