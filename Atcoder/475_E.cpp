//Mon Sep 14 07:18:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}
const int N = 6e6;
int trie[N+1][2];
int cnt[N+1];
int tot;
void initTrie() {
    for (int i = 0; i <= tot; ++i) {
        trie[i][0] = trie[i][1] = cnt[i] = 0;
    }
    tot = 0;
}
int newnode() {
    int x = ++tot;
    return x;
}
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string t;
    std::cin >> t;
    initTrie();
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        int cur = 0;
        for (int j = 0; j < k; ++j) {
            int x;
            if (v[i][j] == 'o') {
                x = trie[cur][0];
                if (!x) x = newnode();
                trie[cur][0] = x;
                cnt[x]++;
            }else {
                x = trie[cur][1];
                if (!x) x = newnode();
                trie[cur][1] = x;
                cnt[x]++;
            }
            cur = x;
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int i, j;
        std::cin >> i >> j;
        i--, j--;
        int cur;
        cur = 0;
        for (int idx = 0; idx < k; ++idx) {
            if (v[i][idx] == 'o') {
                cur = trie[cur][0];
                cnt[cur]--;
            }else {
                cur = trie[cur][1];
                cnt[cur]--;
            }
        }
        v[i][j] = (v[i][j] == 'x' ? 'o' : 'x');

        cur = 0;
        for (int idx = 0; idx < k; ++idx) {
            if (v[i][idx] == 'o') {
                if (!trie[cur][0]) trie[cur][0] = newnode();
                cur = trie[cur][0];
                cnt[cur]++;
            }else {
                if (!trie[cur][1]) trie[cur][1] = newnode();
                cur = trie[cur][1];
                cnt[cur]++;
            }
        }

        int sum = 0;
        bool ok = false;
        cur = 0;
        for (int idx = 0; idx < k; ++idx) {
            int x;
            if (t[idx] == 'o') {
                x = trie[cur][0];
                if (sum + cnt[x] <= m) {
                    sum += cnt[x];
                    if (v[i][idx] == 'o') {
                        ok = true;
                        break;
                    }else {
                        cur = trie[cur][1];
                    }
                }else {
                    if (v[i][idx] == 'x') {
                        ok = false;
                        break;
                    }else {
                        cur = trie[cur][0];
                    }
                }
            }else {
                x = trie[cur][1];
                if (sum + cnt[x] <= m) {
                    sum += cnt[x];
                    if (v[i][idx] == 'x') {
                        ok = true;
                        break;
                    }else {
                        cur = trie[cur][0];
                    }
                }else {
                    if (v[i][idx] == 'o') {
                        ok = false;
                        break;
                    }else {
                        cur = trie[cur][1];
                    }
                }
            }
        }
        if (ok) std::cout << "Yes" << nl;
        else std::cout << "No" << nl;
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
