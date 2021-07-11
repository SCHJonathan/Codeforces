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
    const vector<int> xdir = {-1, 0, 1, 0};
    const vector<int> ydir = {0, 1, 0, -1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int entrX = entrance[0], entrY = entrance[1];

        int step = 0;
        queue<pint> q; bool visited[m][n]; memset(visited, 0, sizeof(visited));
        visited[entrX][entrY] = true; q.push({entrX, entrY});

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front(); q.pop();
                int x = curr.first, y = curr.second;
                if ((x == 0 || y == 0 || x == m-1 || y == n-1) && step) return step;
                for (int j = 0; j < 4; j++) {
                    int xx = x+xdir[j], yy = y+ydir[j];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || maze[xx][yy] == '+' || visited[xx][yy]) continue;
                    q.push({xx, yy}); visited[xx][yy] = true;
                }
            }
            step++;
        }
        return -1;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};
    int _ret_ans = 1;
    int _ret = _sol.nearestExit(maze, entrance);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    vector<vector<char>> maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
    vector<int> entrance = {1, 0};
    int _ret_ans = 2;
    int _ret = _sol.nearestExit(maze, entrance);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    vector<vector<char>> maze = {{'.', '+'}};
    vector<int> entrance = {0, 0};
    int _ret_ans = -1;
    int _ret = _sol.nearestExit(maze, entrance);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
