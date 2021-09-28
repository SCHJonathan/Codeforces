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
    vint xdir = {0, -1, -1, 1, 1, 0, 0};
    vint ydir = {0, -1, 1, -1, 1, -1, 1};

    int find(vint& set, int x) {
        if (set[x] != x) {
            set[x] = find(set, set[x]);
        }
        return set[x];
    }

    int unify(vint& set, vint& size, int x, int y) {
        x = find(set, x), y = find(set, y);
        if (x == y) return size[x];
        set[x] = y;
        return size[x] = size[y] = size[x]+size[y];
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> sets(row, vint(col, 0));
        vector<vector<int>> sizes(row, vint(col, 1));
        for (int i = 0; i < row; i++) {
            auto& set = sets[i];
            for (int j = 0; j < col; j++) {
                set[j] = j;
            }
        }

        int res = 0;
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        for (auto& cell : cells) {
            int x = cell[0]-1, y = cell[1]-1;
            grid[x][y] = true;
            for (int i = 0; i < xdir.size(); i++) {
                int xx = x+xdir[i], yy = y+ydir[i];
                // debug(xx, yy);
                if (xx >= 0 && xx < row && yy >= 0 && yy < col && grid[xx][yy]) {
                    if (unify(sets[xx], sizes[xx], y, yy) == col) return res; 
                    if (unify(sets[x], sizes[x], y, yy) == col) return res;
                }
            }
            res++;
            debug(res);
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int row = 2;
    int col = 2;
    vector<vector<int>> cells = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
    int _ret_ans = 2;
    int _ret = _sol.latestDayToCross(row, col, cells);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    int row = 2;
    int col = 2;
    vector<vector<int>> cells = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    int _ret_ans = 1;
    int _ret = _sol.latestDayToCross(row, col, cells);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    int row = 3;
    int col = 3;
    vector<vector<int>> cells = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}};
    int _ret_ans = 3;
    int _ret = _sol.latestDayToCross(row, col, cells);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
