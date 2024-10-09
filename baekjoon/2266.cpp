#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll dp[505][505];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++)
      dp[i][j] = (ll)1e9;
  for (int i = 1; i <= n; i++)
    dp[i][1] = i;
  for (int i = 2; i <= k; i++)
    for (int j = 1; j <= n; j++)
    {
      for (int a = 1; a <= j; a++)
        dp[j][i] = min(dp[j][i], 1 + max(dp[j - a][i], dp[a - 1][i - 1]));
    }
  cout << dp[n][k] << endl;
  return 0;
}