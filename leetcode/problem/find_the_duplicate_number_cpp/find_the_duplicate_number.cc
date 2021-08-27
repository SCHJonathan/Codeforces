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
    // negative market
    int findDuplicateNegativeMarket(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i])] < 0) return abs(nums[i]);
            nums[abs(nums[i])] *= -1;
        }

        // error
        return -1;
    }

    // Array as index map (recursive)
    int duplicate(vector<int>& nums, int curr) {
        if (nums[curr] == curr) return curr;
        int val = nums[curr];
        nums[curr] = curr;
        return duplicate(nums, val);
    }

    int findDuplicateArrayAsIdxMapRecursive(vector<int>& nums) {
        return duplicate(nums, 0);
    }

    // Array as index map (iterative)
    int findDuplicateArrayAsIdxMapIterative(vector<int>& nums) {
        while (nums[nums[0]] != nums[0]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }

    int countSmaller(vector<int>& nums, int val) {
        int count = 0;
        for (int& x : nums)
            count += x <= val;
        return count;
    }

    // Binary search
    int findDuplicateBinarySearch(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n-1, res = 0;
        while (left <= right) {
            int mid = left+(right-left)/2;
            int count = countSmaller(nums, mid);
            if (count > mid) {
                right = mid-1;
                res = mid;
            } else {
                left = mid+1;
            }
        }

        return res;
    }

    // bit count
    int findDuplicateBitCount(vector<int>& nums) {
        int n = nums.size();
        int countBitBase[32]; memset(countBitBase, 0, sizeof(countBitBase));
        for (int i = 1; i < n; i++) {
            int buffer = i, idx = 0;
            while (buffer) {
                if (buffer & 1) countBitBase[idx]--;
                buffer >>= 1;
                idx++;
            }
        }

        for (int x : nums) {
            int idx = 0;
            while (x) {
                if (x & 1) countBitBase[idx]++;
                x >>= 1;
                idx++;
            }
        }

        int res = 0;
        for (int i = 0; i < 30; i++) {
            int bit = 1 << i;
            if (countBitBase[i] > 0) res |= bit;
        }
        return res;
    }

    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums = {1, 3, 4, 2, 2};
    int _ret_ans = 2;
    int _ret = _sol.findDuplicate(nums);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums = {3, 1, 3, 4, 2};
    int _ret_ans = 3;
    int _ret = _sol.findDuplicate(nums);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> nums = {1, 1};
    int _ret_ans = 1;
    int _ret = _sol.findDuplicate(nums);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<int> nums = {1, 1, 2};
    int _ret_ans = 1;
    int _ret = _sol.findDuplicate(nums);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
