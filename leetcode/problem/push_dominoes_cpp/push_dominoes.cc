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
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        bool stand[n]; memset(stand, 0, sizeof(stand));
        int left = -1, right = -1;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') continue;
            if (dominoes[i] == 'R') right = i;
            if (dominoes[i] == 'L') {
                left = i;
                if (right != -1) {
                    int rr = right, leftl = i;
                    while (rr <= leftl) {
                        if (rr == leftl) {
                            stand[rr] = true;
                        } else {
                            dominoes[rr] = 'R';
                            dominoes[leftl] = 'L';                            
                        }

                        leftl--; rr++;
                    }
                    right = -1;
                }
                // if (right != -1 && right < left && (left-right-1) % 2 == 1 &&
                //     dominoes[right+(left-right)/2] == '.') {
                //     stand[right+(left-right)/2] = true;
                //     right = -1;
                // }
            }
        }

        for (int i = 1; i < n; i++) {
            if (dominoes[i] == '.' && dominoes[i-1] == 'R' && !stand[i]) {
                dominoes[i] = 'R';
            }
        }

        for (int i = n-2; i >= 0; i--) {
            if (dominoes[i] == '.' && dominoes[i+1] == 'L' && !stand[i]) {
                dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string dominoes = "RR.L";
    string _ret_ans = "RR.L";
    string _ret = _sol.pushDominoes(dominoes);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string dominoes = ".L.R...LR..L..";
    string _ret_ans = "LL.RR.LLRRLL..";
    string _ret = _sol.pushDominoes(dominoes);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
