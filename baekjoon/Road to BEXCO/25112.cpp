#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
ll arr[200005],tree[800005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=arr[st];
  ll mid=(st+en)>>1;
  return tree[node]=init(node<<1,st,mid)+init(node<<1|1,mid+1,en);
}
void update(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]=arr[st]=v;
    return;
  }
  ll mid=(st+en)>>1;
  update(node<<1,st,mid,idx,v); update(node<<1|1,mid+1,en,idx,v);
  tree[node]=tree[node<<1]+tree[node<<1|1];
}
ll query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return query(node<<1,st,mid,l,r)+query(node<<1|1,mid+1,en,l,r);
}
ll f(ll x,ll n)
{
  ll st=1,en=n-1;
  while(st<en)
  {
    ll mid=(st+en)>>1;
    if(query(1,0,n-1,0,mid)<x) st=mid+1;
    else en=mid;
  }
  return st;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  n--;
  for(int i=0; i<n; i++) cin>>arr[i];
  ll sum=0;
  for(int i=0; i<n; i++) sum+=arr[i];
  init(1,0,n-1);
  ll idx=f((sum+1)/2,n);
  ll ans=min(llabs(sum-2*query(1,0,n-1,0,idx)),llabs(sum-2*query(1,0,n-1,0,idx-1)));
  cout<<ans<<endl;
  ll t;
  cin>>t;
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    sum+=b-arr[a-1];
    update(1,0,n-1,a-1,b);
    idx=f((sum+1)/2,n);
    ans=min(llabs(sum-2*query(1,0,n-1,0,idx)),llabs(sum-2*query(1,0,n-1,0,idx-1)));
    cout<<ans<<endl;
  }
  return 0;
}