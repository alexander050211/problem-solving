#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ll;
ll tree[400005],lazy[400005];
ll init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]=2;
  ll mid=(st+en)>>1;
  return tree[node]=init(node<<1,st,mid)|init(node<<1|1,mid+1,en);
}
void ulazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  tree[node]=lazy[node];
  if(st!=en)
  {
    lazy[node<<1]=lazy[node];
    lazy[node<<1|1]=lazy[node];
  }
  lazy[node]=0;
}
void update(ll node,ll st,ll en,ll l,ll r,ll v)
{
  ulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node]=v;
    if(st!=en)
    {
      lazy[node<<1]=v;
      lazy[node<<1|1]=v;
    }
    return;
  }
  ll mid=(st+en)>>1;
  update(node<<1,st,mid,l,r,v); update(node<<1|1,mid+1,en,l,r,v);
  tree[node]=tree[node<<1]|tree[node<<1|1];
}
ll query(ll node,ll st,ll en,ll l,ll r)
{
  ulazy(node,st,en);
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return query(node<<1,st,mid,l,r)|query(node<<1|1,mid+1,en,l,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,t,q;
  cin>>n>>t>>q;
  init(1,1,n);
  while(q--)
  {
    char ch;
    ll a,b,c=0;
    cin>>ch>>a>>b;
    if(a>b) swap(a,b);
    if(ch=='C') cin>>c;
    if(ch=='C') update(1,1,n,a,b,(1LL<<c));
    else cout<<__popcount(query(1,1,n,a,b))<<endl;
  }
  return 0;
}