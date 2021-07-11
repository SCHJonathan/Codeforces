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
    bool exits(unordered_map<int, unordered_map<int, unordered_map<int, pint>>>& dp,
               int sum, int i, int j, int turn) {
        bool valid = dp.find(sum) != dp.end() && dp[sum].find(i) != dp[sum].end() 
        && dp[sum][i].find(j) != dp[sum][i].end();
        debug("exits", sum, i, j, turn, valid);
        if (!valid) return false;
        auto& pair = dp[sum][i][j];
        if (turn) {
            return pair.second != -1;
        } else {
            return pair.first != -1;
        }
    }

    bool getAns(unordered_map<int, unordered_map<int, unordered_map<int, pint>>>& dp,
               int sum, int i, int j, int turn) {
        if (turn) {
            return dp[sum][i][j].second != -1;
        } else {
            return dp[sum][i][j].first != -1;
        }
    }

    bool setAns(unordered_map<int, unordered_map<int, unordered_map<int, pint>>>& dp,
               int sum, int i, int j, int turn, bool val) {
        bool valid = dp.find(sum) != dp.end() && dp[sum].find(i) != dp[sum].end() 
        && dp[sum][i].find(j) != dp[sum][i].end();
        if (!valid) dp[sum][i][j] = {-1, -1};
        if (turn) {
            return dp[sum][i][j].second = val;
        } else {
            return dp[sum][i][j].first = val;
        }
    }

    bool memo(unordered_map<int, unordered_map<int, unordered_map<int, pint>>>& dp, 
              int sum, int left, int right, int turn) {
        if (exits(dp, sum, left, right, turn)) {
            return getAns(dp, sum, left, right, turn);
        }
        if (left == 0 && right == 0) return sum != 0;
        if (left) {
            for (int d = 0; d < 9; d++) {
                int newsum = sum+d;
                bool ans = memo(dp, newsum, left-1, right, turn^1);
                if (turn) {
                    debug(sum, left, right, turn, false);
                    if (!ans) return false;
                } else {
                    debug(sum, left, right, turn, true);
                    if (ans) return true;
                }
            }
        }
        
        if (right) {
            for (int d = 0; d < 9; d++) {
                int newsum = sum-d;
                bool ans = memo(dp, newsum, left, right-1, turn^1);
                if (turn) {
                    debug(sum, left, right, turn, false);
                    if (!ans) return false;
                } else {
                    debug(sum, left, right, turn, true);
                    if (ans) return true;
                }
            }
        }
        if (turn) {
            debug(sum, left, right, turn, true);
            return setAns(dp, sum, left, right, turn, true);
        } else {
            debug(sum, left, right, turn, false);
            return setAns(dp, sum, left, right, turn, false);
        }
    }

    bool sumGame(string num) {
        int n = num.size();
        // {sum of first half - sum of second half, 
        //  question mark in first half, question mark in second half
        // }

        unordered_map<int, unordered_map<int, unordered_map<int, pint>>> dp;
        int sum = 0, i = 0, j = 0;
        for (int i = 0; i < n; i++) {
            if (i < n/2) {
                sum += num[i]-'a';
                i++;
            } else {
                sum -= num[i]-'a';
                j++;
            }
        }
        bool ans = memo(dp, sum, i, j, 0);
        return ans;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string num = "5023";
    bool _ret_ans = false;
    bool _ret = _sol.sumGame(num);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    string num = "25??";
    bool _ret_ans = true;
    bool _ret = _sol.sumGame(num);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    string num = "?3295???";
    bool _ret_ans = false;
    bool _ret = _sol.sumGame(num);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
