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
    int maxEventsStrict(vector<vector<int>>& events) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int i = 0, res = 0, d = 0, n = events.size();
        while (pq.size() > 0 || i < n) {
            if (pq.size() == 0)
                d = events[i][0];
            while (i < n && events[i][0] == d)
                pq.push(events[i++][1]);
            pq.pop();
            ++res, ++d;
            while (pq.size() > 0 && pq.top() < d)
                pq.pop();

        }
        return res;
    }

    int maxEvents(vector<vector<int>>& events) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int maxday = 0, result = 0, idx = 0, n = events.size();
        for (auto& x : events) maxday = max(maxday, x[1]);
        for (int i = 1; i <= maxday; i++) {
            while (idx < n && events[idx][0] <= i) pq.push(events[idx++][1]);
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop(); 
                result++;
            }
        }
        return result;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    int _ret_ans = 3;
    int _ret = _sol.maxEvents(events);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    int _ret_ans = 4;
    int _ret = _sol.maxEvents(events);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> events = {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
    int _ret_ans = 4;
    int _ret = _sol.maxEvents(events);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<vector<int>> events = {{1, 100000}};
    int _ret_ans = 1;
    int _ret = _sol.maxEvents(events);
    test("Example - 3", _ret_ans, _ret);
}


void test_example_4(Solution &_sol) {
    vector<vector<int>> events = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}};
    int _ret_ans = 7;
    int _ret = _sol.maxEvents(events);
    test("Example - 4", _ret_ans, _ret);
}

void test_example_5(Solution &_sol) {
    vector<vector<int>> events = {{1,2},{1,2},{3,3},{1,5},{1,5}};
    int _ret_ans = 5;
    int _ret = _sol.maxEvents(events);
    test("Example - 5", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
    test_example_4(_sol);
    test_example_5(_sol);
}
