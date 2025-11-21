#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
vector<ll> adj[200005];
ll n,m,k;
vector<ll> dijk() {
  vector<ll> dist(n+1,INF);
  priority_queue<pll> pq;
  dist[1]=0;
  pq.push({1,0});
  while(!pq.empty()) {
    auto [idx,cost]=pq.top();
    cost=-cost;
    pq.pop();
    for(int i=0; i<adj[idx].size(); i++) {
      ll nxt=adj[idx][i];
      if(cost+1>=dist[nxt]) continue;
      dist[nxt]=cost+1;
      pq.push({nxt,-dist[nxt]});
    }
  }
  return dist;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>k;
  vector<ll> arr(n+1);
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=0; i<m; i++) {
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b); adj[b].pb(a);
  }
  vector<ll> dist=dijk();
  vector<ll> ans(k+1,0);
  for(int i=1; i<=n; i++) ans[arr[i]]=max(ans[arr[i]],dist[i]);
  for(int i=1; i<=k; i++) cout<<ans[i]<<' ';
  cout<<endl;
  return 0;
}