//
// Created by admin on 13.05.2020.
//

#ifndef CLASS_D_EXEPCTION_H
#define CLASS_D_EXEPCTION_H



template<typename T>
class Element {
public:
    T value;
    Element<T> *next;

    Element() : next(nullptr) {}

    Element(T v) : value(v), next(nullptr) {}

    Element(T v, Element<T> *n) : value(v), next(n) {}
};

class Exception : public runtime_error {
public:
    Exception() : runtime_error("segmentation_fault") {
    }
};

#endif //CLASS_D_EXEPCTION_H
