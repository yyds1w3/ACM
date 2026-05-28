//Fri Apr 24 04:10:49 PM CST 2026
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
    std::string s;
    std::cin >> s;
    if (s == "red") {
        std::cout << "SSS" ;
    }else if (s == "blue") {
        std::cout << "FFF";
    }else if (s == "green") {
        std::cout << "MMM";
    }else {
        std::cout << "Unknown";
    }
}
