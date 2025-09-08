#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define MOD 1000000007
ll arr[100005],tree[400005];
pll lazy[400005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=arr[st];
  ll mid=(st+en)>>1;
  return tree[node]=(init(node<<1,st,mid)+init(node<<1|1,mid+1,en))%MOD;
}
void update_lazy(ll node,ll st,ll en)
{
  pll zero={1,0},t=lazy[node];
  if(t==zero) return;
  tree[node]=(tree[node]*t.F+(en-st+1)*t.S)%MOD;
  if(st!=en)
  {
    pll t1=lazy[node<<1],t2=lazy[node<<1|1];
    lazy[node<<1]={(t1.F*t.F)%MOD,(t1.S*t.F+t.S)%MOD};
    lazy[node<<1|1]={(t2.F*t.F)%MOD,(t2.S*t.F+t.S)%MOD};
  }
  lazy[node]=zero;
}
void update_range(ll node,ll st,ll en,ll l,ll r,pll val)
{
  update_lazy(node,st,en);
  if(en<l || r<st) return;
  if(l<=st && en<=r)
  {
    tree[node]=(tree[node]*val.F+(en-st+1)*val.S)%MOD;
    if(st!=en)
    {
      pll t1=lazy[node<<1],t2=lazy[node<<1|1];
      lazy[node<<1]={(t1.F*val.F)%MOD,(t1.S*val.F+val.S)%MOD};
      lazy[node<<1|1]={(t2.F*val.F)%MOD,(t2.S*val.F+val.S)%MOD};
    }
    return;
  }
  ll mid=(st+en)>>1;
  update_range(node<<1,st,mid,l,r,val); update_range(node<<1|1,mid+1,en,l,r,val);
  tree[node]=(tree[node<<1]+tree[node<<1|1])%MOD;
}
ll query(ll node,ll st,ll en,ll l,ll r)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return (query(node<<1,st,mid,l,r)+query(node<<1|1,mid+1,en,l,r))%MOD;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<=4*n; i++) lazy[i]={1,0};
  init(1,1,n);
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b,c,d=0;
    cin>>a>>b>>c;
    if(a!=4) cin>>d;
    if(a==1) update_range(1,1,n,b,c,{1,d});
    else if(a==2) update_range(1,1,n,b,c,{d,0});
    else if(a==3) update_range(1,1,n,b,c,{0,d});
    else cout<<query(1,1,n,b,c)<<endl;
  }
  return 0;
}