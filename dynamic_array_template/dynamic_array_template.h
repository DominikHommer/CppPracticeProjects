// dynamic_array_template.h
#ifndef DYNAMIC_ARRAY_TEMPLATE_H
#define DYNAMIC_ARRAY_TEMPLATE_H

#include <iostream>
#include <cassert>

template<typename T>
class dynamic_array {
    int len = 0;
    T *data = nullptr;
public:
    dynamic_array();
    explicit dynamic_array(int n);
    dynamic_array(const dynamic_array &other);
    dynamic_array& operator=(const dynamic_array &other);
    dynamic_array(dynamic_array &&other) noexcept;
    dynamic_array& operator=(dynamic_array &&other) noexcept;
    ~dynamic_array();

    void append(T value);
    int size() const;

    T& operator[](int i) const;
    friend std::ostream& operator<<(std::ostream &os, const dynamic_array<T> &d) {
        for(int i = 0; i < d.len; i++) {
            os << d.data[i] << (i < d.len - 1 ? ", " : "");
        }
        return os;
    }
};

#include "dynamic_array_template.tpp"

#endif // DYNAMIC_ARRAY_TEMPLATE_H

