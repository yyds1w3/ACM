//Wed Aug 19 06:53:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl; 
#define debugv(v, sz) std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;
#define debugvv(v, sz1, sz2) std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}
using i64 = long long;
using i128 = __int128;
struct st {
    char c;
    int t;
    bool operator<(const st& other) const {
        return t > other.t;
    }
};
std::ostream& operator<<(std::ostream& os, const st& rhs) {
    os << "[" << rhs.c << "," << rhs.t << "]";
    return os;
}
void solve() {
    std::vector<st> a(3);
    int r, g, b;
    std::cin >> r >> g >> b;
    a[0] = {'R', r};
    a[1] = {'G', g};
    a[2] = {'B', b};
    std::vector<int> mp(200);
    mp['R'] = r;
    mp['G'] = g;
    mp['B'] = b;
    std::sort(a.begin(), a.end());
    std::string s;
    s += a[0].c;
    a[0].t--;
    mp[a[0].c]--;
    if (a[1].t > 0) {
        s += a[1].c;
        a[1].t--;
        mp[a[1].c]--;
    }else {
        std::cout << s << nl;
        return;
    }
    std::sort(a.begin(), a.end());
    int i = 0;
    while (true) {
        char ci = s[i];
        char cl = s[i+1];
        char c1 = ci;
        char c2 = 'H';
        if ('R' != ci && 'R' != cl) c2 = 'R';
        else if ('G' != ci && 'G' != cl) c2 = 'G';
        else c2 = 'B';
        // debug(c1);
        // debug(c2);
        if (mp[c1] >= mp[c2]) {
            if (mp[c1] <= 0) break;
            s += c1;
            mp[c1]--;
        }else {
            if (mp[c2] <= 0) break;
            s += c2;
            mp[c2]--;
        }
        i++;
    }
    std::cout << s << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
