//Sun Sep 20 04:44:02 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define print(x) std::cout << x << " "
#define printnl(x) std::cout << x << nl
using i64 = long long;
std::mt19937 rng(time(0));
int Int(int l, int r) {
    return rng() % (r - l) + l;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int T = Int(1, 10);
    printnl(T);
    while (T--) {
        int n = Int(1, 1000);
        int m = Int(1, 1000);
        print(n);printnl(m);
    }
}
