
#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <vector>
#include "_boilerplate.hpp"

template <typename T>
void print(const T &x) { std::cerr << x; }

template <typename T>
void print(const std::vector<T> &vec) {
    std::cerr << "{";
    for (int i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cerr << ", ";
        print(vec[i]);
    }
    std::cerr << "}";
}

void print(ListNode* node) {
    std::cerr << "{";
    for (ListNode* thru = node; thru; thru = thru->next) {
        std::cerr << thru->val;
        if (thru->next) std::cerr << " -> ";
    }
    std::cerr << "}";
}

template <>
void print(const bool &x) { std::cerr << (x ? "true" : "false"); }

template <typename T>
inline bool _test(const T &a, const T &b) {
    return a == b;
}

template <typename T>
inline bool _test(const std::vector<T> &a, const std::vector<T> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i)
        if (!_test(a[i], b[i])) return false;
    return true;
}

template <typename T>
inline void test(const char *msg, const T &a, const T &b) {
    if (_test(a, b)) {
        std::cerr << msg << "\033[1;32m [OK]\033[0m" << std::endl;
        std::cerr << "Expected: ";
        print(a);
        std::cerr << std::endl << "Received: ";
        print(b);
        std::cerr << std::endl;
    } else {
        std::cerr << msg << "\033[1;31m [WRONG]\033[0m" << std::endl;
        std::cerr << "Expected: ";
        print(a);
        std::cerr << std::endl << "Received: ";
        print(b);
        std::cerr << std::endl;
    }
}

#endif  // TESTING_H
