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
    pair<string, double> find(unordered_map<string, double>& weight, 
                              unordered_map<string, string>& disjointSet,
                              string x) {
        if (disjointSet[x] != x) {
            auto [parent, aggregateWeight] = find(weight, disjointSet, disjointSet[x]);
            disjointSet[x] = parent;
            // debug(x, parent, weight[x], aggregateWeight);
            weight[x] *= aggregateWeight;
        }
        return {disjointSet[x], weight[x]};
    }
    
    void unionSet(unordered_map<string, double>& weight, 
                  unordered_map<string, string>& disjointSet,
                  string x, string y, double value) {
        x = find(weight, disjointSet, x).first;
        y = find(weight, disjointSet, y).first;
        if (x == y) return;
        disjointSet[x] = y;
        weight[x] *= value;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double> weight;
        unordered_map<string, string> disjointSet;
        
        for (auto& equation : equations) {
            string divident = equation[0], divisor = equation[1];
            disjointSet[divident] = divident;
            disjointSet[divisor] = divisor;
            weight[divident] = 1.0;
            weight[divisor] = 1.0;
        }
        
        for (int i = 0; i < equations.size(); i++) {
            double quotient = values[i];
            string divident = equations[i][0], divisor = equations[i][1];
            weight[divident] *= quotient;
            unionSet(weight, disjointSet, divident, divisor, quotient);
        }
        debug(equations, values);
        for (auto& [x, y] : weight) {
            // debug(x);
            find(weight, disjointSet, x);
        }
        debug(weight);
        vector<double> result;
        for (auto& query : queries) {
            string divident = query[0], divisor = query[1];
            if (disjointSet.find(divident) == disjointSet.end() ||
                disjointSet.find(divisor) == disjointSet.end() ||
                find(weight, disjointSet, divident).first != find(weight, disjointSet, divisor).first) {
                debug(query, weight[divident], weight[divisor]);
                result.push_back(-1.0);
            } else {
                double dividentWeight = find(weight, disjointSet, divident).second;
                double divisorWeight = find(weight, disjointSet, divisor).second;
                debug(query, weight[divident], weight[divisor]);
                // result.push_back(weight[divident]/weight[divisor]);
                result.push_back(dividentWeight/divisorWeight);
            }
        }
        return result;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> _ret_ans = {6.0, 0.5, -1.0, 1.0, -1.0};
    vector<double> _ret = _sol.calcEquation(equations, values, queries);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    vector<double> _ret_ans = {3.75, 0.4, 5.0, 0.2};
    vector<double> _ret = _sol.calcEquation(equations, values, queries);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<string>> equations = {{"a", "b"}};
    vector<double> values = {0.5};
    vector<vector<string>> queries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    vector<double> _ret_ans = {0.5, 2.0, -1.0, -1.0};
    vector<double> _ret = _sol.calcEquation(equations, values, queries);
    test("Example - 2", _ret_ans, _ret);
}

void test_example_3(Solution &_sol) {
    /*
    {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}}
    {3.0,4.0,5.0,6.0}
    {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}}
    */
    vector<vector<string>> equations = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
    vector<double> values = {3.0,4.0,5.0,6.0};
    vector<vector<string>> queries = {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
    vector<double> _ret_ans = {360.00000,0.00833,20.00000,1.00000,-1.00000,-1.00000};
    vector<double> _ret = _sol.calcEquation(equations, values, queries);
    test("Example - 3", _ret_ans, _ret);
}

void test_example_4(Solution &_sol) {
    /*
    {{"a","b"},{"e","f"},{"b","e"}}
    {3.4,1.4,2.3}
    {{"b","a"},{"a","f"},{"f","f"},{"e","e"},{"c","c"},{"a","c"},{"f","e"}}
    {0.29412,10.94800,1.00000,1.00000,-1.00000,-1.00000,0.71429}
    */
    vector<vector<string>> equations = {{"a","b"},{"e","f"},{"b","e"}};
    vector<double> values = {3.4,1.4,2.3};
    vector<vector<string>> queries = {{"b","a"},{"a","f"},{"f","f"},{"e","e"},{"c","c"},{"a","c"},{"f","e"}};
    vector<double> _ret_ans = {0.29412,10.94800,1.00000,1.00000,-1.00000,-1.00000,0.71429};
    vector<double> _ret = _sol.calcEquation(equations, values, queries);
    test("Example - 4", _ret_ans, _ret);
}


void test_example_5(Solution &_sol) {
    /*
    {{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}}
    {3.0,0.5,3.4,5.6}
    {{"x2","x4"},{"x1","x5"},{"x1","x3"},{"x5","x5"},{"x5","x1"},{"x3","x4"},{"x4","x3"},{"x6","x6"},{"x0","x0"}}
    {1.13333,16.80000,1.50000,1.00000,0.05952,2.26667,0.44118,-1.00000,-1.00000}
    */
    vector<vector<string>> equations = {{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double> values = {3.0,0.5,3.4,5.6};
    vector<vector<string>> queries = {{"x2","x4"},{"x1","x5"},{"x1","x3"},{"x5","x5"},{"x5","x1"},{"x3","x4"},{"x4","x3"},{"x6","x6"},{"x0","x0"}};
    vector<double> _ret_ans = {1.13333,16.80000,1.50000,1.00000,0.05952,2.26667,0.44118,-1.00000,-1.00000};
    vector<double> _ret = _sol.calcEquation(equations, values, queries);
    test("Example - 5", _ret_ans, _ret);
}

int main() {
    Solution _sol;
    // test_example_0(_sol);
    // test_example_1(_sol);
    // test_example_2(_sol);
    // test_example_3(_sol);
    // test_example_4(_sol);
    test_example_5(_sol);
}
