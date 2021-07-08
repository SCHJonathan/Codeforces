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
    ull initHash(string& s, int size) {
        ull result = 0;
        for (int i = 0; i < size; i++) {
            result = ((result*26)%RANGE)+(s[i]-'a');
            result %= RANGE;
        }
        return result;
    }

    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int pow[n]; pow[0] = 1;
        for (int i = 1; i < n; i++) pow[i] = (pow[i-1]*26)%RANGE;
        for (int size = n-1; size >= 1; size--) {
            unordered_set<ull> visited;
            ull hash = initHash(s, size);
            // string startStr = s.substr(0,size);
            // debug(startStr, hash);
            visited.insert(hash);
            for (int i = size; i < n; i++) {
                ull newHash = (hash-(s[i-size]-'a')*pow[size-1]+RANGE)%RANGE;
                newHash = (newHash*26+(s[i]-'a'))%RANGE;
                // string str = s.substr(i-size+1, size);
                // debug(str, newHash);
                if (visited.count(newHash)) return size;
                hash = newHash;
                visited.insert(newHash);
            }
        }
        return 0;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "abcd";
    int _ret_ans = 0;
    int _ret = _sol.longestRepeatingSubstring(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    string s = "abbaba";
    int _ret_ans = 2;
    int _ret = _sol.longestRepeatingSubstring(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    string s = "aabcaabdaab";
    int _ret_ans = 3;
    int _ret = _sol.longestRepeatingSubstring(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_3(Solution &_sol) {
    string s = "aaaaa";
    int _ret_ans = 4;
    int _ret = _sol.longestRepeatingSubstring(s);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
