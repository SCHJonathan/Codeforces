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
    int binary(string& s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res |= s[i]-'0';
            res <<= 1;
        }

        return res >> 1;
    }

    string integer(int x, int n) {
        string res = "";
        while (x) {
            res += to_string(x & 1);
            x >>= 1;
        }
        reverse(res.begin(), res.end());
        if (res.size() < n) {
            res = string(n-res.size(), '0') + res;
        }
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int m = nums.size(), n = nums[0].size();
        // int base = (1 << n) - 1;
        // debug(base);
        // for (int i = 0; i < m; i++) {
        //     int x = binary(nums[i]);
        //     base ^= x;
        //     debug(base);
        // }
        // string res = integer(base);
        // debug(res);
        
        unordered_set<int> exist;
        for (string& s : nums) exist.insert(binary(s));
        int left = 0, right = (1 << n) - 1;
        for (int i = left; i <= right; i++) {
            if (exist.count(i) == 0) {
                return integer(i, n);
            }
        }
        return "";
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> nums = {"01", "10"};
    string _ret_ans = "11";
    string _ret = _sol.findDifferentBinaryString(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> nums = {"00", "01"};
    string _ret_ans = "11";
    string _ret = _sol.findDifferentBinaryString(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> nums = {"111", "011", "001"};
    string _ret_ans = "101";
    string _ret = _sol.findDifferentBinaryString(nums);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    vector<string> nums = {"10","11"};
    string _ret_ans = "00";
    string _ret = _sol.findDifferentBinaryString(nums);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
