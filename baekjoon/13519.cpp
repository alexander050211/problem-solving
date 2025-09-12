#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const ll INF=0;
ll arr[100005];
vector<ll> adj[100005],bdj[100005];
ll dep[100005],sz[100005],par[100005],in[100005],top[100005];
bool visited[100005];
ll n;
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
struct Node
{
  ll ls,rs,as,ss;
};
Node tree[400005];
ll brr[100005],lazy[400005];
void print(Node x)
{
  cout<<x.ls<<' '<<x.rs<<' '<<x.as<<' '<<x.ss<<endl;
}
Node f(Node a,Node b)
{
  return {max(a.ls,a.ss+b.ls),max(b.rs,a.rs+b.ss),max({a.as,b.as,a.rs+b.ls}),a.ss+b.ss};
}
Node init(ll node,ll st,ll en)
{
  if(st==en)
  {
    if(brr[st]>0) return tree[node]={brr[st],brr[st],brr[st],brr[st]};
    return tree[node]={0,0,0,brr[st]};
  }
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void tulazy(ll node,ll st,ll en)
{
  if(lazy[node]==10001) return;
  ll temp=(en-st+1)*lazy[node];
  if(lazy[node]>0) tree[node]={temp,temp,temp,temp};
  else tree[node]={0,0,0,temp};
  if(st!=en) lazy[node<<1]=lazy[node<<1|1]=lazy[node];
  lazy[node]=10001;
}
void tupdate(ll node,ll st,ll en,ll l,ll r,ll v)
{
  tulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    ll temp=(en-st+1)*v;
    if(v>0) tree[node]={temp,temp,temp,temp};
    else tree[node]={0,0,0,temp};
    if(st!=en) lazy[node<<1]=lazy[node<<1|1]=v;
    return;
  }
  ll mid=(st+en)>>1;
  tupdate(node<<1,st,mid,l,r,v); tupdate(node<<1|1,mid+1,en,l,r,v);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node tquery(ll node,ll st,ll en,ll l,ll r)
{
  tulazy(node,st,en);
  if(r<st || en<l) return {-INF,-INF,-INF,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(tquery(node<<1,st,mid,l,r),tquery(node<<1|1,mid+1,en,l,r));
}
void update(ll a,ll b,ll v)
{
  while(top[a]!=top[b])
  {
    if(dep[top[a]]<dep[top[b]]) swap(a,b);
    tupdate(1,1,n,in[top[a]],in[a],v);
    a=par[top[a]];
  }
  if(dep[a]>dep[b]) swap(a,b);
  tupdate(1,1,n,in[a],in[b],v);
}
ll query(ll a,ll b)
{
  Node ret1={-INF,-INF,-INF,0},ret2={-INF,-INF,-INF,0};
  while(top[a]!=top[b])
  {
    Node temp;
    //cout<<a<<' '<<b<<endl;
    if(dep[top[a]]<dep[top[b]])
    {
      temp=tquery(1,1,n,in[top[b]],in[b]);
      ret2=f(temp,ret2);
      b=par[top[b]];
    }
    else
    {
      temp=tquery(1,1,n,in[top[a]],in[a]);
      ret1=f(temp,ret1);
      a=par[top[a]];
    }
    //cout<<a<<' '<<b<<endl;
    //print(ret1); print(ret2);
    //cout<<endl;
  }
  if(dep[a]>dep[b]) ret1=f(tquery(1,1,n,in[b],in[a]),ret1);
  else ret2=f(tquery(1,1,n,in[a],in[b]),ret2);
  //print(ret1); print(ret2);
  swap(ret1.ls,ret1.rs);
  //print(f(ret1,ret2));
  return f(ret1,ret2).as;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
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
  for(int i=1; i<=4*n; i++) lazy[i]=10001;
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b,c,d=0;
    cin>>a>>b>>c;
    if(a==2) cin>>d;
    if(a==1) cout<<query(b,c)<<endl;
    else update(b,c,d);
  }
  return 0;
}