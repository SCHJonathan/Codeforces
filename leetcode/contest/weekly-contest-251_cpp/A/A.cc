// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

#ifdef JONATHAN
#include "_testing.h"
#endif

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

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
    int getLucky(string s, int k) {
        string curr = "";
        for (auto& c : s) {
            curr += to_string(c-'a'+1);
        }
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (auto& c : curr) {
                sum += c-'0';
            }
            curr = to_string(sum);
        }

        return stoi(curr);
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "iiii";
    int k = 1;
    int _ret_ans = 36;
    int _ret = _sol.getLucky(s, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "leetcode";
    int k = 2;
    int _ret_ans = 6;
    int _ret = _sol.getLucky(s, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "zbax";
    int k = 2;
    int _ret_ans = 8;
    int _ret = _sol.getLucky(s, k);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
