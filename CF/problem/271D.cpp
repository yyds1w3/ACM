#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int P = 131;
void solve() {
    string s; cin >> s;
    string mask; cin >> mask;
    int k; cin >> k;
    set<ull> st;
    int sz = s.size();
    for (int i = 0; i < sz ; ++i) {
        int cnt = 0;
        ull hash_v = 0;
        for (int j = i; j < sz; ++j) {
            if (mask[s[j] - 'a'] == '0') cnt++;
            if (cnt > k) break;
            hash_v = hash_v * P + s[j];
            st.insert(hash_v);
        }
    }
    cout << st.size() << endl;
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
