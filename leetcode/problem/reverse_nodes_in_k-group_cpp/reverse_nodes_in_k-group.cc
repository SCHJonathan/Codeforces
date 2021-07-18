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
#include "_boilerplate.hpp"
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* startPrev, int k) {
        assert(startPrev->next != nullptr);
        
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* start = startPrev->next;
        ListNode* node = start;
        
        for (int i = 0; i < k; i++) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        startPrev->next = prev;
        start->next = next;
        return start;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        for (ListNode* thru = head; thru; thru = thru->next) length++;

        ListNode* dummy = new ListNode(-1); dummy->next = head;
        ListNode* start = dummy;
        for (int i = 0; i <= length-k; i += k) {
            start = reverse(start, k);
        }
        return dummy->next;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    ListNode* head = {1, 2, 3, 4, 5};
    int k = 2;
    ListNode* _ret_ans = {2, 1, 4, 3, 5};
    ListNode* _ret = _sol.reverseKGroup(head, k);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    ListNode* head = {1, 2, 3, 4, 5};
    int k = 3;
    ListNode* _ret_ans = {3, 2, 1, 4, 5};
    ListNode* _ret = _sol.reverseKGroup(head, k);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    ListNode* head = {1, 2, 3, 4, 5};
    int k = 1;
    ListNode* _ret_ans = {1, 2, 3, 4, 5};
    ListNode* _ret = _sol.reverseKGroup(head, k);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    ListNode* head = {1};
    int k = 1;
    ListNode* _ret_ans = {1};
    ListNode* _ret = _sol.reverseKGroup(head, k);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
