#include <bits/stdc++.h>
#define _CLR_CYAN   "\033[1;36m"
#define _CLR_GREEN  "\033[1;32m"
#define _CLR_RESET  "\033[0m"
using i64 = long long;
using i128 = __int128;
inline std::ostream& operator<<(std::ostream& os, __int128 n) {
    if (n == 0) return os << "0";
    if (n < 0) { os << "-"; n = -n; }
    std::string s;
    while (n > 0) { s += (char)('0' + (n % 10)); n /= 10; }
    std::reverse(s.begin(), s.end());
    return os << s;
}

template <typename T>
void dbg_out(const T& val) { std::cout << val; }

template <typename A, typename B>
void dbg_out(const std::pair<A, B>& p) { std::cout << '(' << p.first << ", " << p.second << ')'; }

inline void dbg_out(const std::string& s) { 
    std::cout << '"' << s << '"'; 
}

inline void dbg_out(const char* s) { 
    std::cout << '"' << s << '"'; 
}
template <typename T>
requires requires(T t) { t.begin(); t.end(); }
void dbg_out(const T& v) {
    std::cout << '[';
    bool first = true;
    for (const auto& x : v) {
        if (!first) std::cout << ",";
        first = false;
        dbg_out(x);
    }
    std::cout << ']';
    std::cout << "Total:" << v.size() << '\n';
}
template <typename T, std::size_t N>
void dbg_out(const T (&a)[N]) {
    std::cout << '[';
    for (std::size_t i = 0; i < N; ++i) {
        if (i > 0) std::cout << ",";
        dbg_out(a[i]);
    }
    std::cout << "]";
    std::cout << "Total:" << N << '\n';
}
template <typename T>
requires requires(T t) { t.begin(); t.end(); }
void dbg_out_range(const T& v, int L, int R) {
    std::cout << '[';
    bool first = true;
    auto it = std::next(v.begin(), L);
    for (int i = L; i < R && it != v.end(); ++i, ++it) {
        if (!first) std::cout << ",";
        first = false;
        dbg_out(*it);
    }
    std::cout << "]";
    std::cout << "Range: [" << L << ", " << R << "), Total: " << v.size() << '\n';
}
template <typename T, std::size_t N>
void dbg_out_range(const T (&a)[N], int L, int R) {
    std::cout << '[';
    for (int i = L; i < R && i < (int)N; ++i) {
        if (i > L) std::cout << ",";
        dbg_out(a[i]);
    }
    std::cout << "]";
    std::cout << "Range: [" << L << ", " << R << "), Total: " << N << "\n";
}
#define debug(x) do { \
    std::cout << _CLR_CYAN << "[" << #x << "]" << _CLR_RESET << std::endl; \
    std::cout << _CLR_GREEN; dbg_out(x); std::cout << _CLR_RESET << std::endl; \
} while (0);

#define debug_range(x, L, R) do {\
    std::cout << _CLR_CYAN << "[" << #x << "]" << _CLR_RESET << std::endl; \
    std::cout << _CLR_GREEN; dbg_out_range(x, L, R); std::cout << _CLR_RESET << std::endl; \
} while (0);
