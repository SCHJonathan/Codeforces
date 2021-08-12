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
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> countMap;
        for (int& x : arr) countMap[x]++;
        vector<pair<int, int>> count(countMap.begin(), countMap.end());
        sort(count.begin(), count.end(), [](auto& x, auto& y) {
            if (x.first < 0 && y.first < 0) {
                return x.first > y.first;
            } else {
                return x.first < y.first;
            }
        });
        int n = count.size();
        for (int i = 0; i < n; i++) {
            auto [num, occurance] = count[i];
            if (num == 0) {
                if (occurance % 2 == 1) return false;
                else continue;
            }
            if (occurance == 0) continue;
            if (i == n-1 || count[i+1].first != num*2) return false;
            count[i].second = 0;
            count[i+1].second -= occurance;
            if (count[i+1].second < 0) return false;
        }

        return true;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> arr = {3, 1, 3, 6};
    bool _ret_ans = false;
    bool _ret = _sol.canReorderDoubled(arr);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> arr = {2, 1, 2, 6};
    bool _ret_ans = false;
    bool _ret = _sol.canReorderDoubled(arr);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> arr = {4, -2, 2, -4};
    bool _ret_ans = true;
    bool _ret = _sol.canReorderDoubled(arr);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<int> arr = {1, 2, 4, 16, 8, 4};
    bool _ret_ans = false;
    bool _ret = _sol.canReorderDoubled(arr);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
