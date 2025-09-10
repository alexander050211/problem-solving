#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pair<pll,ll> arr[100005];
vector<ll> adj[100005],bdj[100005];
ll par[100005],in[100005],out[100005],edg[100005];
bool visited[100005];
pll tree[400005];
ll lazy[400005];
ll cnt;
void dfs(ll x=1)
{
  visited[x]=true;
  in[x]=++cnt;
  for(auto y:adj[x])
  {
    if(visited[y]) continue;
    par[y]=x;
    bdj[x].pb(y);
    dfs(y);
  }
  out[x]=cnt;
}
pll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={0,1};
  ll mid=(st+en)>>1;
  init(node<<1,st,mid); init(node<<1|1,mid+1,en);
  return tree[node]={0,en-st+1};
}
void update_lazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  tree[node].F+=lazy[node];
  if(st!=en)
  {
    lazy[node<<1]+=lazy[node];
    lazy[node<<1|1]+=lazy[node];
  }
  lazy[node]=0;
}
void update_range(ll node,ll st,ll en,ll l,ll r,ll v)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node].F+=v;
    if(st!=en)
    {
      lazy[node<<1]+=v;
      lazy[node<<1|1]+=v;
    }
    return;
  }
  ll mid=(st+en)>>1;
  update_range(node<<1,st,mid,l,r,v); update_range(node<<1|1,mid+1,en,l,r,v);
  if(tree[node<<1].F==tree[node<<1|1].F) tree[node]={tree[node<<1].F,tree[node<<1].S+tree[node<<1|1].S};
  else tree[node]=(tree[node<<1].F<tree[node<<1|1].F)?tree[node<<1]:tree[node<<1|1];
}
pll query(ll node,ll st,ll en,ll l,ll r)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return {(ll)1e9,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  pll t1=query(node<<1,st,mid,l,r),t2=query(node<<1|1,mid+1,en,l,r);
  if(t1.F==t2.F) return {t1.F,t1.S+t2.S};
  return (t1.F<t2.F)?t1:t2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n;
  for(int i=0; i<n-1; i++)
  {
    string s;
    cin>>arr[i].F.F>>s>>arr[i].F.S;
    arr[i].S=(s[0]=='<')?1:(s[1]=='>'?2:0);
    adj[arr[i].F.F].pb(arr[i].F.S); adj[arr[i].F.S].pb(arr[i].F.F);
  }
  dfs();
  init(1,1,n);
  for(int i=0; i<n-1; i++)
  {
    if(!arr[i].S) continue;
    if(par[arr[i].F.F]==arr[i].F.S) swap(arr[i].F.F,arr[i].F.S),arr[i].S=3-arr[i].S;
    edg[arr[i].F.S]=arr[i].S;
    if(arr[i].S==1)
    {
      if(in[arr[i].F.S]>1) update_range(1,1,n,1,in[arr[i].F.S]-1,1);
      if(out[arr[i].F.S]<n) update_range(1,1,n,out[arr[i].F.S]+1,n,1);
    }
    else if(arr[i].S==2) update_range(1,1,n,in[arr[i].F.S],out[arr[i].F.S],1);
  }
  cin>>q;
  while(q--)
  {
    string s; ll a,b;
    cin>>a>>s>>b;
    ll c=(s[0]=='<')?1:(s[1]=='>'?2:0);
    if(par[a]==b)
    {
      swap(a,b);
      if(c) c=3-c;
    }
    if(edg[b]==1) 
    {
      if(in[b]>1) update_range(1,1,n,1,in[b]-1,-1);
      if(out[b]<n) update_range(1,1,n,out[b]+1,n,-1);
    }
    else if(edg[b]==2) update_range(1,1,n,in[b],out[b],-1);
    if(c==1)
    {
      if(in[b]>1) update_range(1,1,n,1,in[b]-1,1);
      if(out[b]<n) update_range(1,1,n,out[b]+1,n,1);
    }
    else if(c==2) update_range(1,1,n,in[b],out[b],1);
    edg[b]=c;
    pll ans=query(1,1,n,1,n);
    cout<<(ans.F?0:ans.S)<<endl;
  }
  return 0;
}