#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N=1<<21;
const pii zero={0,100000};
pii tree[N<<1],lazy[N<<1];
pii f(pii a,pii b)
{
  if(a.S<b.F) return {b.F,b.F};
  if(b.S<a.F) return {b.S,b.S};
  return {max(a.F,b.F),min(a.S,b.S)};
}
void update_lazy(int node,int st,int en)
{
  if(lazy[node]==zero) return;
  tree[node]=f(tree[node],lazy[node]);
  if(st!=en)
  {
    lazy[node<<1]=f(lazy[node<<1],lazy[node]);
    lazy[node<<1|1]=f(lazy[node<<1|1],lazy[node]);
  }
  lazy[node]=zero;
}
void update_range(int node,int st,int en,int l,int r,pii v)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node]=f(tree[node],v);
    if(st!=en)
    {
      lazy[node<<1]=f(lazy[node<<1],v);
      lazy[node<<1|1]=f(lazy[node<<1|1],v);
    }
    return;
  }
  int mid=(st+en)>>1;
  update_range(node<<1,st,mid,l,r,v); update_range(node<<1|1,mid+1,en,l,r,v);
  tree[node]={min(tree[node<<1].F,tree[node<<1|1].F),max(tree[node<<1].S,tree[node<<1|1].S)};
}
pii query(int node,int st,int en,int l,int r)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return zero;
  if(l<=st && en<=r) return tree[node];
  int mid=(st+en)>>1;
  pii t1=query(node<<1,st,mid,l,r),t2=query(node<<1|1,mid+1,en,l,r);
  return {max(t1.F,t2.F),min(t1.S,t2.S)};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n,q;
  cin>>n>>q;
  while(q--)
  {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==1) update_range(1,0,n-1,b,c,{d,100000});
    else update_range(1,0,n-1,b,c,{0,d});
  }
  for(int i=0; i<n; i++) cout<<query(1,0,n-1,i,i).F<<endl;
  return 0;
}