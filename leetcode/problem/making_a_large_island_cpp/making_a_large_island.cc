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
    int find(int* parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    int unionSet(int* parent, int* size, int x, int y) {
        x = find(parent, x), y = find(parent, y);
        if (x == y) return size[x];
        int res = size[x] + size[y];
        parent[x] = y;
        return res;
    }

    vector<int> xdir = {0, -1, 0, 1};
    vector<int> ydir = {-1, 0, 1, 0};


    int largestIsland(vector<vector<int>>& grid) {
        debug(grid);
        int n = grid.size();
        int size[n*n], parent[n*n];
        memset(size, 0, sizeof(size));
        for (int i = 0; i < n*n; i++) parent[i] = i;
            
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                size[i*n+j] = 1;
                for (int k = 0; k < 2; k++) {
                    int ii = i+xdir[k], jj = j+ydir[k];
                    if (ii < 0 || ii >= n || jj < 0 || jj >= n || !grid[ii][jj]) continue;
                    size[ii*n+jj] = size[i*n+j] = unionSet(parent, size, ii*n+jj, i*n+j);
                }
                res = max(res, size[i*n+j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                int curr = 1; set<int> distinct;
                for (int k = 0; k < 4; k++) {
                    int ii = i+xdir[k], jj = j+ydir[k];
                    if (ii < 0 || ii >= n || jj < 0 || jj >= n || !grid[ii][jj]) continue;
                    int y = find(parent, ii*n+jj);
                    distinct.insert(y);
                }
                for (auto& x : distinct) {
                    debug(size[x]);
                    curr += size[x];
                }
                debug(i, j, distinct);
                res = max(res, curr);
            }
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    int _ret_ans = 3;
    int _ret = _sol.largestIsland(grid);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> grid = {{1, 1}, {1, 0}};
    int _ret_ans = 4;
    int _ret = _sol.largestIsland(grid);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> grid = {{1, 1}, {1, 1}};
    int _ret_ans = 4;
    int _ret = _sol.largestIsland(grid);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
