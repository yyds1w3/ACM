#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
template <typename T>
struct BIT {
    int n;
    std::vector<T> a;
    
    BIT(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i >= 1; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};
const int MOD = 1e8 - 3;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    BIT<int> bit(n);
    vector<pair<int, int>> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<int> c(n+1);
    for (int i = 1; i <= n; ++i) {
        c[a[i].second] = b[i].second;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        bit.add(c[i], 1);
        ans = (ans + i - bit.sum(c[i])) % MOD;
    }
    cout << ans << nl;

}
