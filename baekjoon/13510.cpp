#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n;
ll sz[100005],par[100005],depth[100005],in[100005],out[100005],top[100005];
vector<ll> children[100005];
vector<pll> adj[100005];
bool visited[100005];
ll u[100005],v[100005],w[100005];
void dfs(ll x)
{
  visited[x]=true;
  for(auto y:adj[x])
  {
    if(visited[y.F]) continue;
    children[x].pb(y.F);
    dfs(y.F);
  }
}
void dfs1(ll x)
{
  sz[x]=1;
  for(auto& y:children[x])
  {
    depth[y]=depth[x]+1;
    par[y]=x;
    dfs1(y);
    sz[x]+=sz[y];
    if(sz[y]>sz[children[x][0]]) swap(y,children[x][0]);
  }
}
ll cnt;
void dfs2(ll x)
{
  in[x]=++cnt;
  for(auto y:children[x])
  {
    top[y]=(y==children[x][0])?top[x]:y;
    dfs2(y);
  }
  out[x]=cnt;
}
ll arr[100005],tree[400005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=arr[st];
  ll mid=(st+en)>>1;
  return tree[node]=max(init(node*2,st,mid),init(node*2+1,mid+1,en));
}
void tupdate(ll node,ll st,ll en,ll idx,ll val)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]=val;
    return;
  }
  ll mid=(st+en)>>1;
  tupdate(node*2,st,mid,idx,val); tupdate(node*2+1,mid+1,en,idx,val);
  tree[node]=max(tree[node*2],tree[node*2+1]);
}
ll tquery(ll node,ll st,ll en,ll l,ll r)
{
  if(en<l || r<st) return -1;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return max(tquery(node*2,st,mid,l,r),tquery(node*2+1,mid+1,en,l,r));
}
ll query(ll a,ll b)
{
  ll ret=-1;
  while(top[a]!=top[b])
  {
    if(depth[top[a]]<depth[top[b]]) swap(a,b);
    ll temp=top[a];
    ret=max(ret,tquery(1,1,n,in[temp],in[a]));
    a=par[temp];
  }
  if(depth[a]>depth[b]) swap(a,b);
  ret=max(ret,tquery(1,1,n,in[a]+1,in[b]));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll m;
  cin>>n;
  for(int i=1; i<n; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    u[i]=a,v[i]=b,w[i]=c;
    adj[a].pb({b,c});
    adj[b].pb({a,c});
  }
  dfs(1); dfs1(1); dfs2(1);
  for(int i=1; i<n; i++)
  {
    ll a=u[i],b=v[i],c=w[i];
    if(par[a]==b) swap(a,b);
    arr[in[b]]=c;
  }
  init(1,1,n);
  cin>>m;
  while(m--)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==1)
    {
      ll t1=u[b],t2=v[b];
      if(par[t1]==t2) swap(t1,t2);
      tupdate(1,1,n,in[t2],c);
    }
    else cout<<query(b,c)<<endl;
  }
  return 0;
}