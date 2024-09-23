#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
pll arr[105];
ll n;
bool visited[205];
bool dfs(ll idx, ll d)
{
  // cout << idx << ' ' << d << endl;
  for (int i = 1; i <= n; i++)
  {
    if (idx <= arr[i].S && arr[i].S < idx + d)
      return false;
    if (idx + d <= arr[i].F && arr[i].F < idx + 2 * d)
      return false;
    if (idx <= arr[i].F && arr[i].F < idx + d && arr[i].S != arr[i].F + d && arr[i].S != -1)
      return false;
    if (idx + d <= arr[i].S && arr[i].S < idx + 2 * d && arr[i].F != arr[i].S - d && arr[i].F != -1)
      return false;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        continue;
      if (idx <= arr[i].F && arr[i].F < idx + d && arr[j].S == arr[i].F + d)
        return false;
    }
  ll tidx = idx + 2 * d;
  if (tidx == 2 * n + 1)
    return true;
  for (int td = 1; td <= (2 * n + 1 - idx) / 2; td++)
    if (dfs(tidx, td))
      return true;
  return false;
}
bool check()
{
  for (int i = 1; i <= n; i++)
    if (dfs(1, i))
      return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i].F >> arr[i].S;
  for (int i = 1; i <= n; i++)
  {
    if (arr[i].F == -1 || arr[i].S == -1)
      continue;
    if (arr[i].F >= arr[i].S)
    {
      cout << "No";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
    {
      bool c = true;
      if (arr[i].F == arr[j].F && arr[i].F != -1)
        c = false;
      if (arr[i].S == arr[j].S && arr[i].S != -1)
        c = false;
      if (arr[i].F == arr[j].S && arr[i].F != -1)
        c = false;
      if (arr[i].S == arr[j].F && arr[i].S != -1)
        c = false;
      if (!c)
      {
        cout << "No";
        return 0;
      }
    }
  if (check())
    cout << "Yes";
  else
    cout << "No";
  return 0;
}