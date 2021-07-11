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
    bool isSubsequence(unordered_map<char, vector<int>>& suffix, string& w) {
        int idx = -1;
        for (char& c : w) {
            auto v = suffix[c];
            auto it = upper_bound(v.begin(), v.end(), idx);
            if (it == v.end()) return false;
            idx = *it;
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        unordered_map<char, vector<int>> suffix;
        for (int i = 0; i < n; i++) {
            suffix[s[i]].push_back(i);
        }

        int res = 0;
        for (string& w : words) {
            if (isSubsequence(suffix, w)) {
                res++;
            }
        }
        return res;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};
    int _ret_ans = 3;
    int _ret = _sol.numMatchingSubseq(s, words);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    string s = "dsahjpjauf";
    vector<string> words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    int _ret_ans = 2;
    int _ret = _sol.numMatchingSubseq(s, words);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
