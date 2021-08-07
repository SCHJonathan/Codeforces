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
    char revert(char color) {
        return color == 'B' ? 'W' : 'B';
    }

    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        // horizontal line
        board[rMove][cMove] = color;
        vint xdir = {0, 0, -1, 1, -1, 1, 1, -1};
        vint ydir = {1, -1, 0, 0, -1, 1, -1, 1};
        // vint xdir = {-1};
        // vint ydir = {-1};

        debug(board);
        for (int i = 0; i < xdir.size(); i++) {
            int x = rMove, y = cMove;
            int count = 0;
            while (x < 8 && y < 8 && x >= 0 && y >= 0 && board[x][y] == color) {
                x += xdir[i], y += ydir[i];
                count++;
            }
            if (x >= 8 || x < 0 || y >= 8 || y < 0 || board[x][y] == '.' || count > 1) continue;
            while (x < 8 && y < 8 && x >= 0 && y >= 0 && board[x][y] == revert(color)) {
                x += xdir[i], y += ydir[i];
            }
            if (x >= 8 || x < 0 || y >= 8 || y < 0 || board[x][y] == '.') continue;
            return true;
        }
        return false;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<char>> board = {{'.', '.', '.', 'B', '.', '.', '.', '.'}, {'.', '.', '.', 'W', '.', '.', '.', '.'}, {'.', '.', '.', 'W', '.', '.', '.', '.'}, {'.', '.', '.', 'W', '.', '.', '.', '.'}, {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'}, {'.', '.', '.', 'B', '.', '.', '.', '.'}, {'.', '.', '.', 'B', '.', '.', '.', '.'}, {'.', '.', '.', 'W', '.', '.', '.', '.'}};
    int rMove = 4;
    int cMove = 3;
    char color = 'B';
    bool _ret_ans = true;
    bool _ret = _sol.checkMove(board, rMove, cMove, color);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', 'B', '.', '.', 'W', '.', '.', '.'}, {'.', '.', 'W', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'W', 'B', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', 'B', 'W', '.', '.'}, {'.', '.', '.', '.', '.', '.', 'W', '.'}, {'.', '.', '.', '.', '.', '.', '.', 'B'}};
    int rMove = 4;
    int cMove = 4;
    char color = 'W';
    bool _ret_ans = false;
    bool _ret = _sol.checkMove(board, rMove, cMove, color);
    test("Example - 1", _ret_ans, _ret);
}
void test_example_2(Solution &_sol) {
    vector<vector<char>> board = {{'W','W','.','W','.','.','B','.'},{'.','B','W','B','B','.','.','.'},{'B','.','B','.','W','B','W','B'},{'B','B','W','W','B','B','W','W'},{'B','B','B','B','W','.','.','.'},{'B','W','W','W','.','.','B','B'},{'.','.','B','.','B','B','W','W'},{'B','.','B','B','B','B','.','W'}};
    int rMove = 0;
    int cMove = 7;
    char color = 'B';
    bool _ret_ans = false;
    bool _ret = _sol.checkMove(board, rMove, cMove, color);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<vector<char>> board = {{'W','W','.','B','.','B','B','.'},{'W','B','.','.','W','B','.','.'},{'B','B','B','B','W','W','B','.'},{'W','B','.','.','B','B','B','.'},{'W','W','B','.','W','.','B','B'},{'B','.','B','W','.','B','.','.'},{'.','B','B','W','B','B','.','.'},{'B','B','W','.','.','B','.','.'}};
    int rMove = 7;
    int cMove = 4;
    char color = 'B';
    bool _ret_ans = true;
    bool _ret = _sol.checkMove(board, rMove, cMove, color);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_4(Solution &_sol) {
    vector<vector<char>> board = {{'B','B','.','.','B','W','W','.'},{'.','W','W','.','B','W','B','B'},{'.','W','B','B','W','.','W','.'},{'B','.','.','B','W','W','W','.'},{'W','W','W','B','W','.','B','W'},{'.','.','.','W','.','W','.','B'},{'B','B','W','B','B','W','W','B'},{'W','.','W','W','.','B','.','W'}};
    int rMove = 2;
    int cMove = 5;
    char color = 'W';
    bool _ret_ans = false;
    bool _ret = _sol.checkMove(board, rMove, cMove, color);
    test("Example - 4", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
    test_example_4(_sol);

}
