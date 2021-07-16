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

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<int>
#define vull vector<int> 

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
    int m, n;
    int dp[1000][1024];
    unordered_map<int, vector<int>> combinations;

    int memo(int col, int mask) {
        if (col == n) {
            return 1;
        }
        if (dp[col][mask] != -1) return dp[col][mask];
        int res = 0;
        vector<int> masks;
        getMasks(mask, masks);
        for (int& candidate : masks) {
            res = (res+memo(col+1, candidate))%RANGE;
        }
        return dp[col][mask] = res;
    }

    void getMasks(int mask, vector<int>& masks) {
        if (combinations.find(mask) != combinations.end()) {
            masks = combinations[mask];
            return;
        }
        dfs(mask, 0, 0, masks);
        combinations[mask] = masks;
    }

    void dfs(int& mask, int curr, int row, vector<int>& masks) {
        if (row == m) {
            masks.push_back(curr);
            return;
        }
        int above = row >= 1 ? getColor(curr, row-1) : 0;
        for (int i = 1; i <= 3; i++) {
            int left = getColor(mask, row);
            if (i == above || i == left) continue;
            dfs(mask, setColor(curr, row, i), row+1, masks);
        }
    }

    int getColor(int& mask, int row) {
        return (mask >> (2*row))&3;
    }

    int setColor(int& mask, int row, int color) {
        return (color << (2*row)) | mask;
    }

    // 1 <= m <= 5, 1 <= n <= 1000
    int colorTheGrid(int mInput, int nInput) {
        combinations.clear();
        m = mInput, n = nInput;
        for (int i = 0; i < 1000; i++)
            for (int j = 0; j < 1024; j++)
                dp[i][j] = -1;
        return memo(0, 0);
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int m = 1;
    int n = 1;
    int _ret_ans = 3;
    int _ret = _sol.colorTheGrid(m, n);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    int m = 1;
    int n = 2;
    int _ret_ans = 6;
    int _ret = _sol.colorTheGrid(m, n);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    int m = 5;
    int n = 5;
    int _ret_ans = 580986;
    int _ret = _sol.colorTheGrid(m, n);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
