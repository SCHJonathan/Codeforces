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

    string addition(string& s, int a) {
        int n = s.size();
        string result(n, 'a');
        for (int i = 0; i < n; i++) {
            if (i%2 == 0) result[i] = s[i]; 
            else result[i] = ((s[i]-'0'+a)%10)+'0'; 
        }
        return result;
    }

    string rotation(string& s, int b) {
        int n = s.size();
        return s.substr(n-1-b+1, b)+s.substr(0, n-b);
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        set<string> combinations;
        combinations.insert(s); q.push(s); 
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            string additionRes = addition(curr, a);
            string rotationRes = rotation(curr, b);
            debug(curr, additionRes, a, rotationRes, b);
            if (combinations.count(additionRes) == 0) {
                combinations.insert(additionRes);
                q.push(additionRes);
            }
            if (combinations.count(rotationRes) == 0) {
                combinations.insert(rotationRes);
                q.push(rotationRes);
            }
        }
        return *combinations.begin();
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    string s = "5525";
    int a = 9;
    int b = 2;
    string _ret_ans = "2050";
    string _ret = _sol.findLexSmallestString(s, a, b);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string s = "74";
    int a = 5;
    int b = 1;
    string _ret_ans = "24";
    string _ret = _sol.findLexSmallestString(s, a, b);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    string s = "0011";
    int a = 4;
    int b = 2;
    string _ret_ans = "0011";
    string _ret = _sol.findLexSmallestString(s, a, b);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    string s = "43987654";
    int a = 7;
    int b = 3;
    string _ret_ans = "00553311";
    string _ret = _sol.findLexSmallestString(s, a, b);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
