// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int> 

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef JONATHAN_DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

class Solution {
public:
    ll getHash(vector<int>& arr, int size) {
        ll hash = 0;
        for (int i = 0; i < size; i++) {
            hash = (hash*101%RANGE+arr[i])%RANGE;
        }
        // debug(hash, "getHash", size);
        return hash;
    }
    
    bool findDup(vector<int>& arr1, vector<int>& arr2, int size, ll* pow, unordered_map<ll, int>& visited) {
        // debug(arr1, arr2, size);
        visited.clear();
        int m = arr1.size(), n = arr2.size();
        ll hash = getHash(arr1, size);
        visited[hash] = 0;
        for (int i = size; i < m; i++) {
            hash = (hash-(arr1[i-size]*pow[size-1]%RANGE)+RANGE)%RANGE;
            hash = (hash*101%RANGE+arr1[i])%RANGE;
            visited[hash] = i-size+1;
        }
        
        // debug(visited);
        // for arr2
        for (int i = size-1; i < n; i++) {
            if (i == size-1) hash = getHash(arr2, size);
            else {
                hash = (hash-(arr2[i-size]*pow[size-1]%RANGE)+RANGE)%RANGE;
                hash = (hash*101%RANGE+arr2[i])%RANGE;
            }
            // int start = i-size+1;
            // debug(start, hash);
            if (visited.find(hash) != visited.end()) {
                bool valid = true;
                int idx1 = visited[hash], idx2 = i-size+1;
                for (int j = 0; j < size; j++, idx1++, idx2++) {
                    if (idx1 == m || idx2 == n || arr1[idx1] != arr2[idx2]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            } 
        }
        return false;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int minlen = min(nums1.size(), nums2.size());
        int left = 1, right = minlen;
        
        unordered_map<ll, int> visited;
        ll pow[minlen]; memset(pow, 0, sizeof(pow)); pow[0]=1;
        for (int i = 1; i < minlen; i++) pow[i] = pow[i-1]*101%RANGE;
        
        while (left <= right) {
            int mid = left+(right-left)/2;
            bool ans = findDup(nums1, nums2, mid, pow, visited);
            if (ans) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    int _ret_ans = 3;
    int _ret = _sol.findLength(nums1, nums2);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> nums1 = {0, 0, 0, 0, 0};
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int _ret_ans = 5;
    int _ret = _sol.findLength(nums1, nums2);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
