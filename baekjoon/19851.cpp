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
//we need min of prefix sum, and range sum
struct Node
{
  ll sl,sm,ss;
};
ll arr[1000005],lazy[4000005];
Node tree[4000005];
inline Node f(Node a,Node b)
{
  return {min(a.sl,a.ss+b.sl),max(a.sm,a.ss+b.sm),a.ss+b.ss};
}
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={arr[st],arr[st],arr[st]};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void ulazy(ll node,ll st,ll en)
{
  if(lazy[node]==1) return;
  tree[node]={-tree[node].sm,-tree[node].sl,-tree[node].ss};
  if(st!=en)
  {
    lazy[node<<1]*=lazy[node];
    lazy[node<<1|1]*=lazy[node];
  }
  lazy[node]=1;
}
void urange(ll node,ll st,ll en,ll l,ll r)
{
  ulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node]={-tree[node].sm,-tree[node].sl,-tree[node].ss};
    if(st!=en)
    {
      lazy[node<<1]*=-1;
      lazy[node<<1|1]*=-1;
    }
    return;
  }
  ll mid=(st+en)>>1;
  urange(node<<1,st,mid,l,r); urange(node<<1|1,mid+1,en,l,r);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  ulazy(node,st,en);
  if(r<st || en<l) return {INF,-INF,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  string s;
  cin>>n>>s;
  for(int i=0; i<n; i++) arr[i]=(s[i]=='(')?1:-1;
  for(int i=0; i<4*n; i++) lazy[i]=1;
  init(1,0,n-1);
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==1) urange(1,0,n-1,b-1,c-1);
    else
    {
      Node temp=query(1,0,n-1,b-1,c-1);
      ll sum=temp.ss;
      ll sl=temp.sl;
      ll ans=(temp.sl<0)?-temp.sl:0;
      sum+=ans;
      ans+=llabs(sum);
      cout<<ans+(c-b+1)<<endl;
    }
  }
  return 0;
}