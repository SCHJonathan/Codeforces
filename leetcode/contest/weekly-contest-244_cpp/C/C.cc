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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

class Solution {
public:
    int startwith(int bit, string& s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i]-'0' != bit) res++;
            bit = 1^bit;
        }
        return res;
    }

    /**
     * 111000
     * 110001 ++ ++++
     * 100011 ++++
     * 01001001101 ++++++ +++++
     * 10010011010 ++++ +++++++
     * 0010011010
     
     * 0010011010 +++++++
     * 0101010101
     * 
     * 00100110110
     * 01010101010
     * 
     */
    int minFlips(string s) {
        int n = s.size();
        int zero = startwith(0, s), one = startwith(1, s);
        int zeroend = n % 2 == 0 ? 1 : 0;
        int oneend = n % 2 == 0 ? 0 : 1;
        // debug(zero, one);
        int res = min(zero, one);
        if (res == 0) return res;
        for (int i = 1; i < n; i++) {
            int prevzero = zero, prevone = one;
            zero = prevone-(s[i-1]!='1')+(s[i-1]-'0'!=zeroend);
            one  = prevzero-(s[i-1]!='0')+(s[i-1]-'0'!=oneend);

            // string tonea = s.substr(0, i);
            // string toneb = s.substr(i)+tonea;
            // int testone = startwith(1, toneb), testzero = startwith(0, toneb);
            // debug(toneb);
            // debug(zero, one);
            // debug(testzero, testone);

            res = min(min(zero, one), res);
            if (res == 0) return res;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "111000";
    int _ret_ans = 2;
    int _ret = _sol.minFlips(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    string s = "010";
    int _ret_ans = 0;
    int _ret = _sol.minFlips(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    string s = "1110";
    int _ret_ans = 1;
    int _ret = _sol.minFlips(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_3(Solution &_sol) {
    string s = "01001001101";
    int _ret_ans = 5;
    int _ret = _sol.minFlips(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}



int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
