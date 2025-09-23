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
struct Node
{
  ll mml,sl,sr,ss,sa;
};
inline Node f(Node a,Node b)
{
  return {max(a.mml,a.ss+b.mml),min(a.sl,a.ss+b.sl),min(b.sr,a.sr+b.ss),a.ss+b.ss,min({a.sa,b.sa,a.sr+b.sl})};
}
ll arr[300005];
Node tree[1200005];
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={(arr[st]>0?arr[st]:0),arr[st],arr[st],arr[st],arr[st]};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void upd(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]={(v>0?v:0),v,v,v,v};
    return;
  }
  ll mid=(st+en)>>1;
  upd(node<<1,st,mid,idx,v); upd(node<<1|1,mid+1,en,idx,v);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {-INF,INF,INF,0,INF};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n>>q;
  for(int i=0; i<n; i++) cin>>arr[i];
  init(1,0,n-1);
  while(q--)
  {
    ll a,b,c,d;
    cin>>a>>b>>c;
    if(a==1)
    {
      cin>>d;
      Node t1=query(1,0,n-1,0,b-2);
      ll h=(ll)ceil((double)d/10.0);
      if(b>1 && t1.sa<=-d)
      {
        cout<<0<<endl;
        continue;
      }
      ll th=min(d,d+t1.sr);
      Node t2=f({0,th-d,th-d,th-d,th-d},query(1,0,n-1,b-1,c-1));
      if(t2.sa<=h-d) th=h;
      else th=d+t2.sr;
      th=min(d,th);
      if(c==n)
      {
        cout<<th<<endl;
        continue;
      }
      Node t3=f({0,th-d,th-d,th-d,th-d},query(1,0,n-1,c,n-1));
      if(t3.sa<=-d) th=0;
      else th=d+t3.sr;
      th=min(d,th);
      cout<<th<<endl;
    }
    else upd(1,0,n-1,b-1,c);
  }
  return 0;
}