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
const ll RANGE_LL = 1e12+7;

class Solution {
public:
    ll getHash(string& s) {
        ll res = 0;
        for (char& c : s) {
            res = res*26%RANGE_LL+(c-'a');
            res %= RANGE_LL;
        }
        return res;
    }

    bool differByOne(vector<string>& dict) {
        // debug(dict);
        unordered_set<ll> visited;

        int maxlen = 0;
        for (string&s : dict) 
            maxlen = max(maxlen, (int)s.size());
        ll pow[maxlen]; memset(pow, 0, sizeof(pow)); pow[0] = 1;
        for (int i = 1; i < maxlen; i++)
            pow[i] = pow[i-1]*26%RANGE_LL;

        for (string& s : dict) {
            int n = s.size();
            ll hash = getHash(s);
            for (int i = n-1; i >= 0; i--) {
                ll base = (hash-((s[i]-'a')*pow[n-1-i]%RANGE_LL)+RANGE_LL)%RANGE_LL;
                for (int j = 0; j < 26; j++) {
                    if (j == s[i]-'a') continue;
                    
                    ll newHash = (base+(j*pow[n-1-i]%RANGE_LL))%RANGE_LL;
                    if (visited.count(newHash)) {
                        // string curr = s;
                        // curr[i] = (char)(j+'a');
                        // debug(newHash, curr);
                        return true;
                    }
                }
            }
            // debug(hash, s);
            visited.insert(hash);
        }

        return false;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<string> dict = {"abcd", "acbd", "aacd"};
    bool _ret_ans = true;
    bool _ret = _sol.differByOne(dict);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<string> dict = {"ab", "cd", "yz"};
    bool _ret_ans = false;
    bool _ret = _sol.differByOne(dict);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<string> dict = {"abcd", "cccc", "abyd", "abab"};
    bool _ret_ans = true;
    bool _ret = _sol.differByOne(dict);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
