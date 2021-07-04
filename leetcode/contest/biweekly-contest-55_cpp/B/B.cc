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
    string toString(deque<pair<char,int>> dq) {
        string res = "";
        while (dq.size()) {
            res += dq.front().first;
            dq.pop_front();
        }
        return res;
    }

    int getIdx(string s, string part, int i, int j) {
        int res = 0;
        while (j >= 0) {
            int idx = i, idxj = j, counter = 0;
            while (idx >= 0 && s[idx] == part[idxj]) {
                idx--, idxj--;
                counter++;
            }
            j--;
            res = max(counter, res);
        }
        return res-1;
    }

    string removeOccurrences(string s, string part) {
        debug(part);
        deque<pair<char,int>> dq;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int prevIdx = dq.empty() ? -1 : dq.back().second;
            int currentIdx = (part[prevIdx+1] == c) ? prevIdx+1 : getIdx(s, part, i, prevIdx);
            if (currentIdx == part.size()-1) {
                dq.push_back({c, currentIdx});
                debug("before remove:");
                debug(toString(dq));
                while (currentIdx >= 0) {
                    dq.pop_back();
                    currentIdx--;
                }
                debug("after remove:");
                debug(toString(dq));
            } else {
                dq.push_back({c, currentIdx});
                // debug(toString(dq));
            }
        }
        string res = "";
        while (dq.size()) {
            res += dq.front().first;
            dq.pop_front();
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "daabcbaabcbc";
    string part = "abc";
    string _ret_ans = "dab";
    string _ret = _sol.removeOccurrences(s, part);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    string s = "axxxxyyyyb";
    string part = "xy";
    string _ret_ans = "ab";
    string _ret = _sol.removeOccurrences(s, part);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_2(Solution &_sol) {
    string s = "gjgjdsqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuotcmlqunczabsysvzdsqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuogjdsqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuotcmlqunczabsysgjdsqcjibhpskzgdwwhdcrzcyjfzvxgjdgjdsqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuotcmlqunczabsysvzsgjdsqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuotcmlqunczabsysvzqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuotcmlqunczabsysvzzbnkdtpjuotcmlqunczabsysvzvztcmlqunczabsysvzxmqgfeyfzzpnewyngwdshjxbevxdofqsexkdkwsbvtts";
    string part = "gjdsqcjibhpskzgdwwhdcrzcyjfzvxzbnkdtpjuotcmlqunczabsysvz";
    string _ret_ans = "xmqgfeyfzzpnewyngwdshjxbevxdofqsexkdkwsbvtts";
    string _ret = _sol.removeOccurrences(s, part);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    test_example_2(_sol);
}
