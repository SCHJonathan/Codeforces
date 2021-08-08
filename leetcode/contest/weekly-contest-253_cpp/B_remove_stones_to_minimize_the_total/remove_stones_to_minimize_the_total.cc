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
    int minStoneSum(vector<int>& piles, int k) {

        priority_queue<int> pq;
        for (auto& x : piles) pq.push(x);
        while (k) {
            int curr = pq.top(); pq.pop();
            curr = curr - curr/2;
            if (curr > 0) pq.push(curr);
            k--;
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top(); pq.pop();
        } 
        return sum;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> piles = {5, 4, 9};
    int k = 2;
    int _ret_ans = 12;
    int _ret = _sol.minStoneSum(piles, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> piles = {4, 3, 6, 7};
    int k = 3;
    int _ret_ans = 12;
    int _ret = _sol.minStoneSum(piles, k);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
