#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    string s; cin >> s;
    int sz = s.size();
    char zimu = 'a';
    int xishu = 0;
    int changshu = 0;
    int val = 0;
    bool has_val = 0;
    int side = 1;
    int sign = 1;
    for (int i = 0; i < sz; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            val = val * 10 + (c - '0');
            has_val = true;
        }else if (isalpha(c)) {
            if (!has_val) val = 1;
            zimu = c;
            xishu += val * sign * side;
            val = 0;
            has_val = false;
        }else {
            if (has_val) {
                changshu += val * sign * side * (-1);
                val = 0;
                has_val = false;
            }
            if (c == '+') {
                sign = 1;
            }else if (c == '-') {
                sign = -1;
            }else {
                side = -1;
                sign = 1;
            }
        }
    }
    if (has_val) changshu += val * side * sign * (-1);
    double ans = (double)changshu / xishu;
    debug(changshu);
    debug(xishu);
    if (abs(ans) < 1e-3) ans = 0.0;
    cout << zimu << "=" << setprecision(3) << fixed << ans << nl;

}
