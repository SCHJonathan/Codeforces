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

class Solution {
public:
    const int MAX = (1 << 16);

    void getData(vector<int>& students, vector<int>& mentors, int curr, int m) {
        int mask = 1;
        for (int i = 0; i < m; i++, mask <<= 1) {
            if ((curr & mask) == 0) {
                mentors.push_back(i);
            }
        }
        mask = 1 << m;
        for (int i = 0; i < m; i++, mask <<= 1) {
            if ((curr & mask) == 0) {
                students.push_back(i);
            }
        }
    }

    int setCurr(int curr, int i, int j, int m) {
        return curr | (1 << (i+m)) | (1 << j); 
    }

    int memo(vector<vint>& benefit, vector<int>& dp, int curr, int& m) {
        if (dp[curr] != -1) return dp[curr];
        vector<int> students, mentors;
        getData(students, mentors, curr, m);
        debug(students, mentors, curr, m);
        int res = 0;
        for (auto st : students) {
            for (auto men : mentors) {
                int x = setCurr(curr, st, men, m);
                debug(st, men);
                res = max(res, benefit[st][men]+memo(benefit, dp, x, m));
            }
        }
        return dp[curr] = res;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students[0].size();
        vector<int> dp(MAX, -1);
        vector<vint> benefit(m, vint(m, 0)); 
        // auto comp = [&](auto& x, auto& y) {
        //     return x[0] < y[0];
        // };
        // // {price, student, mentor}
        // priority_queue<array<int,3>, vector<array<int,3>>, decltype(comp)> pq(comp);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int price = 0;
                for (int k = 0; k < n; k++) {
                    if (students[i][k] == mentors[j][k]) {
                        price++;
                    }
                }
                benefit[i][j] = price;
                // pq.push({price, i, j});
            }
        }
        debug(benefit);
        // int res = 0;

        // bool st[m], men[m]; 

        // memset(st, 0, sizeof(st));
        // memset(men, 0, sizeof(men));
        // while (!pq.empty()) {
        //     auto [price, student, mentor] = pq.top(); pq.pop();
        //     if (st[student] || men[mentor]) continue;
        //     res += price; st[student] = true, men[mentor] = true;
        // }
        return memo(benefit, dp, 0, m);;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> mentors = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    int _ret_ans = 8;
    int _ret = _sol.maxCompatibilitySum(students, mentors);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> students = {{0, 0}, {0, 0}, {0, 0}};
    vector<vector<int>> mentors = {{1, 1}, {1, 1}, {1, 1}};
    int _ret_ans = 0;
    int _ret = _sol.maxCompatibilitySum(students, mentors);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> students = {{0,1,0,1,1,1},{1,0,0,1,0,1},{1,0,1,1,0,0}};
    vector<vector<int>> mentors = {{1,0,0,0,0,1},{0,1,0,0,1,1},{0,1,0,0,1,1}};
    int _ret_ans = 10;
    int _ret = _sol.maxCompatibilitySum(students, mentors);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    test_example_2(_sol);
}
