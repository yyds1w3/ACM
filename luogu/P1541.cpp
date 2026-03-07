#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXN = 351;
int point[MAXN];
int cnt[5];
int dp[41][41][41][41];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> point[i];
    for (int i = 1; i <= M; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int a = 0; a <= cnt[1]; ++a) {
        for (int b = 0; b <= cnt[2]; ++b) {
            for (int c = 0; c <= cnt[3]; ++c) {
                for (int d = 0; d <= cnt[4]; ++d) {
                    int dist = a + 2 * b + 3 * c + 4 * d + 1;
                    if (a > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a-1][b][c][d]);
                    if (b > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b-1][c][d]);
                    if (c > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c-1][d]);
                    if (d > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d-1]);
                    dp[a][b][c][d] += point[dist];
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << nl;
}
