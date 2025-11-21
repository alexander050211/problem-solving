#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> adj[100005];
ll dp[100005][4];
ll deg[100005];
ll idx;
void dfs(ll par,ll x,ll d)
{
  if(deg[x]==1)
  {
    dp[x][0]=0;
    dp[x][1]=d*d;
    dp[x][2]=d;
    dp[x][3]=1;
    return;
  }
  pll y,z;
  if(par==adj[x][0].F) y=adj[x][1],z=adj[x][2];
  else if(par==adj[x][1].F) y=adj[x][0],z=adj[x][2];
  else y=adj[x][0],z=adj[x][1];
  dfs(x,y.F,y.S); dfs(x,z.F,z.S);
  dp[x][0]=dp[y.F][0]+dp[z.F][0]+dp[y.F][1]*dp[z.F][3]+dp[z.F][1]*dp[y.F][3]+2*dp[y.F][2]*dp[z.F][2];
  dp[x][1]=dp[y.F][1]+dp[z.F][1]+2*d*(dp[y.F][2]+dp[z.F][2])+d*d*(dp[y.F][3]+dp[z.F][3]);
  dp[x][2]=dp[y.F][2]+dp[z.F][2]+d*(dp[y.F][3]+dp[z.F][3]);
  dp[x][3]=dp[y.F][3]+dp[z.F][3];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=1; i<n; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    adj[a].pb({b,c}); adj[b].pb({a,c});
    deg[a]++; deg[b]++;
  }
  idx=1;
  while(deg[idx]>1) idx++;
  dfs(idx,adj[idx][0].F,adj[idx][0].S);
  ll x=adj[idx][0].F;
  cout<<dp[x][0]+dp[x][1]<<endl;
  return 0;
}