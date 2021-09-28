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
    int binarySearch(vector<vector<int>>& properties, int attack, int defense) {
        int n = properties.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            // debug(properties, left, right, properties[mid], attack, defense, mid);
            if (properties[mid][0] <= attack && properties[mid][1] <= defense) {
                left = mid+1;
            } else {
                right = mid-1;
            }
            // debug(left, right);
        }
        return right;
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](auto& x, auto& y) {
            // return (x[0] < y[0] && x[1] < y[1]) || abs(x[0]-x[1]) < abs(y[0]-y[1]);
            // return (x[0] < y[0] && x[1] < y[1]);
            // return (x[0] < y[0] || x[1] < y[1]);
            return (x[0]*x[0]+x[1]*x[1] < y[0]*y[0]+y[1]*y[1]);
        });
        // sort(properties.begin(), properties.end());
        int res = 0, n = properties.size();
        debug(properties);
        int left = 0, right = n-1;
        for (int i = 0; i < n; i++) {
            debug(properties[i], properties[left]);
            while (properties[i][0] > properties[left][0] && 
                   properties[i][1] > properties[left][1]) {
                left++;
                res++;
            }
        }
        // while (left < right) {
        //     debug(left, right, properties[left], properties[right]);
        //     if (properties[left][0] < properties[right][0] && 
        //         properties[left][1] < properties[right][1]) {
        //         res ++;
        //         left++;
        //     } else {
        //         right--;
        //     }
        // }
        // int left = 0;
        // unordered_set<int> visited;
        // for (int i = 0; i < n; i++) {
        //     int idx = binarySearch(properties, properties[i][0]-1, properties[i][1]-1);
        //     debug(idx);
        //     res = max(res, idx+1);
        // }
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

void test_example_4(Solution &_sol) {
    vector<vector<int>> properties = {{1,1},{2,1},{2,2},{1,2},{2,3}};
    int _ret_ans = 2;
    int _ret = _sol.numberOfWeakCharacters(properties);
    test("Example - 4", _ret_ans, _ret);
}

void test_example_5(Solution &_sol) {
    vector<vector<int>> properties = {{7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}};
    int _ret_ans = 6;
    int _ret = _sol.numberOfWeakCharacters(properties);
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
