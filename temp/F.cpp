#include <bits/stdc++.h>
#include <numeric>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        int sum1 = std::accumulate(s.begin(), s.begin() + 3, 0);
        int sum2 = std::accumulate(s.begin()+3, s.end(), 0);
        if (sum1 == sum2) {
            std::cout << "You are lucky!" << nl;
        }else {
            std::cout << "Wish you good luck." << nl;
        }
    }
}
