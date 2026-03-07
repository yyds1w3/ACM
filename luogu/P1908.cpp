#include <algorithm>
#include <bits/stdc++.h>
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
const int MAXN = 5e5 + 1;
int a[MAXN], b[MAXN];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    BIT<int> bit(n);
    for (int i = 1;i <= n; ++i) {
        cin >> a[i]; 
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - (b + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int rank = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        bit.add(rank, 1);
        ans += i - bit.sum(rank);
    }
    cout << ans << nl;
}
