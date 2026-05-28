//Thu May 14 08:36:00 PM CST 2026
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;
    
    vector<i64> a(n), b(m);
    i64 Sa = 0, Sb = 0;
    for (int i = 0; i < n; ++i) { cin >> a[i]; Sa += a[i]; }
    for (int i = 0; i < m; ++i) { cin >> b[i]; Sb += b[i]; }

    vector<i64> va(n), vb(m);
    for (int i = 0; i < n; ++i) va[i] = Sa - a[i];
    for (int i = 0; i < m; ++i) vb[i] = Sb - b[i];
    sort(va.begin(), va.end());
    va.erase(unique(va.begin(), va.end()), va.end());
    sort(vb.begin(), vb.end());
    vb.erase(unique(vb.begin(), vb.end()), vb.end());
    auto inA = [&](i64 val) { return binary_search(va.begin(), va.end(), val); };
    auto inB = [&](i64 val) { return binary_search(vb.begin(), vb.end(), val); };
    while (q--) {
        i64 x;
        cin >> x;
        if (x == 0) {
            if ((inA(0) && !vb.empty()) || (inB(0) && !va.empty())) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        bool found = false;
        i64 abs_x = abs(x);
        for (i64 i = 1; i * i <= abs_x; ++i) {
            if (abs_x % i == 0) {
                i64 d1 = i;
                i64 d2 = abs_x / i;
                if (x > 0) {
                    if ((inA(d1) && inB(d2)) || (inA(d2) && inB(d1)) ||
                        (inA(-d1) && inB(-d2)) || (inA(-d2) && inB(-d1))) {
                        found = true;
                        break;
                    }
                } else {
                    if ((inA(d1) && inB(-d2)) || (inA(d2) && inB(-d1)) ||
                        (inA(-d1) && inB(d2)) || (inA(-d2) && inB(d1))) {
                        found = true;
                        break;
                    }
                }
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
