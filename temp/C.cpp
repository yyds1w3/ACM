#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int H, h1, h2;
    std::cin >> H >> h1 >> h2;
    if (H < h1) {
        std::cout << "Bu Kan" << nl;
    }else if (H < h2) {
        std::cout << "Zhe Gua Bao Shu Ma" << nl;
    }else {
        std::cout << "Chi Gua" << nl;
    }
}
