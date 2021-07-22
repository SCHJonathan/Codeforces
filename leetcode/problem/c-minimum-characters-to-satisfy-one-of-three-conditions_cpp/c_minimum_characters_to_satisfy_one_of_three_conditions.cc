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
#define vll vector<int>
#define vull vector<int> 

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
    int helper(string a, string b) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        auto overlapA = lower_bound(a.begin(), a.end(), b[0]);
        if (overlapA == a.end()) return 0;
        auto overlapB = upper_bound(b.begin(), b.end(), a[n-1]);
        
        int overlapADis = overlapA-a.begin();
        int overlapBDis = overlapB-b.begin();
        debug(a, b, n-overlapADis, overlapBDis);
        return min(n-overlapADis, overlapBDis)+1;
    }

    int minCharacters(string a, string b) {
        return min(helper(a, b), helper(b, a));
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string a = "aba";
    string b = "caa";
    int _ret_ans = 2;
    int _ret = _sol.minCharacters(a, b);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string a = "dabadd";
    string b = "cda";
    int _ret_ans = 3;
    int _ret = _sol.minCharacters(a, b);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
