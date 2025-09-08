#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
ll n;
ll arr[100005];
ll sz[100005],dep[100005],par[100005],in[100005],top[100005];
vector<ll> adj[100005],bdj[100005];
bool visited[100005];
void dfs(ll x=1)
{
  visited[x]=true;
  for(auto y:adj[x])
  {
    if(visited[y]) continue;
    bdj[x].pb(y);
    dfs(y);
  }
}
void dfs1(ll x=1)
{
  sz[x]=1;
  for(auto& y:bdj[x])
  {
    dep[y]=dep[x]+1;
    par[y]=x;
    dfs1(y);
    sz[x]+=sz[y];
    if(sz[y]>sz[bdj[x][0]]) swap(y,bdj[x][0]);
  }
}
ll cnt;
void dfs2(ll x=1)
{
  in[x]=++cnt;
  for(auto y:bdj[x])
  {
    top[y]=(y==bdj[x][0])?top[x]:y;
    dfs2(y);
  }
}
ll brr[100005],tree[400005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=brr[st];
  ll mid=(st+en)>>1;
  return tree[node]=init(node*2,st,mid)^init(node*2+1,mid+1,en);
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
  tree[node]=tree[node*2]^tree[node*2+1];
}
ll tquery(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return tquery(node*2,st,mid,l,r)^tquery(node*2+1,mid+1,en,l,r);
}
ll query(ll a,ll b)
{
  ll ret=0;
  while(top[a]!=top[b])
  {
    if(dep[top[a]]<dep[top[b]]) swap(a,b);
    ret^=tquery(1,1,n,in[top[a]],in[a]);
    a=par[top[a]];
  }
  if(dep[a]>dep[b]) swap(a,b);
  ret^=tquery(1,1,n,in[a],in[b]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll q;
  cin>>n>>q;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<n; i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b); adj[b].pb(a);
  }
  top[1]=1;
  dfs(); dfs1(); dfs2();
  for(int i=1; i<=n; i++) brr[in[i]]=arr[i];
  init(1,1,n);
  while(q--)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==1) tupdate(1,1,n,in[b],c);
    else cout<<query(b,c)<<endl;
  }
  return 0;
}