#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int INF = 0x3F3f3f3f;
int n, m;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        dp[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[u][v], w);
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dp[i][k] != INF && dp[k][j] != INF)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}