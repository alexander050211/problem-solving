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
ll deg[200005],sz[200005],dep[200005];
void dfs(ll x,ll prev)
{
  sz[x]=1;
  for(auto y:adj[x])
  {
    if(y==prev) continue;
    dfs(y,x);
    sz[x]+=sz[y];
  }
}
ll find_cent(ll x,ll prev,ll n)
{
  for(auto y:adj[x])
  {
    if(y==prev) continue;
    if(sz[y]*2>=n) return find_cent(y,x,sz[y]);
  }
  return x;
}
void dfs2(ll x,ll prev)
{
  for(auto y:adj[x])
  {
    if(y==prev) continue;
    dfs2(y,x);
    dep[x]=max(dep[x],dep[y]+1);
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
  bool flag=true;
  for(int i=1; i<=n; i++)if(deg[i]>2) flag=false;
  if(flag || n<=2)
  {
    cout<<-1<<endl;
    for(int i=1; i<=n; i++) deg[i]=sz[i]=dep[i]=0;
    for(int i=1; i<=n; i++) adj[i].clear();
    return;
  }
  dfs(1,0);
  ll cent=find_cent(1,0,n);
  dfs2(cent,0);
  ll a=adj[cent][0],b=cent,c=adj[cent][1];
  for(int i=2; i<adj[cent].size(); i++)
  {
    if(dep[adj[cent][i]]>dep[a]) a=adj[cent][i];
    else if(dep[adj[cent][i]]<dep[c]) c=adj[cent][i];
  }
  cout<<a<<' '<<b<<' '<<c<<endl;
  for(int i=1; i<=n; i++) deg[i]=sz[i]=dep[i]=0;
  for(int i=1; i<=n; i++) adj[i].clear();
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