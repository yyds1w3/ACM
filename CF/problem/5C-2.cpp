#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
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
const int MAXN = 1e5 + 5;

void solve() {
    string s; cin >> s;
    size_t sz = s.size();
    vector<int> st;
    st.push_back(-1);
    int mx = 0;
    int cnt = 1;
    for (int i = 0; i < sz; ++i) {
        if (s[i] == '(') {
            st.push_back(i);
        }else {
            st.pop_back();
            if (st.empty()) st.push_back(i);
            else {
                if (i - st.back() > mx ){
                    mx = i - st.back();
                    cnt = 1;
                } else if (i - st.back() == mx && mx > 0) {
                    cnt++;
                }
            }
        }
    }
    cout << mx << " " << cnt << nl;
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
