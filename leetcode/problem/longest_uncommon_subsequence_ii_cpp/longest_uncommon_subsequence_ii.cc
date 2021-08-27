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
    bool isSubsequence(string& shortStr, string& longStr) {
        if (shortStr.size() > longStr.size()) return false;
        int i = 0, j = 0;
        int m = shortStr.size(), n = longStr.size();
        while (i < m && j < n) {
            if (shortStr[i] == longStr[j]) i++;
            j++;            
        }
        return i == m;
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size(), res = -1;
        sort(strs.begin(), strs.end());

        for (int i = n-1; i >= 0; i--) {
            bool valid = true;
            for (int j = n-1; j >= 0; j--) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    valid = false;
                    break;
                }
            }
            if (valid) res = max(res, (int)strs[i].size());
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> strs = {"aba", "cdc", "eae"};
    int _ret_ans = 3;
    int _ret = _sol.findLUSlength(strs);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> strs = {"aaa", "aaa", "aa"};
    int _ret_ans = -1;
    int _ret = _sol.findLUSlength(strs);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
