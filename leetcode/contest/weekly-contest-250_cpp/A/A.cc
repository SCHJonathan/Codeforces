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
    int canBeTypedWords(string text, string brokenLetters) {
        string word;
        istringstream in(text);
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int res = 0;
        while (getline(in, word, ' ')) {
            bool good = true;
            for (char & c : word) {
                if (broken.count(c)) {
                    good = false;
                    break;
                }
            }
            if (good) res++;
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string text = "hello world";
    string brokenLetters = "ad";
    int _ret_ans = 1;
    int _ret = _sol.canBeTypedWords(text, brokenLetters);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string text = "leet code";
    string brokenLetters = "lt";
    int _ret_ans = 1;
    int _ret = _sol.canBeTypedWords(text, brokenLetters);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string text = "leet code";
    string brokenLetters = "e";
    int _ret_ans = 0;
    int _ret = _sol.canBeTypedWords(text, brokenLetters);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
