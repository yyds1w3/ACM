#include <bits/stdc++.h>
using i128 = __int128;
// 只有正数
std::ostream& operator<<(std::ostream& os, i128 rhs) {
    if (rhs == 0) return os << 0;
    std::vector<int> a;
    while (rhs) {
        a.push_back(rhs%10);
        rhs /= 10;
    }
    while (!a.empty()) {
        os << a.back();
        a.pop_back();
    }
    return os;
}
std::istream& operator>>(std::istream& is, i128& rhs) {
    rhs = 0;
    char c;
    while (is.get(c) && std::isspace(c)) {}
    if (std::isdigit(c)) {
        rhs = rhs * 10 + (c - '0');
        while (is.get(c) && std::isdigit(c)) {
            rhs = rhs * 10 + (c - '0');
        }
        is.unget();
    }
    return is;
}
