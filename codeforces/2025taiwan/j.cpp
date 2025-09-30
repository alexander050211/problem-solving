#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,k;
vector<pll> adj[200005],bdj[200005];
pll dp[200005];
ll par[200005];
bool visited[200005];
void dfs1(ll x)
{
  visited[x]=true;
  for(auto y:adj[x])
  {
    if(visited[y.F])
    {
      par[x]=y.S;
      continue;
    }
    bdj[x].pb(y);
    dfs1(y.F);
  }
}
ll cnt=0;
void dfs2(ll x,ll prev,ll m)
{
  if(bdj[x].empty()) return;
  for(auto y:bdj[x]) dfs2(y.F,x,m);
  ll t1=0,t2=0;
  for(auto y:bdj[x])
  {
    ll temp=dp[y.F].S+y.S;
    if(temp>=t1)
    {
      t2=t1,t1=temp;
    }
    else if(temp>=t2)
    {
      t2=temp;
    }
  }
  dp[x]={t1+t2,t1};
  if(dp[x].F>m || t1+par[x]>m)
  {
    cnt++;
    dp[x]={0,0};
  }
}
bool f(ll m)
{
  cnt=0;
  for(int i=1; i<=n; i++) dp[i]={0,0};
  dfs2(1,0,m);
  if(cnt>k) return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>k;
  ll st=1,en=(ll)2e14;
  for(int i=1; i<n; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    adj[a].pb({b,c});
    adj[b].pb({a,c});
    st=max(st,c);
  }
  dfs1(1);
  while(st<en)
  {
    if(en-st==1)
    {
      if(!f(st)) st++;
      break;
    }
    ll mid=(st+en)>>1;
    if(f(mid)) en=mid;
    else st=mid+1;
  }
  cout<<st<<endl;
  return 0;
}