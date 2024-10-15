#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define INF (ll)1e10
ll n, t, m, st, en;
ll dp[10005][1005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t >> m;
  cin >> st >> en;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= t; j++)
      dp[i][j] = INF;
  dp[st][0] = 0;
  for (int i = 1; i <= t; i++)
  {
    for (int j = 0; j < n; j++)
      dp[j][i] = dp[j][i - 1];
    for (int j = 1; j <= m; j++)
    {
      ll a, b, c;
      cin >> a >> b >> c;
      if (dp[a][i - 1] < INF)
        dp[b][i] = min(dp[b][i], dp[a][i - 1] + c);
      if (dp[b][i - 1] < INF)
        dp[a][i] = min(dp[a][i], dp[b][i - 1] + c);
    }
  }
  ll ans = INF;
  for (int i = 1; i <= t; i++)
    ans = min(ans, dp[en][i]);
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
  return 0;
}