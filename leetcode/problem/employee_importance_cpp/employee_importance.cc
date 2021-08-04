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

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int helper(int id, unordered_map<int, Employee*>& employeeMap) {
        Employee* employee = employeeMap[id];
        int res = employee->importance;
        for (auto& subordinateId : employee->subordinates) {
            res += helper(subordinateId, employeeMap);
        }
        return res;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeeMap;
        for (auto& e : employees) {
            employeeMap[e->id] = e;
        }
        return helper(id, employeeMap);
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<Employee*> employees = {{1, 5, {2, 3}}, {2, 3, {}}, {3, 3, {}}};
    int id = 1;
    int _ret_ans = 11;
    int _ret = _sol.getImportance(employees, id);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<Employee*> employees = {{1, 2, {5}}, {5, -3, {}}};
    int id = 5;
    int _ret_ans = -3;
    int _ret = _sol.getImportance(employees, id);
    test("Example - 1", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
}
