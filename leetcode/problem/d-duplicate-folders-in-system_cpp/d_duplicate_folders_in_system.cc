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

struct PrefixTree {
    string val;
    bool isDeleted;
    bool isEnd;
    map<string, PrefixTree*> children;
    
    PrefixTree(string inputVal) : val(inputVal), isDeleted(false), isEnd(false) {
        children.clear();
    }
};

class Solution {
public:
    string dfs(PrefixTree* node, unordered_map<string, PrefixTree*>& distinct) {
        int idx = 0;
        string curr = "";
        for (auto& p : node->children) {
            curr += "(" + to_string(idx) + ")" + p.first + dfs(p.second, distinct) + "|";
        }
        if (curr == "") return curr;
        if (distinct[curr] != nullptr) {
            node->isDeleted = true;
            distinct[curr]->isDeleted = true;
        } else {
            distinct[curr] = node; 
        }
        return curr;
    }

    bool isEmpty(PrefixTree* node) {
        if (node->children.size() == 0) return true;
        for (auto& p : node->children) {
            if (p.second->isDeleted) continue;
            return false;
        }
        return true;
    }

    void getResult(vector<vector<string>>& result, vector<string>& curr, PrefixTree* root) {
        if (isEmpty(root)) {
            if (curr.size()) result.push_back(curr);
            return;
        }
        if (root->isEnd && curr.size()) result.push_back(curr);
        for (auto& p : root->children) {
            if (p.second->isDeleted) continue;
            curr.push_back(p.first);
            getResult(result, curr, p.second);
            curr.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        PrefixTree* root = new PrefixTree("#"); 
        for (auto& p : paths) {
            PrefixTree* thru = root;
            for (auto& folder : p) {
                if (thru->children.find(folder) == thru->children.end()) {
                    thru->children[folder] = new PrefixTree(folder);
                }
                thru = thru->children[folder];
                thru->isEnd = true;
            }
        }

        unordered_map<string, PrefixTree*> distinct;
        dfs(root, distinct);

        vector<string> curr;
        vector<vector<string>> result;
        getResult(result, curr, root);
        return result;
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
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
    test_example_4(_sol);
}
