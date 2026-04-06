#include <iostream>
#include <vector>

template<typename T>
requires requires(T t) { t.begin(); t.end(); }
void check(T v) {
    std::cout << "C++20 Concepts works!" << '\n';
}

int main() {
    std::vector<int> v = {1};
    check(v);
    return 0;
}
