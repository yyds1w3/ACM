#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
std::mt19937 rng(time(0));
void print(int x) {
    std::cout << x << " ";
}
void printnl(int x) {
    std::cout << x << nl;
}
int Int(int l, int r) {
    return rng() % (r - l) + l;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    freopen("in.txt", "w", stdout);
    int T = Int(10, 20);
    printnl(T);
    while (T--) {
        int n = Int(1, 7);
        printnl(n);
        for (int i = 0; i < n; ++i) {
            print(Int(1, 100));
        }
        std::cout << nl;
    }
}

