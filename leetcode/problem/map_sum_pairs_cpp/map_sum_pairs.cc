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

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieTreeNode();
    }

    void insert(string key, int val) {
        TrieTreeNode* thru = root;
        for (char & c : key) {
            if (thru->children[c-'a'] == nullptr) {
                thru->children[c-'a'] = new TrieTreeNode();
            }
            thru = thru->children[c-'a'];
        }
        int propogateValue = val-thru->value;
        thru->value = val;
        thru = root;
        for (char & c : key) {
            thru->sum += propogateValue;
            thru = thru->children[c-'a'];
        }
        thru->sum += propogateValue;
    }
    
    int sum(string prefix) {
        TrieTreeNode* thru = root;
        for (char & c : prefix) {
            if (thru->children[c-'a'] == nullptr) {
                thru->children[c-'a'] = new TrieTreeNode();
            }
            thru = thru->children[c-'a'];
        }
        return thru->sum;
    }

private:
    struct TrieTreeNode {
        int sum;
        int value;
        TrieTreeNode* children[26];
        TrieTreeNode() {
            sum = 0;
            value = 0;
            memset(children, 0, sizeof(children));
        }
    };

    TrieTreeNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// END SUBMIT

void test_example_0() {
    string insert_key, sum_prefix;
    int insert_val;
    MapSum _sol;
    insert_key = "apple";
    insert_val = 3;
    _sol.insert(insert_key, insert_val);
    sum_prefix = "ap";
    int _ret_ans2 = 3;
    int _ret2 = _sol.sum(sum_prefix);
    test("Example - 0 - Interaction 2", _ret_ans2, _ret2);
    insert_key = "app";
    insert_val = 2;
    _sol.insert(insert_key, insert_val);
    sum_prefix = "ap";
    int _ret_ans4 = 5;
    int _ret4 = _sol.sum(sum_prefix);
    test("Example - 0 - Interaction 4", _ret_ans4, _ret4);
}


int main() {
    test_example_0();
}
