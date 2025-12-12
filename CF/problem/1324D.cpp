#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    long long ans = 0;
    int L = 0;
    int R = n - 1;
    while (L < R) {
        if (c[L] + c[R] > 0) {
            ans += (R - L);
            R--;
        } else {
            L++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}