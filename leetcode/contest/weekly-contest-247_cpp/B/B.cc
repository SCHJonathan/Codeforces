// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int> 

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef JONATHAN_DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<deque<int>> flatten;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0, j = 0; i < m / 2 && j < n / 2; i++, j++) {
            deque<int> layer;
            int ii = i, jj = j;
            // debug(i, j, ii, jj);
            // right
            for (jj = j; jj < n-j-1; jj++) layer.push_back(grid[ii][jj]);
            // debug(i, j, ii, jj);
            // down
            for (ii = i; ii < m-i-1; ii++) layer.push_back(grid[ii][jj]);
            // debug(i, j, ii, jj);
            // left
            for (; jj >= j+1; jj--) layer.push_back(grid[ii][jj]);
            // debug(i, j, ii, jj);
            // up
            for (; ii >= i+1; ii--) layer.push_back(grid[ii][jj]);
            // debug(i, j, ii, jj);
            flatten.push_back(layer);
        }
            // debug(flatten);
        
        for (auto & layer : flatten) {
            int size = layer.size();
            int move = k % size;
            while (move--) {
                layer.push_back(layer.front());
                layer.pop_front();
            }
        }
        debug(flatten);
        int idx = 0;
        for (int i = 0, j = 0; i < m / 2 && j < n / 2; i++, j++) {
            deque<int>& layer = flatten[idx];
            int ii = i, jj = j;
            // right
            for (jj = j; jj < n-j-1; jj++) {
                grid[ii][jj] = layer.front();
                layer.pop_front();
            }
            debug(i, j, ii, jj);
            // down
            for (ii = i; ii < m-i-1; ii++) {
                grid[ii][jj] = layer.front();
                layer.pop_front();
            }
            debug(i, j, ii, jj);
            // left
            for (; jj >= j+1; jj--) {
                grid[ii][jj] = layer.front();
                layer.pop_front();
            }
            debug(i, j, ii, jj);
            // up
            for (; ii >= i+1; ii--) {
                grid[ii][jj] = layer.front();
                layer.pop_front();
            }
            debug(i, j, ii, jj);
            idx++;
        }
        debug(grid);
        vector<vector<int>> result = grid;
        debug("here");
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> grid = {{40, 10}, {30, 20}};
    int k = 1;
    vector<vector<int>> _ret_ans = {{10, 20}, {40, 30}};
    vector<vector<int>> _ret = _sol.rotateGrid(grid, k);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int k = 2;
    vector<vector<int>> _ret_ans = {{3, 4, 8, 12}, {2, 11, 10, 16}, {1, 7, 6, 15}, {5, 9, 13, 14}};
    vector<vector<int>> _ret = _sol.rotateGrid(grid, k);
    debug("here");
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
