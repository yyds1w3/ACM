#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
std::mt19937 rng(time(0));
int Int(int l, int r) {
    return rng() % (r - l) + l;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "w", stdout);
    #endif
    int n = Int(1, 100);
    int m = Int(1, 100);
    std::cout << n << " " << m << nl;
}
