#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define pb push_back
ll n;
ll sub[50005];
vector<ll> adj[50005];
ll dist1[50005], dist2[50005];
ll ans[50005];
ll st, en;
void dfs1(ll prev, ll idx)
{
  for (auto x : adj[idx])
  {
    if (x == prev)
      continue;
    if (dist1[x])
      continue;
    dist1[x] = dist1[idx] + 1;
    dfs1(idx, x);
  }
}
void dfs2(ll prev, ll idx)
{
  sub[idx] = 1;
  for (auto x : adj[idx])
  {
    if (x == prev)
      continue;
    if (dist2[x])
      continue;
    dist2[x] = dist2[idx] + 1;
    dfs2(idx, x);
    sub[idx] += sub[x];
  }
}
void dfs3(ll prev, ll idx)
{
  if (dist2[idx] % 2)
  {
    if (!adj[idx].size())
      return;
    ll next = 0;
    for (auto x : adj[idx])
      if (sub[x] > 1)
        next = x;
    if (!next)
    {
      for (auto x : adj[idx])
        ans[x] = st++;
    }
    else
    {
      ans[next] = st++;
      for (auto x : adj[idx])
        if (x != next)
          ans[x] = st++;
      dfs3(idx, next);
    }
  }
  else
  {
    if (!adj[idx].size())
      return;
    ll next = 0;
    for (auto x : adj[idx])
      if (sub[x] > 1)
        next = x;
    if (!next)
    {
      for (auto x : adj[idx])
        ans[x] = en--;
    }
    else
    {
      ans[next] = en--;
      for (auto x : adj[idx])
        if (x != next)
          ans[x] = en--;
      dfs3(idx, next);
    }
  }
}
int main()
{
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs1(0, 1);
  ll idx1 = 1;
  for (int i = 2; i <= n; i++)
    idx1 = (dist1[idx1] > dist1[i]) ? idx1 : i;

  cout << idx1 << endl;

  dfs2(0, idx1);
  ll idx2 = 1;
  for (int i = 2; i <= n; i++)
    idx2 = (dist2[idx2] > dist2[i]) ? idx2 : i;

  cout << idx2 << endl;
  st = 2, en = n;
  ans[idx2] = 1;
  dfs3(0, idx2);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}