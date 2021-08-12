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
    // up, left, down, right
    vint xdir = {-1, 0, 1, 0};
    vint ydir = {0, -1, 0, 1};
    vector<string> dirStr = {"up", "left", "down", "right"};


    vector<array<int,3>> directions(int bx, int by, int ps, int py, vector<vector<char>>& grid) {
        vector<array<int,3>> res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pint> q; q.push({ps, py}); visited[ps][py] = true;
        while (!q.empty()) {
            auto [lx, ly] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = lx+xdir[i], yy = ly+ydir[i];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] == '#' || grid[xx][yy] == 'B' || visited[xx][yy] || (xx == bx && yy == by)) continue;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
        for (int i = 0; i < 4; i++) {
            int xx = bx+xdir[i], yy = by+ydir[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] == '#' || !visited[xx][yy] || (xx == bx && yy == by)) continue;
            // debug("player", xx, yy, i);
            xx = bx-xdir[i], yy = by-ydir[i]; 
            // debug("box", xx, yy, i);
            if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] == '#') continue;
            res.push_back({xx, yy, i});
        }
        return res;
    }

    array<int, 6> getPositions(vector<vector<char>>& grid) {
        array<int, 6> res;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'T') res[0] = i, res[1] = j;
                if (grid[i][j] == 'B') res[2] = i, res[3] = j;
                if (grid[i][j] == 'S') res[4] = i, res[5] = j;
            }
        }
        return res;
    }



    /**
     *  reach[i][j][4] : i, j
     */
    int minPushBox(vector<vector<char>>& grid) {
        debug(grid);
        int step = 0, m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(4, 0)));
        auto [targetX, targetY, boxX, boxY, playerX, playerY] = getPositions(grid);
        debug(targetX, targetY, boxX, boxY, playerX, playerY);
        queue<array<int,3>> q; q.push({boxX, boxY, -1});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y, dir] = q.front(); q.pop();
                string dirstr = dir == -1 ? "init" : dirStr[dir];
                // up, left, down, right
                if (x == targetX && y == targetY) return step;
                int px = dir == -1 ? playerX : x+xdir[dir];
                int py = dir == -1 ? playerY : y+ydir[dir];
                debug(x, y, px, py, dirstr);
                auto dirs = directions(x, y, px, py, grid);
                for (auto [nbx, nby, nd] :dirs) {
                    if (visited[nbx][nby][nd]) continue;
                    string ndirstr = nd == -1 ? "init" : dirStr[nd];
                    debug("push", nbx, nby, ndirstr);
                    visited[nbx][nby][nd] = true;
                    q.push({nbx, nby, nd});
                }
            }
            step++;
        }
        return -1;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<char>> grid = {{'#', '#', '#', '#', '#', '#'}, {'#', 'T', '#', '#', '#', '#'}, {'#', '.', '.', 'B', '.', '#'}, {'#', '.', '#', '#', '.', '#'}, {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}};
    int _ret_ans = 3;
    int _ret = _sol.minPushBox(grid);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<char>> grid = {{'#', '#', '#', '#', '#', '#'}, {'#', 'T', '#', '#', '#', '#'}, {'#', '.', '.', 'B', '.', '#'}, {'#', '#', '#', '#', '.', '#'}, {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}};
    int _ret_ans = -1;
    int _ret = _sol.minPushBox(grid);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<char>> grid = {{'#', '#', '#', '#', '#', '#'}, {'#', 'T', '.', '.', '#', '#'}, {'#', '.', '#', 'B', '.', '#'}, {'#', '.', '.', '.', '.', '#'}, {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}};
    int _ret_ans = 5;
    int _ret = _sol.minPushBox(grid);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<vector<char>> grid = {{'#', '#', '#', '#', '#', '#', '#'}, {'#', 'S', '#', '.', 'B', 'T', '#'}, {'#', '#', '#', '#', '#', '#', '#'}};
    int _ret_ans = -1;
    int _ret = _sol.minPushBox(grid);
    test("Example - 3", _ret_ans, _ret);
}

void test_example_4(Solution &_sol) {
    vector<vector<char>> grid = {{'#','.','.','#','#','#','#','#'},{'#','.','.','T','#','.','.','#'},{'#','.','.','.','#','B','.','#'},{'#','.','.','.','.','.','.','#'},{'#','.','.','.','#','.','S','#'},{'#','.','.','#','#','#','#','#'}};
    int _ret_ans = 7;
    int _ret = _sol.minPushBox(grid);
    test("Example - 4", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    // test_example_3(_sol);
    test_example_4(_sol);
}
