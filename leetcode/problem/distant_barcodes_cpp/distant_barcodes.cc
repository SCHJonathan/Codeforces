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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int& x : barcodes) count[x]++;

        auto comp = [&](auto& x, auto& y) {return x.second < y.second; };
        priority_queue<pint, vector<pint>, decltype(comp)> pq(comp);

        vector<int> res;
        for (auto& p : count) pq.push(p);

        int prev = -1;
        while (pq.size()) {
            vector<pint> buffer;
            while (pq.top().first == prev) {
                buffer.push_back(pq.top());
                pq.pop();
            }
            auto curr = pq.top(); pq.pop();
            res.push_back(curr.first);
            curr.second--;
            prev = curr.first;
            if (curr.second > 0) pq.push(curr);
            if (buffer.size()) pq.push(buffer.back()); 
        }

        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> barcodes = {1, 1, 1, 2, 2, 2};
    vector<int> _ret_ans = {2, 1, 2, 1, 2, 1};
    vector<int> _ret = _sol.rearrangeBarcodes(barcodes);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> barcodes = {1, 1, 1, 1, 2, 2, 3, 3};
    vector<int> _ret_ans = {1, 3, 1, 3, 1, 2, 1, 2};
    vector<int> _ret = _sol.rearrangeBarcodes(barcodes);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
