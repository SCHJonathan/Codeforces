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
    int jobSchedulingDP(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        vector<int> sortedEndTime;
        for (auto [end, x, y] : jobs) sortedEndTime.push_back(end);
        
        vector<int> dp(n+1, 0); 
        for (int i = 1; i <= n; i++) {
            auto [end, start, gain] = jobs[i-1]; 
            auto it = upper_bound(sortedEndTime.begin(), sortedEndTime.end(), start);
            int previousIndex = -1;
            if (it != sortedEndTime.begin() && it != sortedEndTime.end()) previousIndex = distance(sortedEndTime.begin(), prev(it));
            int previous = previousIndex != -1 ? dp[previousIndex+1] : 0;
            dp[i] = max(dp[i-1], previous+gain);
        }
        
        return dp[n];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        int res = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        for (auto& job : jobs) {
            auto [start, end, gain] = job;
            while (!pq.empty() && pq.top()[0] <= start) {
                res = max(res, pq.top()[1]);
                pq.pop();
            }
            pq.push({end, res+gain});
        }
        while (!pq.empty()) {
            res = max(res, pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    int _ret_ans = 120;
    int _ret = _sol.jobScheduling(startTime, endTime, profit);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> startTime = {1, 2, 3, 4, 6};
    vector<int> endTime = {3, 5, 10, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};
    int _ret_ans = 150;
    int _ret = _sol.jobScheduling(startTime, endTime, profit);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> startTime = {1, 1, 1};
    vector<int> endTime = {2, 3, 4};
    vector<int> profit = {5, 6, 4};
    int _ret_ans = 6;
    int _ret = _sol.jobScheduling(startTime, endTime, profit);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
