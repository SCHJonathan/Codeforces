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
    pair<int, int> largestAndOther(priority_queue<pair<int, char>>& pq) {
        pair<int, int> res;
        vector<pair<int, char>> buffer;
        int idx = 0;
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            if (idx == 0) res.first = curr.first;
            else res.second += curr.first;
            buffer.push_back(curr);
            idx++;
        }
        for (auto& p : buffer) pq.push(p);
        return res;
    }

    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'}); 
        if (b > 0) pq.push({b, 'b'}); 
        if (c > 0) pq.push({c, 'c'});

        while (pq.size() >= 2) {

            auto [largest, others] = largestAndOther(pq);
            auto largestPair = pq.top(); pq.pop();
            auto secondLargestPair = pq.top(); pq.pop();
            int amount = largest > others ? 2 : 1;
            res += string(amount, largestPair.second) + string(1, secondLargestPair.second);
            largestPair.first -= amount; secondLargestPair.first--; 
            if (largestPair.first > 0) pq.push(largestPair);
            if (secondLargestPair.first > 0) pq.push(secondLargestPair);
        }

        if (!pq.empty()) {
            auto leftover = pq.top(); pq.pop();
            res += string(min(2, leftover.first), leftover.second);
        }

        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int a = 1;
    int b = 1;
    int c = 7;
    string _ret_ans = "ccaccbcc";
    string _ret = _sol.longestDiverseString(a, b, c);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int a = 2;
    int b = 2;
    int c = 1;
    string _ret_ans = "aabbc";
    string _ret = _sol.longestDiverseString(a, b, c);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    int a = 7;
    int b = 1;
    int c = 0;
    string _ret_ans = "aabaa";
    string _ret = _sol.longestDiverseString(a, b, c);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
