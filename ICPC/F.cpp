//Fri Sep  4 05:08:07 PM CST 2026
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
    int l, len, val;
    bool operator<(const Node& other) const {
        return l < other.l;
    }
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << rhs.l << "," << rhs.len << "," << rhs.val << "]";
}

void solve() {
    int n;
    std::cin >> n;
    int l = 0, len = 0, val = -1;
    std::set<Node> s;
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x != val) {
            if (val != -1) {
                Node nd = {l, len, val};
                // debug(nd);
                s.insert(nd);
                pq.push({-val, l});
            }
            l = i;
            len = 1;
            val = x;
        }else {
            len++;
        }
    }
    Node nd = {l, len, val};
    // debug(nd);
    s.insert(nd);
    pq.push({-val, l});

    i64 ans = 0;
    while (pq.size() > 1) {
        auto [val, l] = pq.top();
        pq.pop();
        val *= -1;

        auto it = s.lower_bound({l, 0, 0});
        bool f1 = false, f2 = false;
        auto rit = it, nit = it;
        if (it != s.begin()) {
            rit = std::prev(it);
            f1 = true;
        }
        if (std::next(it) != s.end()) {
            nit = std::next(it);
            f2 = true;
        }
        // Node ndd = *it;
        // Node nndd = *nit;
        // debug(ndd);
        // debug(nndd);
        int clen = it->len;
        if (!f1) {
            auto [l1, len1, val1] = *nit;
            if (val1 > it->val) ans += clen;
            s.erase(nit);
            s.erase(it);
            s.insert({l1, len1 + clen, val1});
        }else if (!f2) {
            auto [l1, len1, val1] = *rit;
            if (val1 > it->val) ans += clen;
            s.erase(rit);
            s.erase(it);
            s.insert({l1, len1 + clen, val1});
        }else if (rit->val < nit->val) {
            auto [l1, len1, val1] = *rit;
            if (val1 > it->val) ans += clen;
            s.erase(rit);
            s.erase(it);
            s.insert({l1, len1 + clen, val1});
        }else if (rit->val >= nit->val){
            auto [l1, len1, val1] = *nit;
            if (val1 > it->val) ans += clen;
            s.erase(nit);
            s.erase(it);
            s.insert({l1, len1 + clen, val1});
        }
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
