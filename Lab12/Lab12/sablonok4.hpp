#ifndef SABLONOK_HPP
#define SABLONOK_HPP
/*
 * sablonok.hpp
 */

template <typename Iter>
 void printEach(Iter first, Iter last, std::ostream& os = std::cout, const char *sep = ",") {
    while (first != last) {
        os << *first++;
        if (first != last) os << sep;
        else os << std::endl;
    }
 }

template <typename Iter>
int szamol_ha_negativ(Iter first, Iter last) {
    int cnt = 0;
    while (first != last)
        if (*first++ < 0) cnt++;
    return cnt;
}

template <typename Iter, typename Pred>
int szamol_ha(Iter first, Iter last, Pred pred) {
    int cnt = 0;
    while (first != last)
        if (pred(*first++)) cnt++;
    return cnt;
}

template <typename T>
class nagyobb_mint {
    T ref;
public:
    nagyobb_mint(T r) :ref(r) {}
    bool operator()(const T& a) {
        return a > ref;
    }
};

template <class T>
void kiir(const char *txt, T& a) {
    std::cout << txt << ": size=" << a.size()
         << " capacity=" << a.capacity() << std::endl;
    std::cout << "\t data=";
    printEach(a.begin(), a.end());
}

template <class Iter, class Sel>
Iter kivalaszt(Iter first, Iter last, Sel cmp) {
    Iter tmp = first;
    while(++first != last)
        if (cmp(*first, *tmp)) tmp = first;
    return tmp;
}

template <typename T>
struct nagyobb {
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

template <typename Iter, class Func>
Func forEach(Iter first, Iter last, Func func) {
    while (first != last)
        func(*first++);
    return func;
}

template <class T>
class ostreamFunctor {
   std::ostream& os;
   const char* delim;
public:
   ostreamFunctor(std::ostream& os, const char* delim = "") : os(os), delim(delim) {}
   void operator()(const T& d) const { os << d << delim; }
};

#endif