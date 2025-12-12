#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
ll query(int type, int l, int r){
    ll x;
    cout << type << " " << l << " " << r << '\n' << flush;
    cin >> x;
    return x;
}
void solve(){
    int n;
    cin >> n;
    ll sum_a = query(2, 1, n); // a[1] + a[2] + ... + a[n]
    ll diff = sum_a - (1LL * n * (n + 1) / 2); // a[1] - p[1] + a[2] - p[2] + ...
    // bsearch for l
    int l = 1 ,r = n;
    while (l < r){
        int mid = (l + r) / 2;
        if (query(1, 1, mid) < query(2, 1, mid)){ // if sum(p[1]...p[mid]) < sum(a[1]...a[mid]) , means that the true l should <= mid
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    // because diff = r - l + 1, we know l and we can let r = diff + l - 1
    cout << "!" << ' ' << l << ' ' << diff + l - 1 << '\n' << flush;
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}