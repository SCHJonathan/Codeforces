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
    void printPq(priority_queue<vint, vector<vint>, greater<vint>> pq) {
        cout << "[";
        while (!pq.empty()) {
            cout << "{"<< pq.top()[0] << ", " << pq.top()[1] << "}, ";
            pq.pop();
        }
        cout << "]" << endl;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // vector<vint> times;
        // for (int i = 0; i < timesOriginal.size(); i++) {
        //     if (i == targetFriend) continue;
        //     auto& v = timesOriginal[i];
        //     // {start, end, friend}
        //     times.push_back({v[0], v[1], i});
        // }
        vint target = times[targetFriend];
        sort(times.begin(), times.end());

        // vint target = {timesOriginal[targetFriend][0], timesOriginal[targetFriend][1], targetFriend};
        // auto targetIterator = lower_bound(times.begin(), times.end(), target);

        int maxChair = 0; priority_queue<int, vint, greater<int>> chair;
        // {finishedTime, chairNumber} finishedTime then, chairNumber
        priority_queue<vint, vector<vint>, greater<vint>> pq; 
        for (auto it = times.begin(); it != times.end(); ++it) {
            // push all the available chair
            vint time = *it;
            int start = time[0], end = time[1];
            // if (pq.empty()) {debug(chair);}
            // else {printPq(pq); debug(chair);}
            while (!pq.empty() && pq.top()[0] <= start) {
                chair.push(pq.top()[1]);
                pq.pop();
            }
            if (chair.empty()) chair.push(maxChair);
            int chairSelected = chair.top(); chair.pop();
            maxChair = max(maxChair, chairSelected+1);
            debug(time, chairSelected, maxChair);
            if (time == target) return chairSelected;
            else pq.push({end, chairSelected});
        }
        return -1;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend = 1;
    int _ret_ans = 1;
    int _ret = _sol.smallestChair(times, targetFriend);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> times = {{3, 10}, {1, 5}, {2, 6}};
    int targetFriend = 0;
    int _ret_ans = 2;
    int _ret = _sol.smallestChair(times, targetFriend);
    test("Example - 1", _ret_ans, _ret);
}

void test_example_2(Solution &_sol) {
    vector<vector<int>> times = {{33889,98676},{80071,89737},{44118,52565},{52992,84310},{78492,88209},{21695,67063},{84622,95452},{98048,98856},{98411,99433},{55333,56548},{65375,88566},{55011,62821},{48548,48656},{87396,94825},{55273,81868},{75629,91467}};
    int targetFriend = 6;
    int _ret_ans = 2;
    int _ret = _sol.smallestChair(times, targetFriend);
    test("Example - 1", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    test_example_2(_sol);
}
