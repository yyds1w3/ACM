#include <bits/stdc++.h>
#include <vector>
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
    int N; cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    
    int ans = N * N;
    for (int t = 0; t < 4; ++t) {
        int cnt = t;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (S[i][j] != T[i][j]) {
                    cnt += 1;
                }
            }
        }
        ans = min(ans, cnt);

        vector<string> ns(N);
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                ns[j] += S[i][j];
            }
        }
        S = std::move(ns);
    }
    cout << ans << nl;
}
