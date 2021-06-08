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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;


class Solution {
public:
    bool valid(pint& up, pint& left, pint& down, pint& right, int m, int n) {
        vector<pint> buffer;
        buffer.push_back(up);
        buffer.push_back(left);
        buffer.push_back(right);
        buffer.push_back(down);
        for (auto& p : buffer) {
            if (p.first >= m || p.first < 0 || p.second >= n || p.second < 0)
                return false;
        }
        return true;
    }

    ull traverse(pint& start, pint& end, vector<vector<int>>& grid, int xx, int yy) {
        ull res = 0;
        int x = start.first, y = start.second;
        while (1) {
            res += grid[x][y];
            if (x == end.first && y == end.second) break;
            x += xx, y += yy;
        }
        return res;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        debug(grid);
        set<ull> best;
        // debug(m, n);
        for (int size = 1; size <= min(m, n); size++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    pair<int, int> up = {i, j}, 
                                   down = {i+2*(size-1), j}, 
                                   left = {i+size-1, j-(size-1)},
                                   right = {i+size-1, j+size-1};
                    if (!valid(up, down, left, right, m, n)) {
                        debug(size, up, left, down, right);
                        continue;
                    }
                    ull sum = 0;
                    // up to left
                    sum += traverse(up, left, grid, 1, -1);
                    // debug("1", sum);
                    // up to right
                    sum += traverse(up, right, grid, 1, 1);
                    // debug("2", sum);
                    // left to down
                    sum += traverse(left, down, grid, 1, 1);
                    // debug("3", sum);
                    // right to down
                    sum += traverse(right, down, grid, 1, -1);
                    if (size > 1) {
                        sum -= grid[i][j];
                        sum -= grid[down.first][down.second];
                        sum -= grid[left.first][left.second];
                        sum -= grid[right.first][right.second];    
                    } else {
                        sum = grid[i][j];
                    }

                    debug("4", sum);

                    best.insert(sum);
                }
            }
        }
        vector<int> res; 
        for (auto it = best.rbegin(); it != best.rend(); it++) {
            if (res.size() == 3) break;
            res.push_back(*it);
        }
        // debug(res);
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> grid = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    vector<int> _ret_ans = {228, 216, 211};
    vector<int> _ret = _sol.getBiggestThree(grid);
    // cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> _ret_ans = {20, 9, 8};
    vector<int> _ret = _sol.getBiggestThree(grid);
    // cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> grid = {{7, 7, 7}};
    vector<int> _ret_ans = {7};
    vector<int> _ret = _sol.getBiggestThree(grid);
    // cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}

void test_example_3(Solution &_sol) {
    // vector<vector<int>> grid = {{20,17,9,13,5,2,9,1,5},{14,9,9,9,16,18,3,4,12},{18,15,10,20,19,20,15,12,11},{19,16,19,18,8,13,15,14,11},{4,19,5,2,19,17,7,2,2}};
    vector<vector<int>> grid = {{7,7,7}};
    vector<int> _ret_ans = {7};
    vector<int> _ret = _sol.getBiggestThree(grid);
    // cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    test_example_3(_sol);
    return 0;
}
