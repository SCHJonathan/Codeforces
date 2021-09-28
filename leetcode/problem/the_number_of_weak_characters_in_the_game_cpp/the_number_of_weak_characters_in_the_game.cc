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
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int end = 0, n = properties.size(), res = 0;
        sort(properties.begin(), properties.end(), [&](auto&x, auto&y) {
            return x[0] < y[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        deque<int> buffer; 
        for (int i = 0; i < n; i++) {
            if (properties[i][0] != properties[end][0]) {
                end = i;
                while (!buffer.empty()) {
                    pq.push(buffer.back());
                    buffer.pop_back();
                }
            }
            while (!pq.empty() && pq.top() < properties[i][1]) {
                pq.pop();
                res++;
            }
            buffer.push_back(properties[i][1]);
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> properties = {{5, 5}, {6, 3}, {3, 6}};
    int _ret_ans = 0;
    int _ret = _sol.numberOfWeakCharacters(properties);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> properties = {{2, 2}, {3, 3}};
    int _ret_ans = 1;
    int _ret = _sol.numberOfWeakCharacters(properties);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> properties = {{1, 5}, {10, 4}, {4, 3}};
    int _ret_ans = 1;
    int _ret = _sol.numberOfWeakCharacters(properties);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    vector<vector<int>> properties = {{1,1},{2,1},{2,2},{1,2}};
    int _ret_ans = 1;
    int _ret = _sol.numberOfWeakCharacters(properties);
    test("Example - 3", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
