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
    string reversePrefix(string word, char ch) {
        int idx = 0;
        while (idx < word.size() && word[idx] != ch) idx++;
        if (idx == word.size()) return word;
        reverse(word.begin(), word.begin()+idx+1);
        return word;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string word = "abcdefd";
    char ch = 'd';
    string _ret_ans = "dcbaefd";
    string _ret = _sol.reversePrefix(word, ch);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string word = "xyxzxe";
    char ch = 'z';
    string _ret_ans = "zxyxxe";
    string _ret = _sol.reversePrefix(word, ch);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string word = "abcd";
    char ch = 'z';
    string _ret_ans = "abcd";
    string _ret = _sol.reversePrefix(word, ch);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
