#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <vector>
#include "_boilerplate.hpp"

template <typename T>
void print(const T &x) { std::cout << x; }

template <typename T>
void print(const std::vector<T> &vec) {
    std::cout << "{";
    for (int i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cout << ", ";
        print(vec[i]);
    }
    std::cout << "}";
}

void print(ListNode* node) {
    std::cout << "{";
    for (ListNode* thru = node; thru; thru = thru->next) {
        std::cout << thru->val;
        if (thru->next) std::cout << " -> ";
    }
    std::cout << "}";
}

template <>
void print(const bool &x) { std::cout << (x ? "true" : "false"); }

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
        std::cout << msg << "\033[1;31m [OK]\033[0m" << std::endl;
        std::cout << "Expected: ";
        print(a);
        std::cout << std::endl << "Received: ";
        print(b);
        std::cout << std::endl;
    } else {
        std::cout << msg << "\033[1;31m [WRONG]\033[0m" << std::endl;
        std::cout << "Expected: ";
        print(a);
        std::cout << std::endl << "Received: ";
        print(b);
        std::cout << std::endl;
    }
}

#endif  // TESTING_H
