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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pint> buy;
        priority_queue<pint, vector<pint>, greater<pint>> sell;

        for (auto& order : orders) {
            int amount = order[1], price = order[0];
            if (order[2] == 0) {
                // buy
                while (amount > 0 && !sell.empty() && sell.top().first <= price) {
                    if (amount >= sell.top().second) {
                        amount -= sell.top().second;
                        sell.pop();
                    } else {
                        auto top = sell.top(); sell.pop();
                        top.second -= amount;
                        sell.push(top);
                        amount = 0;
                    }
                }
                if (amount) buy.push({price, amount});
            } else {
                // sell
                while (amount > 0 && !buy.empty() && buy.top().first >= price) {
                    if (amount >= buy.top().second) {
                        amount -= buy.top().second;
                        buy.pop();
                    } else {
                        auto top = buy.top(); buy.pop();
                        top.second -= amount;
                        buy.push(top);
                        amount = 0;
                    }
                }
                if (amount) sell.push({price, amount});
            }
        }

        int res = 0;
        while (!buy.empty()) {
            res = (res+buy.top().second)%RANGE;
            buy.pop();
        }
        while (!sell.empty()) {
            res = (res+sell.top().second)%RANGE;
            sell.pop();
        }

        return res%RANGE;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> orders = {{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};
    int _ret_ans = 6;
    int _ret = _sol.getNumberOfBacklogOrders(orders);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> orders = {{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}};
    int _ret_ans = 999999984;
    int _ret = _sol.getNumberOfBacklogOrders(orders);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

void test_example_2(Solution &_sol) {
    vector<vector<int>> orders = {{23,8,0},{28,29,1},{11,30,1},{30,25,0},{26,9,0},{3,21,0},{28,19,1},{19,30,0},{20,9,1},{17,6,0}};
    int _ret_ans = 102;
    int _ret = _sol.getNumberOfBacklogOrders(orders);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}

int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
