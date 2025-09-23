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
const ll INF=(ll)1e18;
struct Node
{
  ll sl,sr,ss,sa;
};
ll arr[200005],brr[200005];
vector<Node> tree1(800005),tree2(800005);
inline Node f(Node a,Node b)
{
  return {max(a.sl,a.ss+b.sl),max(b.sr,b.ss+a.sr),a.ss+b.ss,max({a.sa,b.sa,a.sr+b.sl})};
}
void upd1(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    arr[st]+=v;
    tree1[node]={arr[st],arr[st],arr[st],arr[st]};
    return;
  }
  ll mid=(st+en)>>1;
  upd1(node<<1,st,mid,idx,v); upd1(node<<1|1,mid+1,en,idx,v);
  tree1[node]=f(tree1[node<<1],tree1[node<<1|1]);
}
void upd2(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    brr[st]+=v;
    tree2[node]={brr[st],brr[st],brr[st],brr[st]};
    return;
  }
  ll mid=(st+en)>>1;
  upd2(node<<1,st,mid,idx,v); upd2(node<<1|1,mid+1,en,idx,v);
  tree2[node]=f(tree2[node<<1],tree2[node<<1|1]);
}
Node query1(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {-INF,-INF,0,-INF};
  if(l<=st && en<=r) return tree1[node];
  ll mid=(st+en)>>1;
  return f(query1(node<<1,st,mid,l,r),query1(node<<1|1,mid+1,en,l,r));
}
Node query2(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {-INF,-INF,0,-INF};
  if(l<=st && en<=r) return tree2[node];
  ll mid=(st+en)>>1;
  return f(query2(node<<1,st,mid,l,r),query2(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n>>q;
  ll sum=0;
  while(q--)
  {
    ll a,b,c;
    cin>>a;
    if(a==1)
    {
      cin>>b>>c;
      sum+=c;
      upd1(1,1,n,b,c);
      upd2(1,1,n,b,-c);
    }
    else
    {
      Node t1=query1(1,1,n,1,n),t2=query2(1,1,n,1,n);
      ll ans=max(t1.sa,sum+t2.sa);
      if(t1.sa<=0) ans=t1.sa;
      cout<<ans<<endl;
    }
  }
  return 0;
}