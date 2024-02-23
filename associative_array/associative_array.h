// associative_array.h
#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRAY_H

#include <vector>
#include <iostream>
#include <utility>
#include <cassert>
#include <stdexcept>

template<typename S, typename I>
class associative_array {
    struct pair {
        S name;
        I mat;
        pair(const S& n, const I& m) : name(n), mat(m) {}
    };
    std::vector<pair> vec;
public:
    associative_array();
    I& operator[](const S &key);
    const I& operator[](const S &key) const;
};

#include "associative_array.tpp"

#endif // ASSOCIATIVE_ARRAY_H

