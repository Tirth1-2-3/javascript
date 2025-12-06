#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <iostream>

using namespace std;
using ll = long long;
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define srt(arr) sort((arr).begin(), (arr).end())
#define int long long
ll MOD = 1e9 + 7;
void solve()
{
    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<ll>> grid(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int dp[n + 1][m + 1][K + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                if (i == 1 && j == 1)
                {
                    if (grid[i][j])
                    {
                        if (k >= 1)
                            dp[i][j][k] = 1;
                    }
                    else
                    {
                        dp[i][j][k] = 1;
                    }
                }
                else
                {
                    if (k == 0)
                    {
                        if (!grid[i][j])
                            dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k];
                    }
                    else
                    {
                        if (grid[i][j])
                        {
                            dp[i][j][k] = dp[i - 1][j][k - 1] + dp[i][j - 1][k - 1];
                        }
                        else
                        {
                            dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k];
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][m][K] << nline;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}