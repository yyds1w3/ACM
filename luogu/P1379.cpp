#include <bits/stdc++.h>
#include <queue>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
string now;
string target = "123804765";
int tx[10], ty[10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int h(string s) {
    int res = 0;
    rep(i, 0, 8) {
        int cur_x = i / 3; // 0 1 2
        int cur_y = i % 3; // 0 1 2
        int num = s[i] - '0';
        if (num == 0) continue;
        res += abs(tx[num] - cur_x) + abs(ty[num] - cur_y);
    }
    return res;
}
struct State {
    string s;
    int g, h;
    bool operator<(const State& other) const {return g + h > other.g + other.h;}
};
map<string, int> dist;
priority_queue<State> pq;
void A_star() {
    dist[now] = 0;
    pq.push({now, 0, h(now)});
    while(!pq.empty()) {
        State curr = pq.top();
        pq.pop();
        string s = curr.s;
        int step = curr.g;
        if (s == target) {
            cout << step << nl;
            return;
        }
        if (step > dist[s]) continue;
        int idx = s.find('0');
        int x = idx / 3;
        int y = idx % 3;
        rep(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            int nidx = nx * 3 + ny;
            string ns = s;
            swap(ns[idx], ns[nidx]);
            if (dist.count(ns) == 0 || step + 1 < dist[ns]) {
                dist[ns] = step + 1;
                pq.push({ns, step+1, h(ns)});
            }
        }
    }

}
void solve() {
    cin >> now;
    rep(i, 0, 8) {
        int num = target[i] - '0';
        tx[num] = i / 3;
        ty[num] = i % 3;
    }
    A_star();
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
