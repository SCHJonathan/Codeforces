// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <array>
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
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        vector<set<array<int, 2>>> state(n);
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        // [cost, time, node]
        priority_queue<array<int,3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({fees[0], 0, 0});
        while (!pq.empty()) {
            auto [cost, time, node] = pq.top(); pq.pop();
            debug(cost, time, node);
            if (node == n-1) return cost;
            for (auto& neighborPair : graph[node]) {
                auto [neighbor, timeCost] = neighborPair;
                int timeNew = time+timeCost;
                int costNew = cost+fees[neighbor];
                debug(costNew, timeNew, neighbor);
                if (timeNew > maxTime) continue;
                auto& stateSet = state[neighbor];
                auto it = stateSet.upper_bound({costNew, timeNew});
                if (it == stateSet.begin() || (*prev(it))[1] > timeNew) {
                    stateSet.insert({costNew, timeNew});
                    pq.push({costNew, timeNew, neighbor});
                }
            }
        }
        
        return -1;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int maxTime = 30;
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> passingFees = {5, 1, 2, 20, 20, 3};
    int _ret_ans = 11;
    int _ret = _sol.minCost(maxTime, edges, passingFees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    int maxTime = 29;
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> passingFees = {5, 1, 2, 20, 20, 3};
    int _ret_ans = 48;
    int _ret = _sol.minCost(maxTime, edges, passingFees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    int maxTime = 25;
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> passingFees = {5, 1, 2, 20, 20, 3};
    int _ret_ans = -1;
    int _ret = _sol.minCost(maxTime, edges, passingFees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}

void test_example_3(Solution &_sol) {
    int maxTime = 10;
    vector<vector<int>> edges = {{1,2,4},{2,0,9},{3,0,4},{0,1,9},{4,3,10},{4,3,8},{3,1,2},{2,1,9},{0,2,1},{4,1,2}};
    vector<int> passingFees = {8,5,10,4,10};
    int _ret_ans = 27;
    int _ret = _sol.minCost(maxTime, edges, passingFees);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
