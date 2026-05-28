//Sat May 23 08:02:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int N;
    std::cin >> N;
    std::string s;
    for (int i = 0; i < N; ++i) {
        std::cin >> s;
        if (s[0] == 'a' || s[0] == 'b' || s[0] == 'c') std::cout << 2;
        if (s[0] == 'd' || s[0] == 'e' || s[0] == 'f') std::cout << 3;
        if (s[0] == 'g' || s[0] == 'h' || s[0] == 'i')std::cout << 4;
        if (s[0] == 'j' || s[0] == 'k' || s[0] == 'l')std::cout << 5;
        if (s[0] == 'm' || s[0] == 'n' || s[0] == 'o')std::cout << 6;
        if (s[0] == 'p' || s[0] == 'q' || s[0] == 'r' || s[0] == 's')std::cout << 7;
        if (s[0] == 't' || s[0] == 'u' || s[0] == 'v')std::cout << 8;
        if (s[0] == 'w' || s[0] == 'x' || s[0] == 'y' || s[0] == 'z')std::cout << 9;
    }

}
