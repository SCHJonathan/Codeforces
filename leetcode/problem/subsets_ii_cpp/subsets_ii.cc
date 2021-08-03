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
    void dfs(vector<vector<int>>& result, 
             vector<int>& nums, 
             vector<int>& curr, 
             int start) {
        int n = nums.size();
        result.push_back(curr);
        unordered_set<int> visited;
        for (int i = start; i < n; i++) {
            if (visited.count(nums[i])) continue;
            visited.insert(nums[i]);
            curr.push_back(nums[i]);
            dfs(result, nums, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vint curr;
        debug(nums);
        // sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        dfs(result, nums, curr, 0);
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> _ret_ans = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
    vector<vector<int>> _ret = _sol.subsetsWithDup(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {0};
    vector<vector<int>> _ret_ans = {{}, {0}};
    vector<vector<int>> _ret = _sol.subsetsWithDup(nums);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<int> nums = {4,4,4,1,4};
    vector<vector<int>> _ret_ans = {{},{1},{1,4},{1,4,4},{1,4,4,4},{1,4,4,4,4},{4},{4,4},{4,4,4},{4,4,4,4}};
    vector<vector<int>> _ret = _sol.subsetsWithDup(nums);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    test_example_2(_sol);
}
