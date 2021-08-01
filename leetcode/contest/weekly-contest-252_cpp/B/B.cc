// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
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
    long long numberOfWeeks(vector<int>& milestones) {
        ll sum = 0;
        int n = milestones.size();
        sort(milestones.begin(), milestones.end());
        for (int& x : milestones) {
            sum += x;
        }
        return milestones[n-1] > sum-milestones[n-1] ? (sum-milestones[n-1])*2+1 : sum;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> milestones = {1, 2, 3};
    long long _ret_ans = 6;
    long long _ret = _sol.numberOfWeeks(milestones);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> milestones = {5, 2, 1};
    long long _ret_ans = 7;
    long long _ret = _sol.numberOfWeeks(milestones);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<int> milestones = {5,7,5,7,9,7};
    long long _ret_ans = 40;
    long long _ret = _sol.numberOfWeeks(milestones);
    test("Example - 1", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);

}
