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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < 4; i++) {
            bool okay = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[j][n-1-i]) {
                        okay = false;
                        break;
                    }
                }
                if (!okay) break;
            }
            if (okay) return true;

            vector<vector<int>> newmat(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    newmat[j][n-1-i] = mat[i][j];
                }
            }
            mat = newmat;
        }
        
        return false;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    bool _ret_ans = true;
    bool _ret = _sol.findRotation(mat, target);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> mat = {{0, 1}, {1, 1}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    bool _ret_ans = false;
    bool _ret = _sol.findRotation(mat, target);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> target = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    bool _ret_ans = true;
    bool _ret = _sol.findRotation(mat, target);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
