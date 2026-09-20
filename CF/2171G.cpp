//Thu Sep  3 08:05:08 PM CST 2026
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
const int INF = 1e9;
const int N = 1e6 + 2;
constexpr int MOD = 1e6 + 3;

struct Z {
    i64 x;
    Z() : x(0) {}
    Z(i64 x_) : x(x_ % MOD) {if (x < 0) x += MOD;}
    i64 val() {return x;}
    Z& operator+=(Z b) {if ((x += b.x) >= MOD) x -= MOD; return *this;}
    Z& operator-=(Z b) {if ((x -= b.x) < 0) x += MOD; return *this;}
    Z& operator*=(Z b) {x = x * b.x % MOD; return *this;}
    Z pow(i64 b) const {
        Z res = 1;
        Z a = *this;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    Z inv() const {return pow(MOD - 2);}
    Z& operator/=(Z b) {return *this *= b.inv();}
    friend Z operator+(Z a, Z b) {return a += b;}
    friend Z operator-(Z a, Z b) {return a -= b;}
    friend Z operator*(Z a, Z b) {return a *= b;}
    friend Z operator/(Z a, Z b) {return a /= b;}
    friend bool operator==(Z a, Z b) {return a.val() == b.val();}
    friend bool operator!=(Z a, Z b) {return !(a == b);}
};
std::ostream& operator<<(std::ostream& os, Z& rhs) {return os << rhs.val();}
Z fact[N+1], infact[N+1];
void initFact() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) fact[i] = fact[i-1] * i;
    infact[N] = fact[N].inv();
    for (int i = N-1; i >= 0; --i) infact[i] = infact[i+1] * (i+1);
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    int k = std::__lg(b[0] / a[0]);
    for (int i = 1; i < n; ++i) {
        k = std::min(k, std::__lg(b[i] / a[i]));
    }
    i64 res1 = k;
    std::vector<int> cnt(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (b[i] & 1) cnt[j]++;
            b[i] >>= 1;
        }
        c[i] = b[i] - a[i];
    }
    Z res2 = 1;
    for (int i = 0; i < k; ++i) {
        res1 += cnt[i];
        res2 *= fact[cnt[i]];
    }
    i64 tot = std::accumulate(c.begin(), c.end(), 0LL);
    res1 += tot;
    if (tot >= MOD) {
        res2 = 0;
    }else {
        res2 *= fact[tot];
    }
    for (int v : c) {
        res2 *= infact[v];
    }
    std::cout << res1 << " " << res2 << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    initFact();
    int t;
    std::cin >> t;
    while (t--) solve();
}
