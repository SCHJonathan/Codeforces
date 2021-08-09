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
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0, idx = 0; string res = "";
        while (idx < num2.size()) {
            int sum = num1[idx]-'0'+num2[idx]-'0'+carry;
            debug(sum);
            res += (char)(sum%10+'0');
            carry = sum / 10;
            idx++;
        }
        while (idx < num1.size()) {
            int sum = num1[idx]-'0'+carry;
            debug(sum);
            res += (char)(sum%10+'0');
            carry = sum / 10;
            idx++;
        }
        if (carry) res += (char)('0'+carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string num1 = "11";
    string num2 = "123";
    string _ret_ans = "134";
    string _ret = _sol.addStrings(num1, num2);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string num1 = "456";
    string num2 = "77";
    string _ret_ans = "533";
    string _ret = _sol.addStrings(num1, num2);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string num1 = "0";
    string num2 = "0";
    string _ret_ans = "0";
    string _ret = _sol.addStrings(num1, num2);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
