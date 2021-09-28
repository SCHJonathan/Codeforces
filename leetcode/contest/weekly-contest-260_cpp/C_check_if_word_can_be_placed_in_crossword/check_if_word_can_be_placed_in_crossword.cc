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
    vector<int> xdir = {0, 1, 0, -1};
    vector<int> ydir = {1, 0, -1, 0};

    bool dfs(vector<vector<char>>& board, string& word, int direction, int idx, int x, int y) {
        int m = board.size(), n = board[0].size();
        int startX = x, startY = y;
        debug("start", x, y, idx, m, n, word.size());
        while (idx < word.size() && x < m && y < n && x >= 0 && y >= 0) {
            if (board[x][y] == '#' || (board[x][y] != ' ' && board[x][y] != word[idx])) break;
            x += xdir[direction];
            y += ydir[direction];
            idx++;
        }
        startX -= xdir[direction];
        startY -= ydir[direction];
        if (idx == word.size()) {
            debug("end", x, y, idx,direction, m, n, word.size());
        }
        return idx == word.size() && (x >= m || y >= n || x < 0 || y < 0 || board[x][y] == '#') && (startX < 0 || startY < 0 || startX >= m || startY >= n || board[startX][startY] == '#');
    }

    // bool placeWordInCrossword(vector<vector<char>>& board, string word) {
    //     int len = word.size();
    //     int m = board.size(), n = board[0].size();
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             // 0 horizontal 1 vertical 2 horizontal backward 3 vertical back
    //             for (int dir = 0; dir < 4; dir++) {
    //                 if (dir == 0 && j+len-1 >= n) continue;
    //                 if (dir == 1 && i+len-1 >= m) continue;
    //                 if (dir == 2 && j-len+1 < 0) continue;
    //                 if (dir == 3 && j-len+1 < 0) continue;
    //                 debug(i, j, dir);
    //                 bool okay = dfs(board, word, dir, 0, i, j);
    //                 if (okay) return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size(), n = board[0].size();
        unordered_map<int, vector<pair<int, int>>> horizontal, vertical;
        for (int i = 0; i < m; i++) {
            int window = 0, left = -1;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ' ' || isalpha(board[i][j])) {
                    if (window == 0) {
                        left = j;
                    }
                    window++;
                } else {
                    if (window == word.size()) {
                        horizontal[i].push_back({j-word.size(), j-1});
                    }
                    window = 0;
                }
            } 
            if (window == word.size()) {
                horizontal[i].push_back({n-word.size(), n-1});
            }
        }

        for (int i = 0; i < n; i++) {
            int window = 0;
            for (int j = 0; j < m; j++) {
                if (board[j][i] == ' ' || isalpha(board[j][i])) {
                    window++;
                } else {
                    if (window == word.size()) {
                        vertical[i].push_back({j-word.size(), j-1});
                    }
                    window = 0;
                }
            } 
            if (window == word.size()) {
                vertical[i].push_back({m-word.size(), m-1});
            }
        }

        for (auto& [row, horizontalPairs] : horizontal) {
            for (auto& [start, end] : horizontalPairs) {
                bool okay = true;
                for (int i = start; i <= end; i++) {
                    if (board[row][i] != ' ' && board[row][i] != word[i-start]) {
                        okay = false;
                        break;
                    }
                }
                if (okay) return true;
                okay = true;
                for (int i = end; i >= start; i--) {
                    if (board[row][i] != ' ' && board[row][i] != word[end-i]) {
                        okay = false;
                        break;
                    }
                }
                if (okay) return true;
            }
        }
        for (auto& [col, verticalPairs] : vertical) {
            for (auto& [start, end] : verticalPairs) {
                bool okay = true;
                for (int i = start; i <= end; i++) {
                    if (board[i][col] != ' ' && board[i][col] != word[i-start]) {
                        okay = false;
                        break;
                    }
                }
                if (okay) return true;
                okay = true;
                for (int i = end; i >= start; i--) {
                    if (board[i][col] != ' ' && board[i][col] != word[end-i]) {
                        okay = false;
                        break;
                    }
                }
                if (okay) return true;
                debug(start, end);
            }
        }
        return false;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<char>> board = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}};
    string word = "abc";
    bool _ret_ans = true;
    bool _ret = _sol.placeWordInCrossword(board, word);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<char>> board = {{' ', '#', 'a'}, {' ', '#', 'c'}, {' ', '#', 'a'}};
    string word = "ac";
    bool _ret_ans = false;
    bool _ret = _sol.placeWordInCrossword(board, word);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<char>> board = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', ' ', 'c'}};
    string word = "ca";
    bool _ret_ans = true;
    bool _ret = _sol.placeWordInCrossword(board, word);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
