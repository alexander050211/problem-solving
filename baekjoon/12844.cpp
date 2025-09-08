#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll arr[500005],tree[2000005],lazy[2000005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=arr[st];
  ll mid=(st+en)>>1;
  return tree[node]=init(node<<1,st,mid)^init(node<<1|1,mid+1,en);
}
void update_lazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  if((en-st+1)&1) tree[node]^=lazy[node];
  if(st!=en)
  {
    lazy[node<<1]^=lazy[node];
    lazy[node<<1|1]^=lazy[node];
  }
  lazy[node]=0;
}
void update_range(ll node,ll st,ll en,ll l,ll r,ll val)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    if((en-st+1)&1) tree[node]^=val;
    if(st!=en)
    {
      lazy[node<<1]^=val;
      lazy[node<<1|1]^=val;
    }
    return;
  }
  ll mid=(st+en)>>1;
  update_range(node<<1,st,mid,l,r,val); update_range(node<<1|1,mid+1,en,l,r,val);
  tree[node]=tree[node<<1]^tree[node<<1|1];
}
ll query(ll node,ll st,ll en,ll l,ll r)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return query(node<<1,st,mid,l,r)^query(node<<1|1,mid+1,en,l,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  init(1,0,n-1);
  cin>>q;
  while(q--)
  {
    ll a,b,c=0,d=0;
    cin>>a>>b;
    if(a==1) cin>>c>>d;
    if(a==1) update_range(1,0,n-1,b,c,d);
    else cout<<query(1,0,n-1,b,b)<<endl;
  }
  return 0;
}