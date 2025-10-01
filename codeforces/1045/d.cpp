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
ll deg[200005],par[200005],dist[200005];
void dfs(ll x,ll prev)
{
  for(auto y:adj[x])
  {
    if(y==prev) continue;
    par[y]=x;
    dist[y]=dist[x]+1;
    dfs(y,x);
  }
}
void solve()
{
  ll n;
  cin>>n;
  for(int i=1; i<n; i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b); adj[b].pb(a);
    deg[a]++; deg[b]++;
  }
  ll x1=1;
  for(int i=2; i<=n; i++)if(deg[i]==1) x1=i;
  dfs(x1,0);
  ll x2=x1;
  for(int i=1; i<=n; i++)if(dist[i]>dist[x2]) x2=i;
  for(int i=1; i<=n; i++) dist[i]=0;
  dfs(x2,0);
  ll x3=x2;
  for(int i=1; i<=n; i++)if(dist[i]>dist[x3]) x3=i;
  if(dist[x3]==n-1)
  {
    cout<<-1<<endl;
    for(int i=1; i<=n; i++)
    {
      adj[i].clear();
      deg[i]=par[i]=dist[i]=0;
    }
    return;
  }
  for(int i=x3; par[i]!=x2; i=par[i])
  {
    ll j=par[i];
    if(deg[j]>2)
    {
      ll k;
      for(auto x:adj[j])if(x!=i && x!=par[j]) k=x;
      cout<<i<<' '<<j<<' '<<k<<endl;
      break;
    }
  }
  for(int i=1; i<=n; i++)
  {
    adj[i].clear();
    deg[i]=par[i]=dist[i]=0;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tt=1;
  cin>>tt;
  while(tt--)
  {
    solve();
  }
  return 0;
}