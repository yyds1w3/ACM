#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct st {
    ll x, y;
    bool operator<(const st& other) const { return x < other.x; }
};

st a[5005];
st raw_p[5005];  
int l, w, n;

ll calc() {
    a[1] = {0, 0}; a[2] = {0, w}; a[3] = {l, 0}; a[4] = {l, w};
    for (int i = 1; i <= n; ++i) {
        a[i + 4] = raw_p[i];
    }
    
    int cnt = n + 4;
    sort(a + 1, a + 1 + cnt);
    
    ll s = 0;
    
    for (int i = 1; i <= cnt; ++i) {
        ll up = w, down = 0;
        for (int j = i + 1; j <= cnt; ++j) {
            s = max(s, (up - down) * (a[j].x - a[i].x));
            if (a[j].y > a[i].y) up = min(up, a[j].y);
            else down = max(down, a[j].y);
        }
    }
    for (int i = cnt; i >= 1; --i) {
        ll up = w, down = 0;
        for (int j = i - 1; j >= 1; --j) {
            s = max(s, (up - down) * (a[i].x - a[j].x));
            if (a[j].y > a[i].y) up = min(up, a[j].y);
            else down = max(down, a[j].y);
        }
    }
    
    for (int i = 1; i < cnt; ++i) {
        s = max(s, (ll)w * (a[i + 1].x - a[i].x));
    }
    
    return s;
}

void solve() {
    if (!(cin >> l >> w >> n)) return;
    for (int i = 1; i <= n; ++i) {
        cin >> raw_p[i].x >> raw_p[i].y;
    }
    ll ans = calc();
    swap(l, w); 
    for (int i = 1; i <= n; ++i) {
        swap(raw_p[i].x, raw_p[i].y);
    }
    ans = max(ans, calc());
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
