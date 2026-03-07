#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
map<string, int> m = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10},
    {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15},
    {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20},
    {"a", 1}, {"both", 2}, {"another", 1}, {"first", 1}, {"second", 2}, {"third", 3},
    {"zero", 0} 
};
int nums[7];
int tot = 0;
void solve() {
    rep(i, 1, 7) {
        string s; cin >> s;
        auto it = m.find(s);
        if (it != m.end()){
            nums[++tot] = (it->second * it->second) % 10000000000;
        }
    }
    sort(nums + 1, nums + 1 + tot);
    int printed = false;
    int pre = false;
    rep(i, 1, tot) {
        if (nums[i] != 0) {
            if (nums[i] < 10) {
                if (pre) cout << "0" << nums[i];
                else cout << nums[i];
            }
            else cout << nums[i];
            printed = true;
            pre = true;
        }
    }
    if (!printed) cout << 0;
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
