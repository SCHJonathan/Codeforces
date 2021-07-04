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
    bool checkValid(int curr) {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            count += curr & 1;
            curr >>= 1;
        }
        return count <= 1;
    }

    int get(unordered_map<int,int>& count, int x) {
        if (count.find(x) == count.end()) return 0;
        return count[x];
    }


    long long wonderfulSubstrings(string word) {
        int n = word.size();
        int curr = 0; ll result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            int x = (word[i]-'a');
            curr ^= (1<<x);
            if (checkValid(curr)) {
                result += 1+get(count, curr);
                for (int i = 0; i < 10; i++) {
                    int x = 1 << i;
                    int flip = curr^x;
                    if (get(count, flip)) {
                        debug(flip);
                    }
                    result += get(count, flip);
                }
            } else {
                for (int i = 0; i < 10; i++) {
                    int x = 1 << i;
                    int flip = curr^x;
                    result += get(count, flip);
                }
                result += get(count, curr);
            }
            debug(curr, count, result);
            count[curr]++;
        }
        return result;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string word = "aba";
    long long _ret_ans = 4;
    long long _ret = _sol.wonderfulSubstrings(word);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    string word = "aabb";
    long long _ret_ans = 9;
    long long _ret = _sol.wonderfulSubstrings(word);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    string word = "he";
    long long _ret_ans = 2;
    long long _ret = _sol.wonderfulSubstrings(word);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_3(Solution &_sol) {
    string word = "fiabhedce";
    long long _ret_ans = 9;
    long long _ret = _sol.wonderfulSubstrings(word);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_4(Solution &_sol) {
    string word = "fihhicigaaahcbgdabfbch";
    long long _ret_ans = 37;
    long long _ret = _sol.wonderfulSubstrings(word);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
    test_example_4(_sol);
}
