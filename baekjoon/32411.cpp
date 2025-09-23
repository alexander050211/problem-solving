#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
struct Node
{
  ll l1,l2,ls,la;
};
ll n,q;
ll arr[100005],brr[100005];
Node tree[1<<18][11];
ll lazy[1<<18];
inline Node f(Node a,Node b)
{
  return {(a.l1==a.ls)?a.ls+b.l1:a.l1,(b.l2==b.ls)?a.l2+b.ls:b.l2,a.ls+b.ls,max({a.la,b.la,a.l2+b.l1})};
}
Node init(ll node,ll st,ll en,ll k)
{
  if(st==en)
  {
    if(llabs(brr[st])==k) return tree[node][k]={1,1,1,1};
    return tree[node][k]={0,0,1,0};
  }
  ll mid=(st+en)>>1;
  return tree[node][k]=f(init(node<<1,st,mid,k),init(node<<1|1,mid+1,en,k));
}
void upd(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    brr[st]+=v;
    for(int k=1; k<=10; k++)
    {
      if(llabs(brr[st])==k) tree[node][k]={1,1,1,1};
      else tree[node][k]={0,0,1,0};
    }
    return;
  }
  ll mid=(st+en)>>1;
  upd(node<<1,st,mid,idx,v); upd(node<<1|1,mid+1,en,idx,v);
  for(int k=1; k<=10; k++) tree[node][k]=f(tree[node<<1][k],tree[node<<1|1][k]);
}
Node query(ll node,ll st,ll en,ll l,ll r,ll k)
{
  if(r<st || en<l) return {0,0,0,0};
  if(l<=st && en<=r) return tree[node][k];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r,k),query(node<<1|1,mid+1,en,l,r,k));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>q;
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<n-1; i++) brr[i]=arr[i+1]-arr[i];
  if(n>1) for(int i=1; i<=10; i++) init(1,0,n-2,i);
  while(q--)
  {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==1)
    {
      if(b>1) upd(1,0,n-2,b-2,d);
      if(c<n) upd(1,0,n-2,c-1,-d);
    }
    else
    {
      if(b==c) cout<<1<<endl;
      else cout<<query(1,0,n-2,b-1,c-2,d).la+1<<endl;
    }
  }
  return 0;
}