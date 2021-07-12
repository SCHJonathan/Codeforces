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
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, pint> idx;
        unordered_map<char, vector<int>> idxlist;
        for (int i = 0; i < n; i++) {
            if (idx.find(s[i]) == idx.end()) {
                idx[s[i]] = {i, i};
            } else {
                idx[s[i]].second = i;
            }
            idxlist[s[i]].push_back(i);
        }

        int res = 0;
        for (auto& pair : idx) {
            auto& range = pair.second;
            if (range.first == range.second) continue;
            for (auto& idxlistPair: idxlist) {
                auto& v = idxlistPair.second;
                auto it = upper_bound(v.begin(), v.end(), range.first);
                if (it != v.end() && *it < range.second) {
                    res++;
                }
            }
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "aabca";
    int _ret_ans = 3;
    int _ret = _sol.countPalindromicSubsequence(s);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_1(Solution &_sol) {
    string s = "adc";
    int _ret_ans = 0;
    int _ret = _sol.countPalindromicSubsequence(s);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


void test_example_2(Solution &_sol) {
    string s = "bbcbaba";
    int _ret_ans = 4;
    int _ret = _sol.countPalindromicSubsequence(s);
    cout << " Expected:" << _ret_ans << " My Answer:" << _ret << endl;
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
