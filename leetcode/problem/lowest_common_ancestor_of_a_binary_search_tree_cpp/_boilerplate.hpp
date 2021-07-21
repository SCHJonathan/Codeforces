#include <algorithm>
#include <bitset>
#include <complex>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include <cmath>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() {
        if (left != NULL) delete left;
        if (right != NULL) delete right;
    }
};

const int NONE = INT_MIN;

TreeNode *_construct_tree(const vector<int> &parent) {
    queue<TreeNode *> q;
    int ptr = 0;

    auto _add_node = [&]() -> TreeNode * {
        if (ptr >= parent.size()) return nullptr;
        int val = parent[ptr++];
        if (val == NONE) return nullptr;
        auto *p = new TreeNode(val);
        q.push(p);
        return p;
    };

    TreeNode *root = _add_node();
    while (!q.empty()) {
        if (ptr >= parent.size()) break;
        TreeNode *p = q.front();
        q.pop();
        p->left = _add_node();
        p->right = _add_node();
    }
    return root;
}
