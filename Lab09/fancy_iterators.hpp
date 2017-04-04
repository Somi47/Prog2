/*
 * \file fancy_iterators.hpp
 *
 */

#ifndef FANCY_ITERATORS_HPP
#define FANCY_ITERATORS_HPP

/// counting iterator.
/// Végtelen számláló.
/// Olyan típusokra példányosítható, aminek van pre-inkremens operátora.
template <typename T>
class counting_iterator {
    T t;
public:
     counting_iterator(T t = T()) : t(t) {}
     bool operator==(const counting_iterator& rhs) const { return t == rhs.t; }
     bool operator!=(const counting_iterator& rhs) const { return !operator==(rhs); }
     counting_iterator& operator++() { ++t; return *this; }
     counting_iterator operator++(int) { counting_iterator tmp = *this;  operator++(); return tmp; }
     T& operator*() { return t; }
     T* operator->() { return &operator*(); }
};

#endif // FANCY_ITERATORS_HPP
