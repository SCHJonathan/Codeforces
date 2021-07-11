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

const ll RANGE = 1e10+7;

class Solution {
public:
    ll getHash(vector<int>& path, int size, int n) {
        ll res = 0;
        for (int i = 0; i < size; i++) {
            res = (res*n%RANGE+path[i])%RANGE;
        }
        return res;
    }

    bool hasCommonPath(vector<vector<int>>& paths, 
                       unordered_map<ll, int>& visited, 
                       ll* pow,
                       int size,
                       int n) {
        debug(paths, size, n);
        visited.clear();
        unordered_map<int, int> count;
        // path 1 rolling hash
        ll hash = 0;
        for (int i = size-1; i < paths[0].size(); i++) {
            if (i == size-1) hash = getHash(paths[0], size, n);
            else {
                hash = (hash-(pow[size-1]*paths[0][i-size]%RANGE)+RANGE)%RANGE;
                hash = (hash*n%RANGE+paths[0][i])%RANGE;
            }
            visited[hash] = i-size+1;
        }
        debug(visited);

        // other path rolling hash
        for (int idx = 1; idx < paths.size(); idx++) {
            vector<int>& path = paths[idx];
            debug(path);
            unordered_set<ll> incremented;
            for (int i = size-1; i < path.size(); i++) {
                if (i == size-1) hash = getHash(path, size, n);
                else {
                    hash = (hash-(pow[size-1]*path[i-size]%RANGE)+RANGE)%RANGE;
                    hash = (hash*n%RANGE+path[i])%RANGE;
                }
                if (visited.find(hash) != visited.end() && incremented.count(hash) == 0) {
                    int start = i-size+1;
                    debug(hash, start);
                    // verify
                    bool valid = true;
                    int idx1 = visited[hash], idx2 = start;
                    for (int j = 0; j < size; j++, idx1++, idx2++) {
                        if (idx1 == paths[0].size() || idx2 == path.size() ||
                            paths[0][idx1] != path[idx2]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        count[visited[hash]]++;
                        incremented.insert(hash);
                    } else {
                        debug("not valid");
                    }
                }
            }
        }
        debug(count);
        for (auto& pair : count) {
            if (pair.second == paths.size()-1) {
                return true;
            }
        }
        return false;
    }


    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int minlen = INT_MAX;
        for (auto& v : paths) minlen = min(minlen, (int)v.size());
        ll pow[minlen]; memset(pow, 0, sizeof(pow)); pow[0] = 1;
        for (int i = 1; i < minlen; i++) pow[i] = pow[i-1]*n%RANGE;

        unordered_map<ll, int> visited;

        int left = 1, right = minlen;
        while (left <= right) {
            int mid = left+(right-left)/2;
            bool ans = hasCommonPath(paths, visited, pow, mid, n);
            if (ans) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    int n = 5;
    vector<vector<int>> paths = {{0, 1, 2, 3, 4}, {2, 3, 4}, {4, 0, 1, 2, 3}};
    int _ret_ans = 2;
    int _ret = _sol.longestCommonSubpath(n, paths);
    cout << "Expected: " << _ret_ans <<  " My Answer: " << _ret << endl;
}


void test_example_1(Solution &_sol) {
    int n = 3;
    vector<vector<int>> paths = {{0}, {1}, {2}};
    int _ret_ans = 0;
    int _ret = _sol.longestCommonSubpath(n, paths);
    cout << "Expected: " << _ret_ans <<  " My Answer: " << _ret << endl;
}


void test_example_2(Solution &_sol) {
    int n = 5;
    vector<vector<int>> paths = {{0, 1, 2, 3, 4}, {4, 3, 2, 1, 0}};
    int _ret_ans = 1;
    int _ret = _sol.longestCommonSubpath(n, paths);
    cout << "Expected: " << _ret_ans <<  " My Answer: " << _ret << endl;
}

void test_example_3(Solution &_sol) {
    int n = 3;
    vector<vector<int>> paths = {{0,1,0,1,0,1,0,1,0,1,0,1},{0,1,2,0,1,2,0,1,2}};
    int _ret_ans = 2;
    int _ret = _sol.longestCommonSubpath(n, paths);
    cout << "Expected: " << _ret_ans <<  " My Answer: " << _ret << endl;
}

void test_example_4(Solution &_sol) {
    int n = 3;
    vector<vector<int>> paths = {{1,2,0,1},{2,0},{2,0},{1,2},{0,1,0}};
    int _ret_ans = 0;
    int _ret = _sol.longestCommonSubpath(n, paths);
    cout << "Expected: " << _ret_ans <<  " My Answer: " << _ret << endl;
}


int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    // test_example_3(_sol);
    test_example_4(_sol);
}
