//
// Created by admin on 13.05.2020.
//

#ifndef CLASS_D_LIST_UTILS_H
#define CLASS_D_LIST_UTILS_H

#include "List.h"
#include "List_Iterator.h"

template<typename T>
class Element {
private:
    T value;
    Element<T> *next;
public:
    Element() : next(nullptr) {}

    Element(T v) : value(v), next(nullptr) {}

    Element(T v, Element<T> *n) : value(v), next(n) {}

    template <typename U> friend class List_Iterator;
    template <typename U> friend class List;
};

class Exception : public runtime_error {
public:
    Exception() : runtime_error("segmentation_fault") {
    }
};

#endif //CLASS_D_LIST_UTILS_H
