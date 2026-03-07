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
const int MAXN = 1e6 + 1;
struct qu {
    int l, r, id;
    bool operator<(const qu& other) const {return r < other.r;}
}q[MAXN];
int pos[MAXN], arr[MAXN];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    BIT<int> bit(n);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i]; 
    }
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    vector<int> ans(m + 1);
    for (int s = 1, i = 1; i <= m; ++i) {
        int r = q[i].r;
        while (s <= r) {
            int col = arr[s];
            if (pos[col] != 0) {
                bit.add(pos[col], -1);
            }
            pos[col] = s;
            bit.add(pos[col], 1);
            s++;
        }
        int l = q[i].l;
        int id = q[i].id;
        ans[id] = bit.rangeSum(l, r);
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << nl;
}
