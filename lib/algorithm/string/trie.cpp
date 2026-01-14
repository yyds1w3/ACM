/**
 * Algorthim: Trie
 * Verified: CF 271D
 * Complexity: Search O(Len)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
// ========================Start======================
const int MAXN = 1.2e6 + 1;
int trie[MAXN][26];
int tot = 0;
// ========================End==========================
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    string mask; cin >> mask;
    int k; cin >> k;
    ll ans = 0;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
        int u = 0;
        int cnt = 0;
        for (int j = i; j < sz; ++j) {
            if (mask[s[j] - 'a'] == '0') cnt++;
            if (cnt > k) break;
            if (trie[u][s[j] - 'a'] == 0) {
                trie[u][s[j] - 'a'] = ++tot;
                ans++;
            }
            u = trie[u][s[j] - 'a'];
        }
    }
    cout << ans << endl;
}
