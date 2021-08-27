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
    vector<string> parse(string& preorder) {
        vector<string> res; int prev = -1;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',') {
                res.push_back(preorder.substr(prev+1, i-prev-1));
                prev = i;
            }
        }
        res.push_back(preorder.substr(prev+1, preorder.size()-prev-1));
        return res;
    }

    bool isValidSerialization(string preorder) {
        stack<int> st;
        if (preorder == "#") return true;
        vector<string> values = parse(preorder);
        for (int i = 0; i < values.size(); i++) {
            string node = values[i];
            if (i != 0 && st.empty()) return false;
            if (i != 0) st.top()++;
            if (node != "#") st.push(0);
            while (!st.empty() && st.top() == 2) st.pop();
        }
        return st.empty();
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool _ret_ans = true;
    bool _ret = _sol.isValidSerialization(preorder);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string preorder = "1,#";
    bool _ret_ans = false;
    bool _ret = _sol.isValidSerialization(preorder);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string preorder = "9,#,#,1";
    bool _ret_ans = false;
    bool _ret = _sol.isValidSerialization(preorder);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
