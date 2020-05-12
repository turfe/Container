//
// Created by admin on 07.05.2020.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "List_Iterator.h"
#include "Exepction.h"

using namespace std;


/*
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

template<typename T>
class List_Iterator {
private:
    Element<T> *p;
public:
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
};*/


template<typename T>
class Container {
public:
    // Виртуальный деструктор
    virtual ~Container() = default;

    // Вставка элемента
    virtual void insert(const T &value) = 0;

    // Удаление элемента
    virtual void remove(const T &value) = 0;

    // Проверка наличия элемента
    virtual bool exists(const T &value) const = 0;
};

template<typename T>
class List : public Container<T> {
private:
    Element<T> *root;

    void printer(struct Element<T> *root) {
        while (root != nullptr) {
            cout << root->value << endl;
            root = root->next;
        }
    };

    void delete_element(const T &value, Element<T> *root) {
        Element<T> *cur_elem, *pre_elem;
        pre_elem = root;
        cur_elem = root;
        while (cur_elem->value != value) {
            if ((cur_elem->next == nullptr) & (cur_elem->value != value)) {
                return;
            }
            cur_elem = cur_elem->next;
        }
        while (pre_elem->next != cur_elem) {
            pre_elem = pre_elem->next;
        }
        pre_elem->next = cur_elem->next;
        delete cur_elem;
    }

    void delete_list() {
        Element<T> *cur_elem, *next_elem;
        cur_elem = root;
        if (root == nullptr) {
            delete root;
            return;
        }
        while (cur_elem->next != nullptr) {
            next_elem = cur_elem->next;
            delete cur_elem;
            cur_elem = next_elem;
        }
        delete cur_elem;
    }

    void copy(const List &L) {
        Element<T>* p = nullptr;
        for (auto i = L.root; i != nullptr; i = i->next) {
            auto n = new Element<T>(i->value);
            if(p!= nullptr) {
                p->next = n;
            }
            else {
                this->root = n;
            }
            p = n;
        }
    }

public:
    List() {
        this->root = nullptr;
    }

    List(const List &L) {
        copy(L);
    }

    using iterator = List_Iterator<T>;
    using const_iterator = List_Iterator<const T>;

    iterator begin() const {
        return List_Iterator<T>(root);
    };

    iterator end() const {
        return List_Iterator<T>(nullptr);
    };

    const_iterator const_begin() const {
        return List_Iterator<T>(root);
    };

    const_iterator const_end() const {
        return List_Iterator<const T>(nullptr);
    };

    List &operator=(const List &src) {
        if (this == &src) {
            return *this;
        }
        delete_list();
        copy(src);
        return *this;
    }

    ~List() {
        delete_list();
    }

    void insert(const T &value) override {
        if (root == nullptr) {
            root = new Element<T>(value);
        } else {
            root = new Element<T>(value, root);
        }
    }

    void print() {
        printer(root);
    }

    bool exists(const T &value) const override {
        Element<T> *cur_elem = root;
        if (root == nullptr) {
            return false;
        }
        while (cur_elem->value != value) {
            if (cur_elem->next == nullptr)
                return false;
            cur_elem = cur_elem->next;
        }
        return true;
    }

    void remove(const T &value) override {
        if (root == nullptr) {
            return;
        }
        if (value == root->value) {
            Element<T> *e = root;
            root = root->next;
            delete e;
        } else {
            delete_element(value, root);
        }
    }
};

#endif //LIST_H
