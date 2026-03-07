#include <bits/stdc++.h>
#include <queue>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void solve() {
    int n; cin >> n;
    map<int,int> cnt;
    priority_queue<int> pq;
    rep(i, 1, n*n) {
        int x; cin >> x;
        cnt[x]++;
        pq.push(x);
    }
    vector<int> ans;
    while (ans.size() < n) {
        int tp = pq.top();
        pq.pop();
        if (cnt[tp] == 0) continue;
        cnt[tp]--;
        for (int v : ans) {
            int g = gcd(v, tp);
            cnt[g] -= 2;
        }
        ans.push_back(tp);
    }
    for (int v : ans) cout << v << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
