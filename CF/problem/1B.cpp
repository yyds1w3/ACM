#include <bits/stdc++.h>
#include <cctype>
#include <iterator>
#include <string>
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
string f1(string &s) {
    size_t C = s.find('C');
    string n1 = s.substr(1, C-1);
    string n2 = s.substr(C+1);
    int num2 = stoi(n2);
    string ans = "";
    while (num2 > 0) {
        num2--;
        ans += char(num2 % 26 + 'A');
        num2 /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans + n1;
}

string f2(string &s) {
    size_t m = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            m = i;
            break;
        }
    }
    string n1 = s.substr(0, m);
    string n2 = s.substr(m);
    int base = 1;
    int ans = 0;
    for (int i = (int)n1.size() - 1; i >= 0; --i) {
        ans += (n1[i] - 'A' + 1) * base;
        base *= 26;
    }
    return 'R' + n2 + 'C' + to_string(ans);
}
void solve() {
    string s; cin >> s;
    size_t R = s.find('R');
    size_t C = s.find('C');
    if (R == 0 && C != string::npos && isdigit(s[1])) {
        cout << f1(s) << nl;
    }else cout << f2(s) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
