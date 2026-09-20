//Tue Aug 11 12:58:15 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int c00 = 0, c01 = 0, c10 = 0, c11 = 0;

    int l00 = n, r00 = -1, l11 = n, r11 = -1;
    int l01 = n, r01 = -1, l10 = n, r10 = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (s.substr(i, 2) == "00") {
            l00 = std::min(l00, i);
            r00 = std::max(r00, i);
            c00 = 1;
        }
        if (s.substr(i, 2) == "01") {
            l01 = std::min(l01, i);
            r01 = std::max(r01, i);
            c01 = 1;
        }
        if (s.substr(i, 2) == "10") {
            l10 = std::min(l10, i);
            r10 = std::max(r10, i);
            c10 = 1;
        }
        if (s.substr(i, 2) == "11") {
            l11 = std::min(l11, i);
            r11 = std::max(r11, i);
            c11 = 1;
        }
    }
    std::string ans;
    int t00 = 0, t01 = 0, t10 = 0, t11 = 0;
    int l0 = n, r0 = -1, l1 = n, r1 = -1;
    if (t00 < c00) {
        ans += "00";
        l0 = std::min(l0, l00);
        r0 = std::max(r0, r00+1);
        t00++;
        if (t01 < c01) {
            if (l01 >= r0) {
                ans += '1';
                t01++;
            }
        }
        if (t10 < c10){
            if (r10 + 1 <= l0) {
                ans = '1' + ans;
                t10++;
            }
        }
    }
    if (t01 < c01) {
        ans = "01" + ans;
        l0 = std::min(l0, l01);
        r1 = std::max(r1, r01 + 1);
        t01++;
        if (t10 < c10)
    } 



}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
