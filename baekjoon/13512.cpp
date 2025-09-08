#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
const ll INF=(ll)1e9;
ll n;
ll dep[100005],par[100005],sz[100005],in[100005],out[100005],top[100005];
bool visited[100005];
vector<ll> adj[100005],bdj[100005];
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
  out[x]=cnt;
}
ll tree[400005];
inline ll f(ll a,ll b)
{
  if(a==INF) return b;
  if(b==INF) return a;
  if(dep[a]!=dep[b]) return (dep[a]<dep[b])?a:b;
  return min(a,b);
}
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=INF;
  ll mid=(st+en)>>1;
  return tree[node]=min(init(node*2,st,mid),init(node*2+1,mid+1,en));
}
void tupdate(ll node,ll st,ll en,ll idx,ll val)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]=(tree[node]==INF)?val:INF;
    return;
  }
  ll mid=(st+en)>>1;
  tupdate(node*2,st,mid,idx,val); tupdate(node*2+1,mid+1,en,idx,val);
  tree[node]=f(tree[node*2],tree[node*2+1]);
}
ll tquery(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return INF;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(tquery(node*2,st,mid,l,r),tquery(node*2+1,mid+1,en,l,r));
}
ll query(ll a,ll b)
{
  ll ret=INF;
  while(top[a]!=top[b])
  {
    if(dep[top[a]]<dep[top[b]]) swap(a,b);
    ll temp=top[a];
    ret=f(ret,tquery(1,1,n,in[temp],in[a]));
    a=par[temp];
  }
  if(dep[a]>dep[b]) swap(a,b);
  ret=f(ret,tquery(1,1,n,in[a],in[b]));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1; i<n; i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b); adj[b].pb(a);
  }
  top[1]=1;
  dfs(); dfs1(); dfs2();
  init(1,1,n);
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b;
    cin>>a>>b;
    if(a==1) tupdate(1,1,n,in[b],b);
    else
    {
      ll ans=query(1,b);
      if(ans==(ll)1e9) cout<<-1<<endl;
      else cout<<ans<<endl;
    }
  }
  return 0; 
}