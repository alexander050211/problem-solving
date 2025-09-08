#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,q;
ll arr[30005],brr[30005];
vector<pair<ll,pll>> queries;
vector<ll> adj[30005],bdj[30005];
ll dep[30005],sz[30005],par[30005],in[30005],top[30005];
bool visited[30005];
ll cp[30005];
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
  visited[x]=true;
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
  visited[x]=true;
  for(auto y:bdj[x])
  {
    top[y]=(y==bdj[x][0])?top[x]:y;
    dfs2(y);
  }
}
ll fin(ll x)
{
  if(cp[x]==x) return x;
  return cp[x]=fin(cp[x]);
}
ll tree[120005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=brr[st];
  ll mid=(st+en)>>1;
  return tree[node]=init(node*2,st,mid)+init(node*2+1,mid+1,en);
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
  tree[node]=tree[node*2]+tree[node*2+1];
}
ll tquery(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return tquery(node*2,st,mid,l,r)+tquery(node*2+1,mid+1,en,l,r);
}
ll query(ll a,ll b)
{
  ll ret=0;
  while(top[a]!=top[b])
  {
    if(dep[top[a]]<dep[top[b]]) swap(a,b);
    ret+=tquery(1,1,n,in[top[a]],in[a]);
    a=par[top[a]];
  }
  if(dep[a]>dep[b]) swap(a,b);
  ret+=tquery(1,1,n,in[a],in[b]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<=n; i++) cp[i]=i;
  cin>>q;
  queries.resize(q);
  for(int i=0; i<q; i++)
  {
    string s;
    ll a,b,c=0;
    cin>>s>>a>>b;
    if(s=="bridge")
    {
      c=1;
      if(fin(a)!=fin(b))
      {
        adj[a].pb(b),adj[b].pb(a);
        cp[fin(a)]=fin(b);
      }
    }
    else if(s=="penguins") c=2;
    else if(s=="excursion") c=3;
    queries[i]={c,{a,b}};
  }
  for(int i=1; i<=n; i++) cp[i]=i;
  for(int i=1; i<=n; i++)if(!visited[i])dfs(i);
  for(int i=1; i<=n; i++) visited[i]=false;
  for(int i=1; i<=n; i++)if(!visited[i])dfs1(i);
  for(int i=1; i<=n; i++) visited[i]=false;
  for(int i=1; i<=n; i++)
  {
    if(visited[i]) continue;
    top[i]=i;
    dfs2(i);
  }
  for(int i=1; i<=n; i++) brr[in[i]]=arr[i];
  init(1,1,n);
  for(int i=0; i<q; i++)
  {
    auto temp=queries[i];
    if(temp.F==1)
    {
      ll a=temp.S.F,b=temp.S.S;
      if(fin(a)==fin(b)) cout<<"no"<<endl;
      else
      {
        cout<<"yes"<<endl;
        cp[fin(a)]=fin(b);
      }
    }
    else if(temp.F==2) tupdate(1,1,n,in[temp.S.F],temp.S.S);
    else
    {
      ll a=temp.S.F,b=temp.S.S;
      if(fin(a)!=fin(b))
      {
        cout<<"impossible"<<endl;
        continue;
      }
      cout<<query(a,b)<<endl;
    }
  }
  return 0;
}