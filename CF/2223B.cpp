//Tue Sep  1 09:38:38 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}
const int MOD = 998244353;
const int N = 2000;
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
void init() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) fact[i] = fact[i-1] * i;
    infact[N] = fact[N].inv();
    for (int i = N-1; i >= 0; --i) infact[i] = infact[i+1] * (i+1);
}
struct Fenwick {
    int n;
    std::vector<i64> treeA;
    
    Fenwick(int n_ = 0) : n(n_) {
        treeA.assign(n + 1, 0);
    }
    void add(int pos, int val) {
        for (int i = pos + 1; i <= n; i += i & -i) { 
            treeA[i] += val;
        }
    }
    void update(int pos, int val) {
        int x = val - query(pos, pos + 1);
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i] += x;
        }
    }
    // sum(pos) == S[0, pos)
    i64 sum(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) { // 这里不加1 因为我们写的开区间
            res += treeA[i];
        }
        return res;
    }
    // query[l, r) = S[0, r) - S[0, l)
    i64 query(int l, int r) {
        return sum(r) - sum(l);
    }
};
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    i64 inva = 0;
    i64 invb = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] < a[j]) {
                inva++;
            }
            if (b[i] < b[j]) {
                invb++;
            }
        }
    }
    std::vector<i64> c(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i*n+j] = 1LL * a[i] * b[j];
        }
    }
    std::sort(c.begin(), c.end());
    c.erase(std::unique(c.begin(), c.end()), c.end());
    auto gR = [&](i64 val) -> int {
        return std::lower_bound(c.begin(), c.end(), val) - c.begin();
    };
    Fenwick bit(c.size());
    Z ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            i64 val = 1LL * a[i] * b[j];
            i64 rk = gR(val);
            i64 diff = i*n+j-bit.sum(rk+1);
            ans += diff;
            bit.add(rk, 1);
        }
    }
    ans -= n * inva + n * invb;
    ans /= n * (n - 1);
    std::cout << ans << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    init();
    int t;
    std::cin >> t;
    while (t--) solve();
}
