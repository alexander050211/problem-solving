#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
ll n;
ll par[200005],dep[200005],in[200005],out[200005],top[200005],sz[200005];
vector<ll> adj[200005];
void dfs1(ll x)
{
  sz[x]=1;
  for(auto& y:adj[x])
  {
    dep[y]=dep[x]+1;
    dfs1(y);
    sz[x]+=sz[y];
    if(sz[y]>sz[adj[x][0]]) swap(y,adj[x][0]);
  }
}
ll cnt;
void dfs2(ll x)
{
  in[x]=++cnt;
  for(auto y:adj[x])
  {
    top[y]=(y==adj[x][0])?top[x]:y;
    dfs2(y);
  }
  out[x]=cnt;
}
bool tree[800005];
bool init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=(st!=1);
  ll mid=(st+en)>>1;
  return tree[node]=init(node*2,st,mid)*init(node*2+1,mid+1,en);
}
void tupdate(ll node,ll st,ll en,ll idx)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]=false;
    return;
  }
  ll mid=(st+en)>>1;
  tupdate(node*2,st,mid,idx); tupdate(node*2+1,mid+1,en,idx);
  tree[node]=tree[node*2]*tree[node*2+1];
}
bool tquery(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return true;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return tquery(node*2,st,mid,l,r)*tquery(node*2+1,mid+1,en,l,r);
}
bool query(ll a,ll b)
{
  bool ret=true;
  while(top[a]!=top[b])
  {
    if(dep[top[a]]<dep[top[b]]) swap(a,b);
    ll temp=top[a];
    ret*=tquery(1,1,n,in[temp],in[a]);
    a=par[temp];
  }
  if(dep[a]>dep[b]) swap(a,b);
  ret*=tquery(1,1,n,in[a]+1,in[b]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll q;
  cin>>n>>q;
  for(int i=2; i<=n; i++)
  {
    cin>>par[i];
    adj[par[i]].pb(i);
  }
  dfs1(1); dfs2(1);
  init(1,1,n);
  while(q--)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    bool temp=query(a,b);
    cout<<(temp?"YES":"NO")<<endl;
    if(!c) continue;
    if(temp) tupdate(1,1,n,in[a]);
    else tupdate(1,1,n,in[b]);
  }
  return 0;
}