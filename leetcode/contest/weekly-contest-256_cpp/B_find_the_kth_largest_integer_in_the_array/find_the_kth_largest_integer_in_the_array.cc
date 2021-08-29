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
    bool compare(string& x, string& y) {
        if (x.size() != y.size()) {
            return x.size() > y.size();
        } else {
            for (int i = 0; i < x.size(); i++) {
                if (x[i] > y[i]) return true;
                if (x[i] < y[i]) return false;
            }
            return true;
        }
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](auto& x, auto& y) {
            if (x.size() != y.size()) {
                return x.size() > y.size();
            } else {
                for (int i = 0; i < x.size(); i++) {
                    if (x[i] > y[i]) return true;
                    if (x[i] < y[i]) return false;
                }
                return true;
            }
        };
        priority_queue<string, vector<string>, decltype(comp)> pq(comp);
        for (auto& x : nums) {
            // int x =stoi(s);
            if (pq.size() < k) pq.push(x);
            else {
                string y = pq.top();
                debug(x, y);
                if (compare(x, y)) {
                    pq.pop();
                    pq.push(x);
                }
            }
        }

        return pq.top();
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> nums = {"3", "6", "7", "10"};
    int k = 4;
    string _ret_ans = "3";
    string _ret = _sol.kthLargestNumber(nums, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> nums = {"2", "21", "12", "1"};
    int k = 3;
    string _ret_ans = "2";
    string _ret = _sol.kthLargestNumber(nums, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> nums = {"0", "0"};
    int k = 2;
    string _ret_ans = "0";
    string _ret = _sol.kthLargestNumber(nums, k);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    vector<string> nums = {"423","521","2","42"};
    int k = 2;
    string _ret_ans = "423";
    string _ret = _sol.kthLargestNumber(nums, k);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
