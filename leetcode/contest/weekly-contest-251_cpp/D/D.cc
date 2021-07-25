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

struct SuffixTreeNode {
    int count;
    bool deleted;
    unordered_map<string, SuffixTreeNode*> children;
    SuffixTreeNode() {
        count = 0;
        deleted = false;
        children.clear();
    }    
};

// struct PrefixTreeNode {

//     unordered_map<string, vector<PrefixTreeNode*>> children;
//     PrefixTreeNode() {
//         children.clear();
//     }
// };

class Solution {
public:
    void dfs(SuffixTreeNode* node, vector<vector<string>>& res, vector<string>& curr) {
        if (node->children.size() == 0) {
            if (curr.size() > 0) {
                res.push_back(curr);
            }
            return;
        }
        debug(curr);
        for (auto [str, child] : node->children) {
            debug(str, child->count, child->deleted);
            if (!child->deleted) curr.push_back(str);
            dfs(child, res, curr);
            if (!child->deleted) curr.pop_back();
        }


    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        SuffixTreeNode* root = new SuffixTreeNode();
        for (auto& path : paths) {
            SuffixTreeNode* thru = root;
            for (int i = path.size()-1; i >= 0; i--) {
                string& folder = path[i];
                if (thru->children.find(folder) == thru->children.end()) {
                    thru->children[folder] = new SuffixTreeNode();
                }
                thru = thru->children[folder];
                thru->count++;
            }
            for (int i = path.size()-1; i >= 0; i--) {
                string& folder = path[i];
                if (thru->children.find(folder) == thru->children.end()) {
                    thru->children[folder] = new SuffixTreeNode();
                }
                thru = thru->children[folder];
                thru->count++;
            }
        }
        // delete
        queue<pair<SuffixTreeNode*, SuffixTreeNode*>> q;
        q.push({nullptr, root});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [parent, curr] = q.front(); q.pop();
                if (curr->count > 1 || (parent && parent->count > 1)) curr->deleted = true;
                for (auto& pair : curr->children) {
                    q.push({curr, pair.second});
                }
            }
        }
        vector<string> curr;
        vector<vector<string>> res;
        dfs(root, res, curr);
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<string>> paths = {{"a"}, {"c"}, {"d"}, {"a", "b"}, {"c", "b"}, {"d", "a"}};
    vector<vector<string>> _ret_ans = {{"d"}, {"d", "a"}};
    vector<vector<string>> _ret = _sol.deleteDuplicateFolder(paths);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<string>> paths = {{"a"}, {"c"}, {"a", "b"}, {"c", "b"}, {"a", "b", "x"}, {"a", "b", "x", "y"}, {"w"}, {"w", "y"}};
    vector<vector<string>> _ret_ans = {{"c"}, {"c", "b"}, {"a"}, {"a", "b"}};
    vector<vector<string>> _ret = _sol.deleteDuplicateFolder(paths);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<string>> paths = {{"a", "b"}, {"c", "d"}, {"c"}, {"a"}};
    vector<vector<string>> _ret_ans = {{"c"}, {"c", "d"}, {"a"}, {"a", "b"}};
    vector<vector<string>> _ret = _sol.deleteDuplicateFolder(paths);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<vector<string>> paths = {{"a"}, {"a", "x"}, {"a", "x", "y"}, {"a", "z"}, {"b"}, {"b", "x"}, {"b", "x", "y"}, {"b", "z"}};
    vector<vector<string>> _ret_ans = {};
    vector<vector<string>> _ret = _sol.deleteDuplicateFolder(paths);
    test("Example - 3", _ret_ans, _ret);
}


void test_example_4(Solution &_sol) {
    vector<vector<string>> paths = {{"a"}, {"a", "x"}, {"a", "x", "y"}, {"a", "z"}, {"b"}, {"b", "x"}, {"b", "x", "y"}, {"b", "z"}, {"b", "w"}};
    vector<vector<string>> _ret_ans = {{"b"}, {"b", "w"}, {"b", "z"}, {"a"}, {"a", "z"}};
    vector<vector<string>> _ret = _sol.deleteDuplicateFolder(paths);
    test("Example - 4", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    // test_example_3(_sol);
    // test_example_4(_sol);
}
