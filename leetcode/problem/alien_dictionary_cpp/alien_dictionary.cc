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
    bool compare(string& a, string& b, vector<unordered_set<int>>& graph) {
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] != b[i]) {
                graph[a[i]-'a'].insert(b[i]-'a');
                return true;
            }
        }
        if (a.size() > b.size()) return false;
        return true;
    }

    bool dfs(vector<unordered_set<int>>& graph, 
             string& result, 
             bool* visiting, bool* visited,
             int node) {
        if (visiting[node]) return true;
        if (visited[node]) return false;
        visiting[node] = true;
        for (auto& neighbor : graph[node]) {
            bool res = dfs(graph, result, visiting, visited, neighbor);
            if (res) return true;
        }
        visiting[node] = false;
        visited[node] = true;
        result += (char)('a'+node);
        return false;
    }

    string alienOrder(vector<string>& words) {
        vint in(26);
        unordered_set<int> all;
        vector<unordered_set<int>> graph(27);
        for (int i = 0; i < words.size(); i++) {
            string& w = words[i];
            for (int j = 0; j < w.size(); j++) {
                all.insert(w[j]-'a');
            }
            if (i) {
                bool valid = compare(words[i-1], words[i], graph);
                if (!valid) return "";
            }
        }

        for (auto& v : graph)
            for (auto& x : v)
                in[x]++;

        for (int i = 0; i < 26; i++) {
            if (graph[i].size() == 0) continue;
            for (auto& n : graph[i]) {
                debug((char)('a'+i), " -> ", (char)('a'+n));
            }
        }

        string result = "";
        bool visiting[27], visited[27];
        memset(visited, 0, sizeof(visited));
        memset(visiting, 0, sizeof(visiting));
        for (auto& x : all)
            graph[26].insert(x);
        
        bool res = dfs(graph, result, visiting, visited, 26);
        if (res) return "";
        reverse(result.begin(), result.end());
        all.clear();
        return result.substr(1);
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string _ret_ans = "wertf";
    string _ret = _sol.alienOrder(words);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> words = {"z", "x"};
    string _ret_ans = "zx";
    string _ret = _sol.alienOrder(words);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> words = {"z", "x", "z"};
    string _ret_ans = "";
    string _ret = _sol.alienOrder(words);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    vector<string> words = {"ac","ab","b"};
    string _ret_ans = "acb";
    string _ret = _sol.alienOrder(words);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
