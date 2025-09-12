#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll arr[100005],tree1[400005],lazy[400005];
ll brr[100005],tree2[400005];
ll f(ll a,ll b)
{
  if(a<0 || b<0) return f(llabs(a),llabs(b));
  if(!b) return a;
  return f(b,a%b);
}
ll init1(ll node,ll st,ll en)
{
  if(st==en) return tree1[node]=arr[st];
  ll mid=(st+en)>>1;
  return tree1[node]=init1(node<<1,st,mid)+init1(node<<1|1,mid+1,en);
}
ll init2(ll node,ll st,ll en)
{
  if(st==en) return tree2[node]=brr[st];
  ll mid=(st+en)>>1;
  return tree2[node]=f(init2(node<<1,st,mid),init2(node<<1|1,mid+1,en));
}
void ulazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  tree1[node]+=(en-st+1)*lazy[node];
  if(st!=en)
  {
    lazy[node<<1]+=lazy[node];
    lazy[node<<1|1]+=lazy[node];
  }
  lazy[node]=0;
}
void update1(ll node,ll st,ll en,ll l,ll r,ll v)
{
  ulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree1[node]+=(en-st+1)*v;
    if(st!=en)
    {
      lazy[node<<1]+=v;
      lazy[node<<1|1]+=v;
    }
    return;
  }
  ll mid=(st+en)>>1;
  update1(node<<1,st,mid,l,r,v); update1(node<<1|1,mid+1,en,l,r,v);
  tree1[node]=tree1[node<<1]+tree1[node<<1|1];
}
void update2(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree2[node]+=v;
    return;
  }
  ll mid=(st+en)>>1;
  update2(node<<1,st,mid,idx,v); update2(node<<1|1,mid+1,en,idx,v);
  tree2[node]=f(tree2[node<<1],tree2[node<<1|1]);
}
ll query1(ll node,ll st,ll en,ll l,ll r)
{
  ulazy(node,st,en);
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree1[node];
  ll mid=(st+en)>>1;
  return query1(node<<1,st,mid,l,r)+query1(node<<1|1,mid+1,en,l,r);
}
ll query2(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree2[node];
  ll mid=(st+en)>>1;
  return f(query2(node<<1,st,mid,l,r),query2(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=1; i<n; i++) brr[i]=arr[i]-arr[i-1];
  init1(1,0,n-1); init2(1,1,n-1);
  cin>>q;
  while(q--)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    if(!a)
    {
      ll temp=query1(1,0,n-1,b-1,b-1);
      if(b<c) temp=f(temp,query2(1,1,n-1,b,c-1));
      cout<<temp<<endl;
    }
    else
    {
      update1(1,0,n-1,b-1,c-1,a);
      if(b>1) update2(1,1,n-1,b-1,a);
      if(c<n) update2(1,1,n-1,c,-a);
    }
  }
  return 0;
}