// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
#else
#define debug(x...)
#endif

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

const int RANGE = 1e9+7;

class Solution {
public:
    int find(vint& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void unionSet(vint& parent, int x, int y) {
        x = find(parent, x), y = find(parent, y);
        if (x == y) return;
        parent[x] = y;
    }

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<array<int, 3>> graph;

        for (auto& e : pipes) {
            graph.push_back({e[0], e[1], e[2]});
        }
        for (int i = 0; i < n; i++) {
            graph.push_back({0, i+1, wells[i]});
        }

        sort(graph.begin(), graph.end(), [](auto& x, auto& y) {return x[2] < y[2];});

        int res = 0;
        vint parent(n+1); for (int i = 0; i <= n; i++) parent[i] = i;
        for (auto& [x, y, cost] : graph) {
            x = find(parent, x), y = find(parent, y);
            if (x == y) continue;
            unionSet(parent, x, y);
            res += cost;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    int n = 3;
    vector<int> wells = {1, 2, 2};
    vector<vector<int>> pipes = {{1, 2, 1}, {2, 3, 1}};
    int _ret_ans = 3;
    int _ret = _sol.minCostToSupplyWater(n, wells, pipes);
    test("Example - 0", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
}
