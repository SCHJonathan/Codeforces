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
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        int left = 0, right = n-1, leftMaxHeight = height[0], rightMaxHeight = height[n-1];
        debug(height);
        while (left <= right) {
            debug(left, right, height[left], height[right]);
            if (height[left] <= height[right]) {
                // left is the threshold
                if (height[left] >= leftMaxHeight) {
                    leftMaxHeight = height[left];
                } else {
                    debug(min(leftMaxHeight, rightMaxHeight)-height[left]);
                    res += min(leftMaxHeight, rightMaxHeight)-height[left];
                }
                left++;
            } else {
                // right is the threshold
                if (height[right] >= rightMaxHeight) {
                    rightMaxHeight = height[right];
                } else {
                    res += min(leftMaxHeight, rightMaxHeight)-height[right];
                }
                right--;
            }
            leftMaxHeight = max(leftMaxHeight, height[left]);
            rightMaxHeight = max(rightMaxHeight, height[right]);
        }

        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int _ret_ans = 6;
    int _ret = _sol.trap(height);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int _ret_ans = 9;
    int _ret = _sol.trap(height);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
