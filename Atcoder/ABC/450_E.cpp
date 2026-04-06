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
const i64 INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    std::string x, y;
    std::cin >> x >> y;
    int sx = x.size();
    int sy = y.size();
    std::vector<std::vector<i64>> pX(sx + 1, std::vector<i64>(256, 0));
    std::vector<std::vector<i64>> pY(sy + 1, std::vector<i64>(256, 0));
    for (int i = 0; i < sx; ++i) {
        pX[i + 1] = pX[i];
        pX[i + 1][x[i]]++;
    }
    for (int i = 0; i < sy; ++i){
        pY[i + 1] = pY[i];
        pY[i + 1][y[i]]++;
    }
    std::vector<i64> len(100, 0);
    std::vector cnt(100, std::vector<i64>(256, 0));
    len[1] = sx;
    for (int i = 0; i < sx; ++i) {
        cnt[1][x[i]]++;
    }
    len[2] = sy;
    for (int i = 0; i < sy; ++i) {
        cnt[2][y[i]]++;
    }
    int mx_n = 2;
    while (len[mx_n] <= INF) {
        mx_n++;
        len[mx_n] = len[mx_n - 1] + len[mx_n - 2];
        for (int c = 0; c < 256; ++c) {
            cnt[mx_n][c] = cnt[mx_n - 1][c] + cnt[mx_n - 2][c];
        } 
    }
    auto ask = [&](i64 k, char c) -> i64 {
        i64 ans = 0;
        int cur = mx_n;
        while (k > 0) {
            if (cur == 1) {
                ans += pX[k][c];
                break;
            }
            if (cur == 2) {
                ans += pY[k][c];
                break;
            }
            if (k >= len[cur - 1]) {
                ans += cnt[cur - 1][c];
                k -= len[cur - 1];
                cur -= 2;
            }else {
                cur -= 1;
            }
        }
        return ans;
    };
    int q;
    std::cin >> q;
    while (q--) {
        i64 l, r;
        std::cin >> l >> r;
        char c;
        std::cin >> c;
        std::cout << ask(r, c) - ask(l - 1, c) << nl; 
    }


}
