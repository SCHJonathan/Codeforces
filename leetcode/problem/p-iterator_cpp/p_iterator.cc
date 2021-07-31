// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
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


class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
 

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!q.size()) q.push(Iterator::next());
        return q.front();
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (q.size()) {
            int res = q.front(); q.pop();
            return res;
        }
        return Iterator::next();
    }
    
    bool hasNext() const {
        return Iterator::hasNext() || q.size();
    }
private:
    queue<int> q;    
};


// END SUBMIT

void test_example_0() {
    vector<int> PeekingIterator_nums;
    PeekingIterator_nums = {1, 2, 3};
    PeekingIterator _sol(PeekingIterator_nums);
    int _ret_ans1 = 1;
    int _ret1 = _sol.next();
    test("Example - 0 - Interaction 1", _ret_ans1, _ret1);
    int _ret_ans2 = 2;
    int _ret2 = _sol.peek();
    test("Example - 0 - Interaction 2", _ret_ans2, _ret2);
    int _ret_ans3 = 2;
    int _ret3 = _sol.next();
    test("Example - 0 - Interaction 3", _ret_ans3, _ret3);
    int _ret_ans4 = 3;
    int _ret4 = _sol.next();
    test("Example - 0 - Interaction 4", _ret_ans4, _ret4);
    bool _ret_ans5 = false;
    bool _ret5 = _sol.hasNext();
    test("Example - 0 - Interaction 5", _ret_ans5, _ret5);
}


int main() {
    test_example_0();
}
