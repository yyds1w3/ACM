#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 1;

ll A[N], B[N << 2], Lazy[N << 2];

void build(int s, int t, int p){
    if (s == t) { B[p] = A[s]; return; }
    int m = s + ((t - s) >> 1);
    build(s, m, p*2);
    build(m+1, t, p*2+1);
    B[p] = B[p*2] + B[p*2+1];
}

void maintain(int l, int r, int p){
    if (Lazy[p] && l != r){
        int m = l + ((r - l) >> 1);
        Lazy[p*2] += Lazy[p];
        Lazy[p*2+1] += Lazy[p];
        B[p*2] += Lazy[p] * (m - l + 1);
        B[p*2+1] += Lazy[p] * (r - m);
        Lazy[p] = 0;
    }
}

void add(int L, int R, int l, int r, int p, ll value){
    if (L <= l && r <= R){
        B[p] += value * (r - l + 1);
        Lazy[p] += value;
        return;
    }
    maintain(l, r, p);
    int m = l + ((r - l) >> 1);
    if (L <= m) add(L, R, l, m, p*2, value);
    if (R > m) add(L, R, m+1, r, p*2+1, value);
    B[p] = B[p*2] + B[p*2+1];
}

ll getsum(int L, int R, int l, int r, int p){
    if (L <= l && r <= R) return B[p];
    maintain(l, r, p);
    int m = l + ((r - l) >> 1);
    ll sum = 0;
    if (L <= m) sum += getsum(L, R, l, m, p*2);
    if (R > m) sum += getsum(L, R, m+1, r, p*2+1);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> A[i];

    build(1, n, 1);

    while (m--){
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1){
            ll k; cin >> k;
            add(x, y, 1, n, 1, k);
        } else {
            cout << getsum(x, y, 1, n, 1) << "\n";
        }
    }
}
