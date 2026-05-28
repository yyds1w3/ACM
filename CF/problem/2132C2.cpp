#include <bits/stdc++.h>
#define nl "\n"
using namespace std;
using i64 = long long;
i64 p3[40];
void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> cnt(40, 0);
    i64 temp = n;
    i64 current_transactions = 0;
    for (int i = 0; temp > 0; ++i) {
        cnt[i] = temp % 3;
        current_transactions += cnt[i];
        temp /= 3;
    }
    if (current_transactions > k) {
        cout << -1 << nl;
        return;
    }
    i64 S = (k - current_transactions) / 2;
    for (int x = 39; x >= 1; --x) {
        if (cnt[x] > 0 && S > 0) {
            i64 splits = min(S, cnt[x]);
            cnt[x] -= splits;
            cnt[x - 1] += splits * 3;
            S -= splits;
        }
    }
    i64 ans = 0;
    for (int x = 0; x < 40; ++x) {
        if (cnt[x] > 0) {
            if (x == 0) {
                ans += cnt[x] * 3;
            } else {
                ans += cnt[x] * (x + 9) * p3[x - 1];
            }
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    p3[0] = 1;
    for (int i = 1; i < 40; ++i) {
        p3[i] = p3[i - 1] * 3;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
