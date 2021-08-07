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
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        vint copy = nums;
        debug(nums);
        vector<vint> waste = {{nums[0], 0}};
        int res = 0, n = nums.size(), bufferRes = 0;
        vector<pint> downWaste; int countWaste = 0;
        for (int i = 1; i < n; i++) {
            if (copy[i] < copy[i-1]) {
                bufferRes += copy[i-1]-copy[i];
                copy[i] = copy[i-1];
            }
            if (copy[i] != copy[i-1]) {
                waste.push_back({copy[i], i});
            }
        }
        debug(nums, copy);
        for (int i = 1; i < n; i++) {
            // if (nums[i] == copy[i]) continue;
            debug(nums[i], copy[i]);
            if (copy[i] == nums[i]) continue;

            if (i+1 < n && nums[i+1] > nums[i]) {
                downWaste.push_back({copy[i]-nums[i], 2});
                countWaste += 2;
            } else {
                downWaste.push_back({copy[i]-nums[i], 1});
                countWaste += 1;
            }
        }
        int m = waste.size();
        debug(waste);
        if (m <= k) {
            if (countWaste+m <= k) return 0;
            vint ones, twos;
            for (auto& p : downWaste) {
                if (p.second == 2) twos.push_back(p.first);
                else ones.push_back(p.first);
            }
            sort(ones.begin(), ones.end(), greater<int>());
            sort(twos.begin(), twos.end(), greater<int>());
            deque<int> onesDq(ones.begin(), ones.end());
            deque<int> twosDq(twos.begin(), twos.end());
            debug(ones, twos);
            int step = k-m+1;
            debug(step);
            while (step) {
            debug(ones, twos);
                if (twosDq.size() == 0) {
                    onesDq.pop_back();
                    step--;
                    continue;
                } 
                if (onesDq.size() == 0) {
                    if (step < 2) break;
                    twosDq.pop_back();
                    step -= 2;
                    continue;
                } 
                if (onesDq.size() > 1) {
                    int x = onesDq.back(); onesDq.pop_back();
                    int y = onesDq.back(); onesDq.pop_back();
                    if (x + y >= twosDq.back()) {
                        step -= 2;
                    } else {
                        onesDq.push_back(y);
                        onesDq.push_back(x);
                        twosDq.pop_back();
                        step -= 2;
                    }
                } else {
                    if (step < 2 || onesDq.back() > twosDq.back()) {
                        onesDq.pop_back();
                        step--;
                        continue;      
                    } else {
                        if (step < 2) break;
                        twosDq.pop_back();
                        step -= 2;
                        continue;
                    }
                }
            }

            for (int& x : onesDq) {
                res += x;
            }
            for (int& x : twosDq) {
                res += x;
            }
            return res;
        }
        int size = waste[m-1-k][0], idx = waste[m-1-k][1];
        debug(size, idx, waste, m-2-k);
        for (int i = m-2-k; i >= 0; i--) {
            int currIdx = waste[i][1], currSize = waste[i][0];
            debug(currIdx, currSize);
            res += (size-currSize)*(idx-currIdx);
            idx = currIdx;
        }
        return res + bufferRes;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {10, 20};
    int k = 0;
    int _ret_ans = 10;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {10, 20, 30};
    int k = 1;
    int _ret_ans = 10;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {10, 20, 15, 30, 20};
    int k = 2;
    int _ret_ans = 15;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    vector<int> nums = {13,46,42,45,35};
    int k = 4;
    int _ret_ans = 0;
    int _ret = _sol.minSpaceWastedKResizing(nums, k);
    test("Example - 3", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    test_example_3(_sol);
}
