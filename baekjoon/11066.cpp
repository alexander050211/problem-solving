#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll dp[505][505];
ll sum[505];
ll n;
void solve()
{
  vector<ll> arr(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + arr[i];
  for (int i = 1; i <= n; i++)
    dp[i][i] = 0;
  for (int i = 1; i < n; i++)
    for (int x = 1; x <= n; x++)
    {
      if (x + i > n)
        continue;
      for (int j = x; j < x + i; j++)
        dp[x][x + i] = min(dp[x][x + i], sum[x + i] - sum[x - 1] + dp[x][j] + dp[j + 1][x + i]);
    }
  cout << dp[1][n] << endl;
}
void init()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = (ll)1e9;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--)
  {
    init();
    solve();
  }
  return 0;
}