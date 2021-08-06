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
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        for (auto& c : s) count[c]++;
        auto comp = [&](auto& x, auto& y) { return x.second < y.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        for (auto& p : count) pq.push(p);

        if (pq.top().second > n/2+(n%2)) return "";
        char prev = '#';
        string result = "";
        while (!pq.empty()) {
            vector<pair<char, int>> buffer;
            if (pq.top().first == prev) {
                buffer.push_back(pq.top());
                pq.pop();
            }
            if (pq.empty()) {
                assert(false);
                return "";
            }
            auto curr = pq.top(); pq.pop();
            prev = curr.first;
            result += curr.first; curr.second--;
            if (curr.second > 0) pq.push(curr);
            if (buffer.size()) pq.push(buffer[0]);
        }

        return result;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "aab";
    string _ret_ans = "aba";
    string _ret = _sol.reorganizeString(s);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "aaab";
    string _ret_ans = "";
    string _ret = _sol.reorganizeString(s);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
