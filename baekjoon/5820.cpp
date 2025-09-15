#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> adj[200005];
ll sz[200005],cost[1000005];
bool visited[200005];
ll n,k;
ll ans=(ll)1e9;

ll get_sz(ll x,ll par)
{
  sz[x]=1;
  for(auto y:adj[x])
  {
    if(visited[y.F] || y.F==par) continue;
    sz[x]+=get_sz(y.F,x);
  }
  return sz[x];
}
ll get_cent(ll x,ll par,ll s)
{
  for(auto y:adj[x])
    if(y.F!=par && !visited[y.F] && sz[y.F]*2>s)
      return get_cent(y.F,x,s);
  return x;
}
void dfs(ll x,ll par,ll dep,ll len,vector<pll>& temp)
{
  if(len>k) return;
  temp.pb(mp(dep,len));
  for(auto y:adj[x])if(y.F!=par && !visited[y.F])
    dfs(y.F,x,dep+1,len+y.S,temp);
}
void dnc(ll x)
{
  ll cent=get_cent(x,-1,get_sz(x,-1));
  vector<ll> check;
  for(auto y:adj[cent])
  {
    if(visited[y.F]) continue;
    vector<pll> temp;
    dfs(y.F,cent,1,y.S,temp);
    for(auto p:temp) ans=min(ans,cost[k-p.S]+p.F);
    for(auto p:temp)
    {
      check.pb(p.S);
      cost[p.S]=min(cost[p.S],p.F);
    }
  }
  for(auto y:check) cost[y]=(ll)1e9;
  visited[cent]=true;
  for(auto y:adj[cent])if(!visited[y.F]) dnc(y.F);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>k;
  for(int i=1; i<n; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    adj[a].pb(mp(b,c)); adj[b].pb(mp(a,c));
  }
  for(int i=1; i<=k; i++) cost[i]=(ll)1e9;
  dnc(0);
  cout<<((ans==(ll)1e9)?-1:ans)<<endl;
  return 0;
}