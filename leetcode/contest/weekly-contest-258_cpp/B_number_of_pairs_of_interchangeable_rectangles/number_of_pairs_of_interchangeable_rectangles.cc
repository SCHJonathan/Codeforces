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
    pair<int, int> simplify(vector<int>& v) {
        pair<int, int> result = {v[0], v[1]};
        int minval = min(v[0], v[1]);
        for (int i = 2; 2*i <= minval;) {
            while (result.first % i == 0 && result.second % i == 0) {
                result.first /= i;
                result.second /= i;
                // debug(result, i);
            }
            minval = min(result.first, result.second);
            if (i == 2) i++;
            else i += 2;
        }
        if (result.first % result.second == 0) {
            result.first /= result.second;
            result.second = 1;
        }
        if (result.second % result.first == 0) {
            result.second /= result.first;
            result.first = 1;
        }
        debug(v, result);
        return result;
    }

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        ll result = 0;
        // multiset<pint> ratios;
        unordered_map<double, int> ratios;
        for (auto & v : rectangles) {
            // auto p = simplify(v);
            double raito = (double)v[0]/(double)v[1];
            result += ratios[raito];
            ratios[raito]++;
        } 
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    long long _ret_ans = 6;
    long long _ret = _sol.interchangeableRectangles(rectangles);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> rectangles = {{4, 5}, {7, 8}};
    long long _ret_ans = 0;
    long long _ret = _sol.interchangeableRectangles(rectangles);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<vector<int>> rectangles = {{2,3},{6,9},{4,5},{5,2},{9,7},{1,8},{5,8},{7,9}};
    long long _ret_ans = 1;
    long long _ret = _sol.interchangeableRectangles(rectangles);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
