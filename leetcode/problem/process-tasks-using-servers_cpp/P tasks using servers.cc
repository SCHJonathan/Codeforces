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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pint, vector<pint>, greater<pint>> idlepq; 
        priority_queue<pint, vector<pint>, greater<pint>> busypq; 
        
        for (int i = 0; i < n; i++)
            idlepq.push({servers[i], i});
        
        int currtime = 0;
        vector<int> res(m, -1);
        
        int i = 0;
        while (i < m) {
            // if no idle server, choose and wait for the latest busy server. update the currtime
            currtime = idlepq.empty() ? busypq.top().first : currtime;
            // push all the finished server in busypq into idlepq based on currtime
            while (!busypq.empty() && busypq.top().first <= currtime) {
                int serverIdx = busypq.top().second;
                idlepq.push({servers[serverIdx], serverIdx});
                busypq.pop();
            }
            
            while (i <= min(currtime, m-1) && !idlepq.empty()) {
                auto server = idlepq.top(); idlepq.pop();
                res[i] = server.second; 
                server.first = currtime + tasks[i];
                busypq.push(server);
                i++;
            }
            currtime = max(currtime, i);
        }
        
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> servers = {3, 3, 2};
    vector<int> tasks = {1, 2, 3, 2, 1, 2};
    vector<int> _ret_ans = {2, 2, 0, 2, 1, 2};
    vector<int> _ret = _sol.assignTasks(servers, tasks);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> servers = {5, 1, 4, 3, 2};
    vector<int> tasks = {2, 1, 2, 4, 5, 2, 1};
    vector<int> _ret_ans = {1, 4, 1, 4, 1, 3, 2};
    vector<int> _ret = _sol.assignTasks(servers, tasks);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
