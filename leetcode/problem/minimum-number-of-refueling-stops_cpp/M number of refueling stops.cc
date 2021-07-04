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
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        int n = stations.size();
        sort(stations.begin(), stations.end());

        int steps = 0, idx = 0, location = 0;
        while (fuel+location < target) {
            int maxval = INT_MIN, maxidx = -1;
            for (int i = idx; i < n && stations[i][0] <= fuel+location; i++) {
                int reach = fuel+location+stations[i][1];
                if (reach > maxval) {
                    maxval = reach; maxidx = i;
                }
            }
            if (maxidx == -1) return -1;
            debug("before", location, fuel, maxidx);
            fuel = fuel-stations[maxidx][0]+location+stations[maxidx][1];
            location = stations[maxidx][0];
            idx = maxidx+1;
            debug("after", location, fuel, maxidx);
            steps++;
        }
        return steps;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int target = 1;
    int startFuel = 1;
    vector<vector<int>> stations = {};
    int _ret_ans = 0;
    int _ret = _sol.minRefuelStops(target, startFuel, stations);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    int target = 100;
    int startFuel = 1;
    vector<vector<int>> stations = {{10, 100}};
    int _ret_ans = -1;
    int _ret = _sol.minRefuelStops(target, startFuel, stations);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int _ret_ans = 2;
    int _ret = _sol.minRefuelStops(target, startFuel, stations);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_3(Solution &_sol) {
    int target = 100;
    int startFuel = 25;
    vector<vector<int>> stations = {{25,25},{50,25},{75,25}};
    int _ret_ans = 3;
    int _ret = _sol.minRefuelStops(target, startFuel, stations);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_4(Solution &_sol) {
    int target = 1000;
    int startFuel = 299;
    vector<vector<int>> stations = {{13,21},{26,115},{100,47},{225,99},{299,141},{444,198},{608,190},{636,157},{647,255},{841,123}};
    int _ret_ans = 4;
    int _ret = _sol.minRefuelStops(target, startFuel, stations);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    // test_example_3(_sol);
    test_example_4(_sol);
}
