//Fri Jul 24 03:35:34 PM CST 2026
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define nl "\n"
using i64 = long long;
const int N = 5e5;
int tr[N + 1][26];
int fail[N + 1];
int cnt[N + 1];
int idx;
void init() {
    for (int i = 0; i <= idx; ++i) {
        memset(tr[i], 0, sizeof(tr[i]));
        fail[i] = 0;
        cnt[i] = 0;
    }
    idx = 0;
}
void insert(const std::string& s) {
    int p = 0;
    for (char c : s) {
        int i = c - 'a';
        if (!tr[p][i]) {
            tr[p][i] = ++idx;
        }
        p = tr[p][i];
    }
    cnt[p]++;
}
void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (tr[0][i]) {
            q.push(tr[0][i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < 26; ++i) {
            int v = tr[u][i];
            if (v) {
                fail[v] = tr[fail[u]][i]; 
                q.push(v);
            }else {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}
int query(const std::string& s) {
    int p = 0, res = 0;
    for (char c : s) {
        p = tr[p][c - 'a'];
        int temp = p;

        while (temp && cnt[temp] != -1) {
            res += cnt[temp];
            cnt[temp] = -1;
            temp = fail[temp];
        }
    }
    return res;
}
void solve() {
    init();
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        insert(s);
    }
    build();
    std::string s;
    std::cin >> s;
    std::cout << query(s) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
