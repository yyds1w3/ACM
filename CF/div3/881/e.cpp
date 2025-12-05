#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5; 

int t, n, m, q;
int query_pos[N]; 
vector<pair<int, int>> beautiful;

bool check(int k) {
    vector<int> state(n + 1, 0);
    for (int i = 1; i <= k; ++i) {
        state[query_pos[i]] = 1;
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] + state[i];
    }
    for (auto p : beautiful) {
        int l = p.first;
        int r = p.second;        
        int len = r - l + 1;
        int ones = pre[r] - pre[l-1];
        int zeros = len - ones;
        if (ones > zeros) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    beautiful.clear();    
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        beautiful.push_back({l, r});
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> query_pos[i];
    }
    int l = 0, r = q + 1; 
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l > q) cout << "-1" << '\n';
    else cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}