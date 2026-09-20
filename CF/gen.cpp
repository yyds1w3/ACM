//Sun Sep 20 12:03:56 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;

std::mt19937 rng(time(0));
#define print(x) std::cout << x << " "
#define printnl(x) std::cout << x << nl
int Int(int l, int r) {
    return rng() % (r - l) + l;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int T = 100;
    printnl(T);
    while (T--) {
        int N = Int(1, 10);
        int K = Int(1, 10);
        printnl(N);
        printnl(K);
        std::string S;
        for (int i = 0; i < N; ++i) {
            S += 'a' + Int(0, 5);
        }
        printnl(S);
    }
}
