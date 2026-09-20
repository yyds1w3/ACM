//Thu Sep 17 16:40:07 CST 2026
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

const int N = 5e5;
int a[N+5];
int tree[4*N+5];
int tag[4*N+5];

int op(int u, int v) {
    return std::min(u, v);
}

void pushup(int u) {
    int lc = 2*u;
    int rc = 2*u+1;
    tree[u] = op(tree[lc], tree[rc]);
}

void pushdown(int u) {
    if (tag[u]) {
        int lc = 2*u;
        int rc = 2*u+1;

        tree[lc] += tag[u];
        tree[rc] += tag[u];

        tag[lc] += tag[u];
        tag[rc] += tag[u];

        tag[u] = 0;
    }
}

// [L, R)
void build(int u, int L, int R) {
    tag[u] = 0;
    if (L == R - 1) {
        tree[u] = a[L];
        return;
    }
    int mid = (L + R) >> 1;
    int lc = 2*u;
    int rc = 2*u+1;
    build(lc, L, mid);
    build(rc, mid, R);
    pushup(u);
}

void rangeAdd(int u, int L, int R, int ql, int qr, int val) {
    if (ql <= L && R <= qr) {
        tree[u] += val;
        tag[u] += val;
        return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    int lc = 2*u;
    int rc = 2*u+1;
    if (ql < mid) rangeAdd(lc, L, mid, ql, qr, val);
    if (qr > mid) rangeAdd(rc, mid, R, ql, qr, val);
    pushup(u);
}

int query(int u, int L, int R, int ql, int qr) {
    if (ql <= L && R <= qr) {
        return tree[u];
    }
    pushdown(u);
    int res = 2e9;
    int mid = (L + R) >> 1;
    int lc = 2*u;
    int rc = 2*u+1;
    if (ql < mid) res = op(res, query(lc, L, mid, ql, qr));
    if (qr > mid) res = op(res, query(rc, mid, R, ql, qr));
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;
    
    for (int i = 1; i <= n; ++i) {
        a[i] = (s[i - 1] == 'A' ? 1 : -1);
        a[i] += a[i - 1];
    }
    build(1, 0, n + 1);
    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int pos;
            char c;
            std::cin >> pos >> c;
            int old_val = (s[pos-1] == 'A' ? 1 : -1);
            int new_val = (c == 'A' ? 1 : -1);
            int diff = new_val - old_val;
            s[pos-1] = c;
            if (diff != 0) {
                rangeAdd(1, 0, n + 1, pos, n + 1, diff);
            }
        } else {
            int ql, qr;
            std::cin >> ql >> qr;
            qr++;
            int r1 = query(1, 0, n + 1, ql-1, ql);
            int r2 = query(1, 0, n + 1, ql, qr);
            
            if (r2 >= r1) std::cout << "Yes" << nl;
            else std::cout << "No" << nl;
        }
    }
}
