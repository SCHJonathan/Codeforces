// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
#else
#define debug(x...)
#endif

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

const int RANGE = 1e9+7;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        set<pint> order;
        unordered_set<int> todo;
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) idx[org[i]] = i, todo.insert(org[i]);
        for (int i = 1; i < n; i++) order.insert({org[i-1], org[i]});

        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] < 1 || seq[i] > n) return false;
                if (todo.count(seq[i])) todo.erase(todo.find(seq[i]));
                if (i > 0 && idx[seq[i-1]] >= idx[seq[i]]) return false;
                if (i > 0 && order.count({seq[i-1], seq[i]})) order.erase(order.find({seq[i-1], seq[i]}));
            }
        }
        return order.empty() && todo.empty();
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}, {1, 3}};
    bool _ret_ans = false;
    bool _ret = _sol.sequenceReconstruction(org, seqs);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}};
    bool _ret_ans = false;
    bool _ret = _sol.sequenceReconstruction(org, seqs);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<int> org = {1, 2, 3};
    vector<vector<int>> seqs = {{1, 2}, {1, 3}, {2, 3}};
    bool _ret_ans = true;
    bool _ret = _sol.sequenceReconstruction(org, seqs);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<int> org = {4, 1, 5, 2, 6, 3};
    vector<vector<int>> seqs = {{5, 2, 6, 3}, {4, 1, 5, 2}};
    bool _ret_ans = true;
    bool _ret = _sol.sequenceReconstruction(org, seqs);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
