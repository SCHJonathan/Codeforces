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
    int leastInterval(vector<char>& tasks, int n) {
        if (!n) return tasks.size();
        unordered_map<char, int> count;
        for (auto& c : tasks) count[c]++;
        auto comp = [&](auto& x, auto& y) { return x.second < y.second || (x.second == y.second && x.first < y.first);};
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        for (auto & p : count) pq.push(p);

        int res = 0, size = 0;
        while (!pq.empty()) {
            vector<pair<char,int>> buffer;
            int pqsize = pq.size();
            for (int i = 0; i < min(pqsize, n+1); i++) {
                buffer.push_back(pq.top()); pq.pop();
            }
            size = buffer.size();
            if (pqsize <= n+1) {
                int prev = 0;
                for (int i = size-1; i >= 0; i--) {
                    res += (n+1)*(buffer[i].second-prev);
                    prev = buffer[i].second;
                }
                int lastRound = 1;
                for (int i = 1; i < size; i++) {
                    if (buffer[i].second == buffer[i-1].second) {
                        lastRound++;
                    } else {
                        break;
                    }
                }
                return res - n - 1 + lastRound;
            } else {
                for (auto& p : buffer) {
                    p.second--;
                    if (p.second > 0) pq.push(p);
                }
                res += n+1;    
            }
        }
        return -1;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int _ret_ans = 8;
    int _ret = _sol.leastInterval(tasks, n);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 0;
    int _ret_ans = 6;
    int _ret = _sol.leastInterval(tasks, n);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n = 2;
    int _ret_ans = 16;
    int _ret = _sol.leastInterval(tasks, n);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
