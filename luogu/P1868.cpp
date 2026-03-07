#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
#define debug(x) cerr << x << endl
const int MAXY = 3e6 + 1;
vector<int> straw[MAXY];
int dp[MAXY];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N; cin >> N;
    int mxY = 0;
    for (int i = 1; i <= N; ++i) {
        int x, y; cin >> x >> y;
        x++, y++;
        straw[y].push_back(x);
        mxY = max(mxY, y);
    }
    for (int i = 1; i <= mxY; ++i) {
        dp[i] = dp[i-1];
        for (int s : straw[i]) {
             dp[i] = max(dp[i], dp[s-1] + i - s + 1);
        }
    }
    cout << dp[mxY] << nl;



}
