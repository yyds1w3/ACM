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
const int MAXN = 1e2 + 5;
int stk[MAXN], top;
bool match[MAXN];
void solve() {
    string s; cin >> s;
    int sz = s.size();
    rep(i, 0, sz-1) {
        if (s[i] == '(' || s[i] == '[') {
            stk[++top] = i;
        }else {
            if (s[i] == ')' && s[stk[top]] == '(') {
                match[stk[top]] = match[i] = true;
                top--;
            }else if (s[i] == ']' && s[stk[top]] == '[') {
                match[stk[top]] = match[i] = true;
                top--;
            }
        }
    }
    rep(i, 0, sz-1) {
        if (!match[i]) {
            if (s[i] == '(' || s[i] == ')') cout << "()";
            else if (s[i] == '[' || s[i] == ']') cout << "[]";
        }else cout << s[i];
    }
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
