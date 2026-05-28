#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto b = a;
    sort(b.begin(), b.end());
    int M = b[n / 2];

    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;

    for (int r = 1; r <= n; r++) {
        int neg = 0, zero = 0, pos = 0;
        for (int l = r; l >= 1; l--) {
            if (a[l - 1] < M) neg++;
            else if (a[l - 1] == M) zero++;
            else pos++;

            if ((r - l + 1) % 2 == 0) continue;
            if (neg + zero > pos && pos + zero > neg)
                dp[r] = max(dp[r], dp[l - 1] + 1);
        }
    }

    cout << max(0, dp[n]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
