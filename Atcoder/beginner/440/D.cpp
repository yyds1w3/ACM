#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 5;
ll A[MAXN]; 
int n, q;
ll count_missing(ll val, ll x) {
    if (val < x) return 0;
    int count_in_A = upper_bound(A + 1, A + 1 + n, val) - lower_bound(A + 1, A + 1 + n, x);
    ll total_len = val - x + 1;
    return total_len - count_in_A;
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + n);
    while (q--) {
        ll x, k;
        cin >> x >> k;
        ll l = x, r = x + k + n + 10; 
        ll ans = r;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (count_missing(mid, x) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
