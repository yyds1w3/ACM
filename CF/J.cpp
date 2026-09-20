//Wed Sep  2 08:22:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, d;
    std::cin >> n >> d;
    std::vector<int> pos(n), a(n), b(n), lst(n, -1), nxt(n, -1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        b[i]--;
    }
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) nxt[b[i]] = b[i + 1];
        if (i > 0) lst[b[i]] = b[i - 1];
    }

    // v1 -> v2;
    auto dist = [&](int v1, int v2) -> int {
        if (v1 == -1 || v2 == -1) return 0;
        return (pos[v2] - pos[v1] + n) % n - 1;
    };

    i64 res = 0;
    for (int i = 0; i < n - 1; ++i) {
        res += dist(b[i], b[i + 1]);
    }
    int head = b[0];
    std::cout << res + pos[head]<< nl;
    // debugv(pos, n);
    // debugv(a, n);
    // debugv(lst, n);
    // debugv(nxt, n);
    for (int i = 0; i < d - 1; ++i) {
        int c, x, y;
        std::cin >> c >> x >> y;
        x--, y--;
        if (c == 1) {
            x = a[x];
            y = a[y];
            int lx = lst[x];
            int rx = nxt[x];
            int ly = lst[y];
            int ry = nxt[y];
            if (rx != y && lx != y) {
                res -= dist(lx, x);
                res -= dist(x, rx);
                res -= dist(ly, y);
                res -= dist(y, ry);

                std::swap(a[pos[x]], a[pos[y]]);
                std::swap(pos[x], pos[y]);

                res += dist(lx, x);
                res += dist(x, rx);
                res += dist(ly, y);
                res += dist(y, ry);

            }else if (rx == y) { 
                res -= dist(lx, x);
                res -= dist(x, rx);
                res -= dist(y, ry);

                std::swap(a[pos[x]], a[pos[y]]);
                std::swap(pos[x], pos[y]);

                res += dist(lx, x);
                res += dist(x, rx);
                res += dist(y, ry);
            }else if (lx == y) {
                res -= dist(lx, x);
                res -= dist(x, rx);
                res -= dist(ly, y);

                std::swap(a[pos[x]], a[pos[y]]);
                std::swap(pos[x], pos[y]);

                res += dist(lx, x);
                res += dist(x, rx);
                res += dist(ly, y);
            }
        }else {
            int ox = x;
            int oy = y;
            x = b[x];
            y = b[y];
            int lx = lst[x];
            int rx = nxt[x];
            int ly = lst[y];
            int ry = nxt[y];
            if (rx != y && lx != y) {
                res -= dist(lx, x);
                res -= dist(x, rx);
                res -= dist(ly, y);
                res -= dist(y, ry);

                if (lx != -1) nxt[lx] = y;
                else head = y;
                lst[y] = lx;
                nxt[y] = rx;
                if (rx != -1) lst[rx] = y;

                if (ly != -1) nxt[ly] = x;
                else head = x;
                lst[x] = ly;
                nxt[x] = ry;
                if (ry != -1) lst[ry] = x;

                res += dist(ly, x);
                res += dist(x, ry);
                res += dist(lx, y);
                res += dist(y, rx);

            }else if (rx == y) { 
                res -= dist(lx, x);
                res -= dist(x, rx);
                res -= dist(y, ry);

                if (lx != -1) nxt[lx] = y;
                else head = y;
                lst[y] = lx;
                nxt[y] = x;
                lst[x] = y;
                nxt[x] = ry;
                if (ry != -1) lst[ry] = x;

                res += dist(lx, y);
                res += dist(y, x);
                res += dist(x, ry);
            }else if (lx == y) {
                res -= dist(lx, x);
                res -= dist(x, rx);
                res -= dist(ly, y);

                if (ly != -1) nxt[ly] = x;
                else head = x;
                lst[x] = ly;
                nxt[x] = y;
                lst[y] = x;
                nxt[y] = rx;
                if (rx != -1) lst[rx] = y;

                res += dist(ly, x);
                res += dist(x, y);
                res += dist(y, rx);
            }
            std::swap(b[ox], b[oy]);
        }
        std::cout << res + pos[head] << nl;
        // debugv(pos, n);
        // debugv(a, n);
        // debugv(lst, n);
        // debugv(nxt, n);
    }
}
