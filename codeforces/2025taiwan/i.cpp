#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct Node
{
  ll mval,ans,cnt1;
};
Node tree[800005];
ll arr[200005],lazy[800005],temp[200005];
inline Node f(Node a,Node b)
{
  return {min(a.mval,b.mval),a.ans+b.ans,a.cnt1+b.cnt1};
}
Node init(ll node,ll st,ll en)
{
  if(st==en)
  {
    if(arr[st]==1) return tree[node]={(ll)1e9,0,1};
    return tree[node]={arr[st],0,0};
  }
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void ulazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  
  lazy[node]=0;
}
void upd(ll node,ll st,ll en,ll l,ll r,ll v,bool flag)
{
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    if(flag) tree[node].ans+=tree[node].cnt1;
    if(tree[node].mval>v)
    {
      if(tree[node].mval<(ll)1e9)
      {
        tree[node].mval-=v;
        lazy[node]+=v;
      }
      return;
    }
    if(st==en)
    {
      if(lazy[node])
    }
  }
  ulazy(node,st,en);
  ll mid=(st+en)>>1;
  upd(node<<1,st,mid,l,r,v); upd(node<<1|1,mid+1,en,l,r,v);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  ulazy(node,st,en);
  if(r<st || en<l) return {(ll)1e9,0,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n>>q;
  for(int i=1; i<=n; i++) cin>>arr[i];
  init(1,1,n);
  while(q--)
  {
    ll a,b,c,d;
    cin>>a>>b>>c;
    if(a==1) cin>>d;
    if(a==1) upd(1,1,n,b,c,d,true);
    else cout<<query(1,1,n,b,c).ans<<endl;
  }
  return 0;
}