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
    string rearrangeString(string s, int k) {
        string res = ""; if (k == 0) return s;
        unordered_map<char, int> count;
        for (char& c : s) count[c]++;
        auto comp = [&](auto& x, auto& y) { return x.second < y.second || (x.second == y.second && x.first < y.first); };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        for (auto& p : count) pq.push(p);

        while (pq.size() >= k) {
            vector<pair<char, int>> buffer;
            for (int i = 0; i < k; i++) {
                buffer.push_back(pq.top()); pq.pop();
            }
            for (auto& p : buffer) {
                res += p.first;
                p.second--;
                if (p.second > 0) pq.push(p);
            }
        }

        while (!pq.empty()) {
            if (pq.top().second > 1) return "";
            res += pq.top().first; pq.pop();
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "aabbcc";
    int k = 3;
    string _ret_ans = "abcabc";
    string _ret = _sol.rearrangeString(s, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "aaabc";
    int k = 3;
    string _ret_ans = "";
    string _ret = _sol.rearrangeString(s, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "aaadbbcc";
    int k = 2;
    string _ret_ans = "abacabcd";
    string _ret = _sol.rearrangeString(s, k);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
