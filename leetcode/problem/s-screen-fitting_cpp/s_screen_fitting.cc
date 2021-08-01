// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
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
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int row = 0, start = 0;
        for (string& s : sentence) {

        }
        return 
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> sentence = {"hello", "world"};
    int rows = 2;
    int cols = 8;
    int _ret_ans = 1;
    int _ret = _sol.wordsTyping(sentence, rows, cols);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> sentence = {"a", "bcd", "e"};
    int rows = 3;
    int cols = 6;
    int _ret_ans = 2;
    int _ret = _sol.wordsTyping(sentence, rows, cols);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> sentence = {"i", "had", "apple", "pie"};
    int rows = 4;
    int cols = 5;
    int _ret_ans = 1;
    int _ret = _sol.wordsTyping(sentence, rows, cols);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
