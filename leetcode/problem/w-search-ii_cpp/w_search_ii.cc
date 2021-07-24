// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#ifdef JONATHAN
#include "_testing.h"
#endif

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

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

struct TrieTreeNode {
    string word;
    TrieTreeNode* children[26];
    TrieTreeNode() {
        memset(children, 0, sizeof(children));
    }
};


class Solution {
public:

    vector<int> xdir = {-1, 0, 1, 0};
    vector<int> ydir = {0, -1, 0, 1};

    void dfs(unordered_set<string>& resultSet, 
             vector<vector<char>>& board, 
             vector<vector<bool>>& visiting, 
             int x, int y, TrieTreeNode* node) {
        int m = board.size(), n = board[0].size();
        debug(x, y);
        if (node->word.size()) resultSet.insert(node->word);
        for (int i = 0; i < 4; i++) {
            int xx = x+xdir[i], yy = y+ydir[i];
            if (xx < 0 || yy < 0 || xx >= m || yy >= n || visiting[xx][yy]) continue;
            if (node->children[board[xx][yy]-'a'] == nullptr) continue;
            visiting[xx][yy] = true;
            dfs(resultSet, board, visiting, xx, yy, node->children[board[xx][yy]-'a']);
        }
        visiting[x][y] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        debug(board);
        unordered_set<string> resultSet;
        vector<vector<bool>> visiting(m, vector<bool>(n, false));
        TrieTreeNode* root = new TrieTreeNode();
        for (auto& w : words) {
            TrieTreeNode* thru = root;
            for (auto& c : w) {
                if (thru->children[c-'a'] == nullptr) {
                    thru->children[c-'a'] = new TrieTreeNode();
                }
                thru = thru->children[c-'a'];
            }
            thru->word = w;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                debug(i, j, board[i][j]);
                if (root->children[board[i][j]-'a'] == nullptr) continue;
                visiting[i][j] = true;
                dfs(resultSet, board, visiting, i, j, root->children[board[i][j]-'a']);
                debug("===");
            }
        }

        vector<string> result(resultSet.begin(), resultSet.end());
        return result;
    }

};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> _ret_ans = {"eat", "oath"};
    vector<string> _ret = _sol.findWords(board, words);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
    vector<string> words = {"abcb"};
    vector<string> _ret_ans = {};
    vector<string> _ret = _sol.findWords(board, words);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<vector<char>> board = {{'a','a'}};
    vector<string> words = {"aaa"};
    vector<string> _ret_ans = {};
    vector<string> _ret = _sol.findWords(board, words);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    test_example_2(_sol);
}
