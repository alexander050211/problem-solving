#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define INF (ll)1e10
ll m, n;
vector<ll> par[1000005];
ll chi[1000005];
ll deg[1000005];
bool visited[1000005];
void dfs(ll x)
{
  for (auto nx : par[x])
  {
    deg[nx] = deg[x] + 1;
    dfs(nx);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> n;
  for (int i = 0; i < n; i++)
    chi[i] = -1;
  for (int i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    if (visited[a] && visited[b])
      continue;
    par[b].push_back(a);
    chi[a] = b;
    visited[a] = visited[b] = true;
  }
  for (int i = 0; i < n; i++)
  {
    if (chi[i] == -1)
    {
      deg[i] = 1;
      dfs(i);
    }
  }
  ll ans = 1;
  for (int i = 0; i < n; i++)
    ans = max(ans, deg[i]);
  cout << ans << endl;
  return 0;
}