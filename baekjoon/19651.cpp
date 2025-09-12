#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct Node
{
  ll x1,l1,x2,l2;
  ll a,l;
};
ll arr[100005],brr[100005],lazy[400005];
Node tree[400005];
Node f(Node a,Node b)
{
  if(!a.l) return b;
  if(!b.l) return a;
  Node ret;
  ret.x1=a.x1; ret.x2=b.x2;
  ret.l1=(a.l1==a.l && a.x1==b.x1)?(a.l+b.l1):a.l1;
  ret.l2=(b.l2==b.l && a.x2==b.x2)?(a.l2+b.l):b.l2;
  ret.a=max(a.a,b.a);
  if(a.x2==b.x1) ret.a=max(ret.a,a.l2+b.l1);
  ret.l=a.l+b.l;
  return ret;
}
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={brr[st],1,brr[st],1,1,1};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void ulazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  tree[node].x1+=lazy[node]; tree[node].x2+=lazy[node];
  if(st!=en)
  {
    lazy[node<<1]+=lazy[node];
    lazy[node<<1|1]+=lazy[node];
  }
  lazy[node]=0;
}
void update(ll node,ll st,ll en,ll l,ll r,ll v)
{
  ulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node].x1+=v; tree[node].x2+=v;
    if(st!=en)
    {
      lazy[node<<1]+=v;
      lazy[node<<1|1]+=v;
    }
    return;
  }
  ll mid=(st+en)>>1;
  update(node<<1,st,mid,l,r,v); update(node<<1|1,mid+1,en,l,r,v);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  ulazy(node,st,en);
  if(r<st || en<l) return {0,0,0,0,0,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<n; i++) brr[i]=arr[i+1]-arr[i];
  init(1,1,n-1);
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b,c,d=1,e=1;
    cin>>a>>b>>c;
    if(a==1) cin>>d>>e;
    if(a==1)
    {
      if(b>1) update(1,1,n-1,b-1,b-1,d);
      if(b<c) update(1,1,n-1,b,c-1,e);
      if(c<n) update(1,1,n-1,c,c,-d-e*(c-b));
    }
    else cout<<query(1,1,n-1,b,c-1).a+1<<endl;
  }
  return 0;
}