// linked_list_template.h
#ifndef LINKED_LIST_TEMPLATE_H
#define LINKED_LIST_TEMPLATE_H

#include <iostream>
#include <cassert>

template<typename T>
class list {
    struct node {
        T value;
        node *next = nullptr;
        node();
        explicit node(const T &value);
        ~node();
    };
    node* head = nullptr;
public:
    list();
    explicit list(const T &content);
    list(const list<T> &other);
    list& operator=(const list<T> &other);
    list(list<T> &&other) noexcept;
    list& operator=(list<T> &&other) noexcept;
    ~list();

    void append(T value);
    void add_list(const list<T> &to_add);
    int size();
    T& value_at(int index);

    friend std::ostream& operator<<(std::ostream &os, const list<T> &l) {
        node *run = l.head;
        while(run) {
            os << run->value << (run->next ? ", " : "");
            run = run->next;
        }
        return os;
    }
};

#include "linked_list_template.tpp"

#endif // LINKED_LIST_TEMPLATE_H

