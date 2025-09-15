#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<ll> adj[500005];
ll par[500005],in[500005],out[500005],arr[500005],brr[500005];
ll tree[2000005],lazy[2000005];
ll cnt;
void dfs(ll x=1)
{
  in[x]=++cnt;
  for(auto y:adj[x]) dfs(y);
  out[x]=cnt;
}
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=brr[st];
  ll mid=(st+en)>>1;
  return tree[node]=init(node<<1,st,mid)+init(node<<1|1,mid+1,en);
}
void ulazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  tree[node]+=(en-st+1)*lazy[node];
  if(st!=en)
  {
    lazy[node<<1]+=lazy[node];
    lazy[node<<1|1]+=lazy[node];
  }
  lazy[node]=0;
}
void urange(ll node,ll st,ll en,ll l,ll r,ll v)
{
  ulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node]+=(en-st+1)*v;
    if(st!=en)
    {
      lazy[node<<1]+=v;
      lazy[node<<1|1]+=v;
    }
    return;
  }
  ll mid=(st+en)>>1;
  urange(node<<1,st,mid,l,r,v); urange(node<<1|1,mid+1,en,l,r,v);
}
ll query(ll node,ll st,ll en,ll idx)
{
  ulazy(node,st,en);
  if(idx<st || en<idx) return 0;
  if(st==en) return tree[node];
  ll mid=(st+en)>>1;
  return query(node<<1,st,mid,idx)+query(node<<1|1,mid+1,en,idx);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  cin>>arr[1];
  for(int i=2; i<=n; i++)
  {
    ll a;
    cin>>arr[i]>>a;
    par[i]=a;
    adj[a].push_back(i);
  }
  dfs();
  for(int i=1; i<=n; i++) brr[in[i]]=arr[i];
  init(1,1,n);
  while(m--)
  {
    char c;
    ll a,b=0;
    cin>>c>>a;
    if(c=='p') cin>>b;
    if(c=='p') for(auto y:adj[a]) urange(1,1,n,in[y],out[y],b);
    else cout<<query(1,1,n,in[a])<<endl;
  }
  return 0;
}