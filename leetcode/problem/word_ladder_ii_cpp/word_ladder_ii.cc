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

class Solution {
public:
    bool valid(string& a, string& b) {
        int differ = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) differ++;
            if (differ > 1) return false;
        }
        return true;
    }

    void generate(vector<unordered_set<int>>& revertList, 
                  vector<vector<string>>& result,
                  vector<string>& words, 
                  vector<string>& curr,
                  bool* visiting,
                  int idx, int step, int& beginIdx, int& steps) {
        curr.push_back(words[idx]);
        if (idx == beginIdx) {
            debug("in", curr);
            if (curr.size() == steps+1) result.push_back(curr);
            visiting[idx] = false;
            return;
        }
        debug(step, steps);
        if (step == steps+1) {
            visiting[idx] = false;
            return;
        }
        vector<int> reverts(revertList[idx].begin(), revertList[idx].end());
        debug(curr, reverts);
        for (auto i : reverts) {
            if (visiting[i]) continue;
            visiting[i] = true;
            generate(revertList, result, words, curr, visiting, i, step+1, beginIdx, steps);
            curr.pop_back();
        }
        visiting[idx] = false;
    }

    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        

        unordered_set<string> wordsSet(wordList.begin(), wordList.end());
        if (wordsSet.count(end) == 0) return {};
        wordsSet.insert(begin); wordsSet.insert(end);
        vector<string> words(wordsSet.begin(), wordsSet.end());

        int n = words.size();
        vector<vint> graph(n);

        vector<unordered_set<int>> revertList(n);
        debug(words, begin, end);
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (!valid(words[i], words[j])) continue;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
            // debug(words[i], begin, words[i] == begin);
            if (words[i] == begin) beginIdx = i;
            if (words[i] == end) endIdx = i;
        }

        bool finished = false; int resultSteps = -1, steps = 0;
        queue<int> q; q.push(beginIdx);
        bool visited[n]; memset(visited, 0, sizeof(visited)); visited[beginIdx] = true;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front(); q.pop();
                if (curr == endIdx) {
                    finished = true;
                    resultSteps = steps;
                    continue;
                }
                debug(curr, words[curr]);
                for (auto& neighbor : graph[curr]) {
                    revertList[neighbor].insert(curr);
                    if (visited[neighbor] || finished) continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
            steps++;
        }
        debug(revertList);
        vector<string> curr;
        vector<vector<string>> result;
        bool visiting[n]; memset(visiting, 0, sizeof(visiting));
        visiting[endIdx] = true;
        generate(revertList, result, words, curr, visiting, endIdx, 0, beginIdx, resultSteps);
        for (auto& v : result) {
            reverse(v.begin(), v.end());
        }
        return result;

    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> _ret_ans = {{"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}};
    vector<vector<string>> _ret = _sol.findLadders(beginWord, endWord, wordList);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    vector<vector<string>> _ret_ans = {};
    vector<vector<string>> _ret = _sol.findLadders(beginWord, endWord, wordList);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
