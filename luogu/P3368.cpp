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
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    BIT<int> bit(n);
    int pre = 0, nxt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nxt;
        bit.add(i, nxt - pre);
        pre = nxt;
    }
    for (int i = 1; i <= m; ++i) {
        int op, x, y, k; cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            bit.add(x, k);
            bit.add(y+1, -k);
        }else {
            cin >> x;
            cout << bit.sum(x) << nl;
        }
    }
}
