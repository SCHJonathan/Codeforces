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
    int wordsTypingRingBuffer(vector<string>& sentence, int rows, int cols) {
        if (sentence[0].size() > cols) return 0;

        int n = sentence.size();
        int size = 0, idx = 0, iteration = 0;

        vector<pair<int, int>> next;
        deque<pair<int, int>> ringBuffer; 
        
        for (int i = 0; i < n; i++) {
            while (size+sentence[idx].size()+(ringBuffer.size() > 0) <= cols) {
                size += (ringBuffer.size() > 0)+sentence[idx].size();
                ringBuffer.push_back({idx, sentence[idx].size()});
                idx = (idx+1)%n;
                if (idx == 0) iteration++;
            }
            next.push_back({ringBuffer.back().first, iteration});
            iteration -= ringBuffer.front().first == n-1;
            size -= (ringBuffer.size() > 1) + ringBuffer.front().second;
            ringBuffer.pop_front();
        }
        
        int res = 0, curr = 0;
        for (int i = 0; i < rows; i++) {
            auto[start, iteration] = next[curr];
            res += iteration;
            curr = (start+1)%n;
        }
        return res;
    }

    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string formatted = "";
        for (string& s : sentence) formatted += " " + s;
        int n = formatted.size();

        int start = 1;
        for (int i = 0; i < rows; i++) {
            start += cols;
            if (formatted[start % n] == ' ') {
                start++;
            } else {
                while (start > 0 && formatted[(start-1)%n] != ' ') start--;
            }
        }
        return start / n;
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

void test_example_3(Solution &_sol) {
    vector<string> sentence = {"f","p","a"};
    int rows = 8;
    int cols = 7;
    int _ret_ans = 10;
    int _ret = _sol.wordsTyping(sentence, rows, cols);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
