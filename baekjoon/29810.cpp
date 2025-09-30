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
ll xx,temp;
bool check[200005];
ll arr[200005],ccnt[200005],ccnt2[200005];
void dfs1(ll x,ll cnt)
{
  arr[x]=cnt;
  for(auto y:adj[x])
  {
    if(arr[y] || y==xx) continue;
    dfs1(y,cnt);
  }
}
void dfs2(ll x,ll cnt)
{
  arr[x]=cnt;
  ccnt[cnt]++;
  for(auto y:adj[x])
  {
    if(arr[y]) continue;
    dfs2(y,cnt);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  cin>>xx;
  ll cnt=0;
  for(auto y:adj[xx])if(!arr[y])dfs1(y,++cnt);
  for(int i=1; i<=n; i++)ccnt[arr[i]]++;
  for(auto y:adj[xx])ccnt2[arr[y]]++;
  ll ans=1;
  for(int i=1; i<=cnt; i++)if(ccnt2[i]==1) ans=max(ans,ccnt[i]+1);
  for(int i=1; i<=cnt; i++)if(ccnt2[i]>1) ans=max(ans,ccnt[i]);
  ll cnt2=cnt;
  for(int i=1; i<=n; i++)if(i!=xx && !arr[i]) dfs2(i,++cnt);
  for(int i=cnt2+1; i<=cnt; i++) ans=max(ans,ccnt[i]);
  cout<<ans<<endl;
  return 0;
}