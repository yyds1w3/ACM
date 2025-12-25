#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
struct st{
    ll a, b;
    bool operator<(const st& other) const {return a < other.a;}
}cow[50001];
vector<int> id;
int cnt[50001];
int get_id(int x){
    return lower_bound(id.begin(), id.end(), x) - id.begin();
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> cow[i].a >> cow[i].b;
        id.push_back(cow[i].b);
    }
    sort(id.begin() , id.end());
    id.erase(unique(id.begin(), id.end()), id.end());
    int need_type = id.size();
    sort(cow + 1, cow + 1 + n);
    ll mn = 0x3f3f3f3f;
    int l = 1;
    int now_type = 0;
    for (int r = 1; r <= n; ++r){
        int tp = get_id(cow[r].b);
        if (cnt[tp] == 0){
            now_type++;
        }
        cnt[tp]++;
        while (now_type == need_type){
            mn = min(cow[r].a - cow[l].a, mn);
            int tpl = get_id(cow[l].b);
            cnt[tpl]--;
            if (cnt[tpl] == 0) now_type--;
            l++;
        }
    }
    cout << mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
