#include <bits/stdc++.h>
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
ll ans[200005],sz[200005];
bool visited[200005];
bool g[200005];
vector<pair<ll,pll>> adj[200005];
void dfs(ll x,ll par)
{
  visited[x]=true;
  sz[x]=1;
  for(auto y:adj[x])
  {
    if(visited[y.F]) continue;
    dfs(y.F,x);
    sz[x]+=sz[y.F];
    if(y.S.F>y.S.S) g[y.F]=(x>y.F);
    else g[y.F]=(y.F>x);
  }
}
void dfs2(ll x,ll par,ll st,ll en)
{
  visited[x]=true;
  ll cnt1=0,cnt2=0;
  for(auto y:adj[x])
  {
    if(visited[y.F]) continue;
    if(g[y.F]) cnt1+=sz[y.F];
    else cnt2+=sz[y.F];
  }
  ans[x]=st+cnt2;
  ll t1=ans[x]-1,t2=ans[x]+1;
  for(auto y:adj[x])
  {
    if(visited[y.F]) continue;
    if(g[y.F])
    {
      dfs2(y.F,x,t2,t2+sz[y.F]-1);
      t2+=sz[y.F];
    }
    else
    {
      dfs2(y.F,x,t1-sz[y.F]+1,t1);
      t1-=sz[y.F];
    }
  }
}
void solve()
{
  ll n;
  cin>>n;
  for(int i=1; i<n; i++)
  {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    adj[a].pb({b,{c,d}});
    adj[b].pb({a,{c,d}});
  }
  dfs(1,0);
  for(int i=1; i<=n; i++) visited[i]=false;
  dfs2(1,0,1,n);
  for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
  cout<<endl;
  for(int i=1; i<=n; i++)
  {
    visited[i]=false;
    adj[i].clear();
    g[i]=false;
    ans[i]=sz[i]=0;
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