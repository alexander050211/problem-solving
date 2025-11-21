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
vector<ll> adj[100005];
vector<ll> ans;
bool visited[100005];
void dfs(ll x)
{
  ans.pb(x);
  visited[x]=true;
  for(int i=0; i<adj[x].size(); i++)if(!visited[adj[x][i]]) dfs(adj[x][i]);
}
void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<ll> cnt(n,0);
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a-1].pb(b-1);
    cnt[a-1]--,cnt[b-1]++;
  }
  ll idx=0;
  for(int i=1; i<n; i++)if(cnt[i]<cnt[idx]) idx=i;
  for(int i=0; i<n; i++)sort(all(adj[i]),[&](ll a,ll b){return cnt[a]<cnt[b];});
  dfs(idx);
  for(auto x:ans) cout<<x+1<<' ';
  cout<<endl;
  for(int i=0; i<n; i++) adj[i].clear(),visited[i]=false;
  ans.clear();
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