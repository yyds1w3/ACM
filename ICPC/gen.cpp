#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
std::mt19937 rng(time(0));
const int INF = 1 << 30;
void print(int x) {
    std::cout << x << " ";
}
void printnl(int x) {
    std::cout << x << nl;
}
// [l, r)
int Int(int l, int r) {
    return rng() % (r - l) + l;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    freopen("in.txt", "w", stdout);
    int T = 10;
    printnl(T);
    while (T--) {
        int n = Int(5, 12);
        for (int i = 0; i < n; ++i) {
            int c = Int(0, 10);
            if (c < 4) std::cout << '-';
            else std::cout << '>';
        }
        std::cout << nl;
    }
}
