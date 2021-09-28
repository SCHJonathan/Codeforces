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
    void dfs(unordered_map<int, vector<int>>& graph, 
             vector<bool>& visited, 
             vector<int>& nums, 
             vector<int>& result, 
             int& loc, int curr) {
        int n = nums.size();
        for (int& children : graph[curr]) {
            dfs(graph, visited, nums, result, loc, children);
        }
        debug(curr, nums[curr]);
        visited[nums[curr]] = true;
        while (loc <= n && visited[loc]) loc++;
        result[curr] = loc;
    } 

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size(), loc = 1;
        vector<int> result(n, -1);
        vector<bool> visited(n+1, false);
        unordered_map<int, vector<int>> graph;
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                root = i;
            } else {
                graph[parents[i]].push_back(i);
            }
        }
        dfs(graph, visited, nums, result, loc, root);
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> parents = {-1, 0, 0, 2};
    vector<int> nums = {1, 2, 3, 4};
    vector<int> _ret_ans = {5, 1, 1, 1};
    vector<int> _ret = _sol.smallestMissingValueSubtree(parents, nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> parents = {-1, 0, 1, 0, 3, 3};
    vector<int> nums = {5, 4, 6, 2, 1, 3};
    vector<int> _ret_ans = {7, 1, 1, 4, 2, 1};
    vector<int> _ret = _sol.smallestMissingValueSubtree(parents, nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> parents = {-1, 2, 3, 0, 2, 4, 1};
    vector<int> nums = {2, 3, 4, 5, 6, 7, 8};
    vector<int> _ret_ans = {1, 1, 1, 1, 1, 1, 1};
    vector<int> _ret = _sol.smallestMissingValueSubtree(parents, nums);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
