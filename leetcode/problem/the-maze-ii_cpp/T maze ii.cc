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
    vector<int> xdir = {0, 1, 0, -1};
    vector<int> ydir = {1, 0, -1, 0};

    int shortestDistance(vector<vector<int>>& arr, vector<int>& s, vector<int>& d) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> weight(m, vector<int>(n, INT_MAX));
        auto comp = [](auto& x, auto& y) { return x[0] > y[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        pq.push({0, s[0], s[1]}); weight[s[0]][s[1]] = 0;
        
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int cost = curr[0], x = curr[1], y = curr[2];
            if (x == d[0] && y == d[1]) return cost;
            for (int i = 0; i < 4; i++) {
                int xx = x, yy = y, resx = x, resy = y;
                while (xx < m && xx >= 0 && yy < n && yy >= 0 && arr[xx][yy] == 0) {
                    resx = xx, resy = yy;
                    xx += xdir[i], yy += ydir[i];
                }
                if (resx == x && resy == y) continue;
                int newcost = cost+abs(x-resx)+abs(y-resy);
                if (weight[resx][resy] <= newcost) continue;
                weight[resx][resy] = newcost;
                pq.push({newcost, resx, resy});
            }
        }
        return -1;
    }   
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> maze = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
    vector<int> start = {0, 4};
    vector<int> destination = {4, 4};
    int _ret_ans = 12;
    int _ret = _sol.shortestDistance(maze, start, destination);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> maze = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
    vector<int> start = {0, 4};
    vector<int> destination = {3, 2};
    int _ret_ans = -1;
    int _ret = _sol.shortestDistance(maze, start, destination);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> maze = {{0, 0, 0, 0, 0}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 0}};
    vector<int> start = {4, 3};
    vector<int> destination = {0, 1};
    int _ret_ans = -1;
    int _ret = _sol.shortestDistance(maze, start, destination);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
