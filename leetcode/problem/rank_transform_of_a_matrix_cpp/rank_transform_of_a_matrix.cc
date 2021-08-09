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
    const int MAX_SIZE = 500;
    int find(unordered_map<int, int>& parent, int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void unionSet(unordered_map<int, int>& parent, int x, int y) {
        x = find(parent, x), y = find(parent, y);
        if (x == y) return;
        parent[x] = y;
    }

    unordered_map<int, vector<int>> getGroups(unordered_map<int, int>& parent) {
        unordered_map<int, vector<int>> res;
        for (auto& p : parent) {
            res[find(parent, p.first)].push_back(p.first);
        }
        return res;
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vint(n, 0));

        map<int, vector<pair<int, int>>> coordinate;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                coordinate[matrix[i][j]].push_back({i, j});
            }
        }

        vector<int> rowMax(m, 0);
        vector<int> colMax(n, 0);
        for (auto [_, group] : coordinate) {
            unordered_map<int, int> parent;
            for (auto [i, j] : group) {
                unionSet(parent, i, j+MAX_SIZE);
            }
            auto getGroupsRes = getGroups(parent);
            unordered_map<int, int> rankMap;
            for (auto [parentVal, indexGroup] : getGroupsRes) {
                int row = 0, col = 0;
                for (auto& idx : indexGroup) {
                    if (idx < MAX_SIZE) {
                        row = max(row, rowMax[idx]);
                    } else {
                        col = max(col, colMax[idx-MAX_SIZE]);
                    }
                }
                int rank = max(row, col)+1;
                rankMap[parentVal] = rank;
            }
            for (auto [i, j] : group) {
                int rank = rankMap[find(parent, i)];
                res[i][j] = rank;
                rowMax[i] = max(rowMax[i], rank);
                colMax[j] = max(colMax[j], rank);
            }
        }
        return res;
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> matrix = {{1, 2}, {3, 4}};
    vector<vector<int>> _ret_ans = {{1, 2}, {2, 3}};
    vector<vector<int>> _ret = _sol.matrixRankTransform(matrix);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> matrix = {{7, 7}, {7, 7}};
    vector<vector<int>> _ret_ans = {{1, 1}, {1, 1}};
    vector<vector<int>> _ret = _sol.matrixRankTransform(matrix);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> matrix = {{20, -21, 14}, {-19, 4, 19}, {22, -47, 24}, {-19, 4, 19}};
    vector<vector<int>> _ret_ans = {{4, 2, 3}, {1, 3, 4}, {5, 1, 6}, {1, 3, 4}};
    vector<vector<int>> _ret = _sol.matrixRankTransform(matrix);
    test("Example - 2", _ret_ans, _ret);
}


void test_example_3(Solution &_sol) {
    vector<vector<int>> matrix = {{7, 3, 6}, {1, 4, 5}, {9, 8, 2}};
    vector<vector<int>> _ret_ans = {{5, 1, 4}, {1, 2, 3}, {6, 3, 1}};
    vector<vector<int>> _ret = _sol.matrixRankTransform(matrix);
    test("Example - 3", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
