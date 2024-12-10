#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define INF (ll)1e16
ll n, m, k;
vector<pll> adj[100005];
ll brr[100005];
vector<ll> dijkstra(ll x)
{
  vector<ll> dist(n + 1, INF);
  priority_queue<pll> pq;
  dist[x] = 0;
  pq.push({0, x});
  while (!pq.empty())
  {
    ll cost = -pq.top().F;
    ll idx = pq.top().S;
    pq.pop();
    if (dist[idx] < cost)
      continue;
    for (int i = 0; i < adj[idx].size(); i++)
    {
      ll next = adj[idx][i].F;
      ll nc = adj[idx][i].S;
      if (dist[next] > cost + nc)
      {
        dist[next] = cost + nc;
        pq.push({-dist[next], next});
      }
    }
  }
  return dist;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  for (int i = 1; i <= n; i++)
    cin >> brr[i];
  vector<ll> dist1 = dijkstra(1);
  vector<ll> dist2 = dijkstra(n);
  ll ans = (ll)1e18;
  for (int i = 1; i <= n; i++)
  {
    if (brr[i] == -1)
      continue;
    if (dist1[i] == INF || dist2[i] == INF)
      continue;
    ll temp = (k - 1) * brr[i] + dist1[i] + dist2[i];
    ans = min(ans, temp);
  }
  if (ans == (ll)1e18)
    ans = -1;
  cout << ans << endl;
  return 0;
}