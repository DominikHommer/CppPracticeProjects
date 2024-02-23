#include "linked_list_template.h"

int main() {
    list<int> l;
    for (int i = 0; i < 10; i++) {
        l.append(i);
    }
    std::cout << l << std::endl;

    list<int> a = l;
    std::cout << a << std::endl;

    list<int> d;
    for (int i = 0; i < 10; i += 2) {
        d.append(i);
    }
    a = d;
    std::cout << a << std::endl;

    a.add_list(d);
    std::cout << a << std::endl;
    std::cout << d.value_at(5) << std::endl;

    list<int> unique = std::move(a);
    std::cout << unique << std::endl;
    std::cout << a << std::endl; // Nach dem Move sollte a leer sein.

    l = std::move(unique);
    std::cout << l << std::endl;
    std::cout << unique << std::endl; // Nach dem Move sollte unique leer sein.

    return 0;
}

