//
// Created by admin on 13.05.2020.
//

#ifndef CLASS_D_LIST_ITERATOR_H
#define CLASS_D_LIST_ITERATOR_H

#include "List.h"
#include "Exepction.h"

template<typename T>
class List_Iterator {
public:
    Element<T> *p;
    using iterator_category = forward_iterator_tag;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using difference_type = ptrdiff_t;

    List_Iterator() : p(nullptr) {
    }

    List_Iterator(Element<T> *e) : p(e) {}

    T &operator*() const {
        if (p == nullptr)
            throw Exception();
        return p->value;
    }

    List_Iterator &operator++() {
        if (p == nullptr) {
            throw Exception();
        }
        p = p->next;
        return *this;
    }

    List_Iterator operator++(int) {
        p = p->next;
        return *this;
    }

    bool operator==(const List_Iterator &it) const {
        return p == it.p;
    }

    bool operator!=(const List_Iterator &it) const {
        return !(*this == it);
    }
};

#endif //CLASS_D_LIST_ITERATOR_H