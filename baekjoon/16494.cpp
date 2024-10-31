#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll dp[25][25];
ll n, m;
ll arr[25];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 1; i <= n; i++)
    dp[i][1] = dp[i - 1][1] + arr[i];

  for (int j = 2; j <= m; j++)
    for (int i = 2 * j - 1; i <= n; i++)
    {
      dp[i][j] = (ll)-1e9;
      dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + arr[i]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i]);
    }

  return 0;
}